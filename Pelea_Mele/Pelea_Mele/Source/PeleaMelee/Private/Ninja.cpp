#include "Ninja.h"

#include "Enemy.h"
#include "EnemyAIController.h"
#include "PeleaMeleeGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/Image.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "HealthComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "Kismet/GameplayStatics.h"
#include "MotionWarpingComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "Components/PawnNoiseEmitterComponent.h"
#include "Sound/SoundBase.h"
#include "TimerManager.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "UObject/UnrealType.h"

ANinja::ANinja()
{
	PrimaryActorTick.bCanEverTick = true;
	
	HealthComp =CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComp"));
	PawnNoiseEmitter = CreateDefaultSubobject<UPawnNoiseEmitterComponent>(TEXT("PawnNoiseEmitter"));
	MotionWarping = CreateDefaultSubobject<UMotionWarpingComponent>(TEXT("MotionWarping"));
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->bUsePawnControlRotation = true;      // el brazo sigue al ratón (controller)
	SpringArm->bDoCollisionTest = true;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm,USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false; 

	// El personaje NO debe rotar con el ratón
	bUseControllerRotationYaw   = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll  = false;

	if (UCharacterMovementComponent* Move = GetCharacterMovement())
	{
		Move->bOrientRotationToMovement = true;       // rota hacia WASD
		Move->bUseControllerDesiredRotation = false;  // no seguir al controller
		Move->RotationRate = FRotator(0.f, 540.f, 0.f);
	}
	
	GetMesh()->SetupAttachment(GetCapsuleComponent());
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	
}

void ANinja::BeginPlay()
{
	Super::BeginPlay();

	// Add Mapping Context + Create HUD
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (ULocalPlayer* LP = PC->GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				if (NinjaMappingContext)
				{
					Subsystem->AddMappingContext(NinjaMappingContext, NinjaMappingPriority);
				}
			}
		}

		//Establece la rotacion standar al incio (no apuntado)
		PC->bShowMouseCursor = false;
		FInputModeGameOnly InitialInputMode;
		PC->SetInputMode(InitialInputMode);

		if (HUDWidgetClass)
		{
			IHUD = CreateWidget<UUserWidget>(PC, HUDWidgetClass);
			if (IHUD)
			{
				IHUD->AddToViewport(HUDZOrder);
			}
		}

		if (IHUD)
		{
			if (UWidget* Found = IHUD->GetWidgetFromName(TEXT("CrossHair")))
			{
				CrossHair = Cast<UImage>(Found);
				SetCrossHairVisible(false);

				if (UCanvasPanelSlot* Slot = Cast<UCanvasPanelSlot>(CrossHair->Slot))
				{
					Slot->SetAnchors(FAnchors(0.f,0.f,0.f,0.f));
					Slot->SetAlignment(FVector2D(0.5f,0.5f));
				}
			}
		}
	}

	AimOffsetUMG = FVector2D::ZeroVector;
	SetAiming(false);
	
	// Recuperar valores del GameInstance
	if (UPeleaMeleeGameInstance* GI = Cast<UPeleaMeleeGameInstance>(GetGameInstance()))
	{
		ShurikensCount = GI->ShurikensCount;
		BombCount = GI->BombCount;
	}

	if (UAnimInstance* Anim = GetMesh() ? GetMesh()->GetAnimInstance() : nullptr)
	{
		Anim->SetRootMotionMode(ERootMotionMode::RootMotionFromMontagesOnly);
	}

	if (HealthComp)
	{
		HealthComp->OnDeath.AddDynamic(this, &ANinja::OnNinjaDied);
	}
}


void ANinja::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsAiming)
	{
		UpdateAimOffsetFromMouse();
		UpdateAimFromCrosshair(DeltaTime);
	}
}

void ANinja::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Fire
		if (NinjaFireAction)
		{
			EIC->BindAction(NinjaFireAction, ETriggerEvent::Triggered, this, &ANinja::OnNinjaFireTriggered);
			EIC->BindAction(NinjaFireAction, ETriggerEvent::Completed, this, &ANinja::OnNinjaFireCompleted);
		}

		// Look
		if (NinjaLookAction)
		{
			EIC->BindAction(NinjaLookAction, ETriggerEvent::Triggered, this, &ANinja::OnNinjaLookTriggered);
		}

		// Move
		if (NinjaMoveAction)
		{
			EIC->BindAction(NinjaMoveAction, ETriggerEvent::Triggered, this, &ANinja::OnNinjaMoveTriggered);
		}

		// Sneak
		if (NinjaSneakAction)
		{
			EIC->BindAction(NinjaSneakAction, ETriggerEvent::Triggered, this, &ANinja::OnNinjaSneakTriggered);
			EIC->BindAction(NinjaSneakAction, ETriggerEvent::Completed, this, &ANinja::OnNinjaSneakCompleted);
		}

		// Attack (Started)
		if (NinjaAttackAction)
		{
			EIC->BindAction(NinjaAttackAction, ETriggerEvent::Started, this, &ANinja::OnNinjaAttackStarted);
		}
	}
}

void ANinja::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Guardar en GameInstance
	if (UPeleaMeleeGameInstance* GI = Cast<UPeleaMeleeGameInstance>(GetGameInstance()))
	{
		GI->ShurikensCount = ShurikensCount;
		GI->BombCount = BombCount;
	}

	Super::EndPlay(EndPlayReason);
}

void ANinja::LossHealth(float HealthToLoss)
{
	if (bDeathTriggered)
	{
		return;
	}
	
	if (!HealthComp)
	{
		return;
	}

	HealthComp->ApplyDelta(-HealthToLoss);

	if (SoundOnDamageRecived)
	{
		UGameplayStatics::PlaySoundAtLocation(this, SoundOnDamageRecived, GetActorLocation());
	}
}

// ---------------- Game Over ----------------

void ANinja::OnNinjaDied()
{
	
	Death(); // tu lógica de game over
}

void ANinja::Death()
{
	if (bDeathTriggered)
	{
		return;
	}
	bDeathTriggered = true;

	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);

	if (PC && GameOverMenuWidgetClass)
	{
		GameOverMenuWidget = CreateWidget<UUserWidget>(PC, GameOverMenuWidgetClass);
		if (GameOverMenuWidget)
		{
			GameOverMenuWidget->AddToViewport(0);

			FInputModeUIOnly InputMode;
			InputMode.SetWidgetToFocus(GameOverMenuWidget->TakeWidget());
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PC->SetInputMode(InputMode);
		}
	}

	if (SoundOnDeath)
	{
		UGameplayStatics::PlaySoundAtLocation(this, SoundOnDeath, GetActorLocation());
	}

	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(
			GameOverDelayHandle,
			this,
			&ANinja::ApplyGameOverPause,
			GameOverDelaySeconds,
			false
		);
	}
	else
	{
		ApplyGameOverPause();
	}
}

void ANinja::ApplyGameOverPause()
{
	UGameplayStatics::SetGamePaused(this, true);

	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		PC->bShowMouseCursor = true;
	}
}

// ---------------- Camera Input (Look) ----------------

void ANinja::OnNinjaLookTriggered(const FInputActionValue& Value)
{
	const FVector2D LookAxis = Value.Get<FVector2D>();
	if (bIsAiming)
	{

		return;
	}
	
	AddControllerYawInput(LookAxis.X);
	AddControllerPitchInput(LookAxis.Y);
}

// ---------------- Movement Input (Move) ----------------

void ANinja::OnNinjaMoveTriggered(const FInputActionValue& Value)
{
	const FVector2D MoveAxis = Value.Get<FVector2D>();

	FRotator YawRot;

	if (bIsAiming)
	{
		// En aim: movimiento relativo al personaje (strafe real)
		YawRot = FRotator(0.0f, GetActorRotation().Yaw, 0.0f);
	}
	else
	{
		// Normal: movimiento relativo a la cámara (controller yaw)
		const FRotator ControlRot = Controller ? Controller->GetControlRotation() : GetActorRotation();
		YawRot = FRotator(0.0f, ControlRot.Yaw, 0.0f);
	}

	const FVector ForwardDir = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
	const FVector RightDir   = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);

	AddMovementInput(RightDir, MoveAxis.X);
	AddMovementInput(ForwardDir, MoveAxis.Y);

	// Ruido si NO está sneaking
	if (!bSneaking && PawnNoiseEmitter)
	{
		const float AbsSum = FMath::Abs(MoveAxis.X) + FMath::Abs(MoveAxis.Y);
		if (AbsSum > KINDA_SMALL_NUMBER)
		{
			PawnNoiseEmitter->MakeNoise(this, MoveNoiseLoudness, GetActorLocation());
		}
	}
}

// ---------------- Sneak ----------------

void ANinja::OnNinjaSneakTriggered(const FInputActionValue& Value)
{
	bSneaking = true;

	if (UCharacterMovementComponent* Move = GetCharacterMovement())
	{
		Move->bOrientRotationToMovement = true;
		Move->bUseControllerDesiredRotation = false;
	}
}

void ANinja::OnNinjaSneakCompleted(const FInputActionValue& Value)
{
	bSneaking = false;

	if (UCharacterMovementComponent* Move = GetCharacterMovement())
	{
		Move->bOrientRotationToMovement = true;
		Move->bUseControllerDesiredRotation = false;
	}
}

// ---------------- Attack Basic ----------------

void ANinja::OnNinjaAttackStarted(const FInputActionValue& Value)
{
	if (bCanAttack)
	{
		DoAssassinationAttack();
	}
	
	else
	{
		LanzarHumo();
	}
}

void ANinja::DoAssassinationAttack()
{
	if (!IsValid(Victim))
	{
		return;
	}

	AEnemy* Enemy = Cast<AEnemy>(Victim);

	//Solo se puede hacer assasiantion a enemigos
	if (!Enemy)
	{
		Victim = nullptr;
		bSneaking = false;
		return;
	}

	AssassinationVictim = Victim;
	
	// Motion Warping: AddOrUpdate target "Victim" desde VictimTarget (SceneComponent) si existe
	if (MotionWarping)
	{
		FTransform VictimTransform;
		bool bHasTransform = false;
		TryGetVictimTargetTransform(VictimTransform, bHasTransform);

		if (bHasTransform)
		{
			MotionWarping->AddOrUpdateWarpTargetFromTransform(VictimWarpTargetName, VictimTransform);
		}
	}

	// Ignore victim collision
	if (UCapsuleComponent* Capsule = GetCapsuleComponent())
	{
		Capsule->IgnoreActorWhenMoving(AssassinationVictim,true);
	}

	// Ninja montage (Play Montage en Mesh)
	if (AssassinMontage && GetMesh() && GetMesh()->GetAnimInstance())
	{
		if (UAnimInstance* Anim = GetMesh()->GetAnimInstance())
		{
			Anim->SetRootMotionMode(ERootMotionMode::RootMotionFromMontagesOnly);

			FOnMontageEnded EndDelegate;
			EndDelegate.BindUObject(this, &ANinja::OnAssassinationMontageEnded);
			Anim->Montage_SetEndDelegate(EndDelegate, AssassinMontage);
		}

		PlayAnimMontage(AssassinMontage, 1.0f);
	}

	if (SoundOnAssassination)
	{
		UGameplayStatics::PlaySoundAtLocation(this, SoundOnAssassination, GetActorLocation());
	}
	
	Enemy->KillByAssassination();
	
	// BP: Set Victim (vacío) + Set Sneaking? false
	Victim = nullptr;
	bSneaking = false;
}

void ANinja::OnAssassinationMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (UCapsuleComponent* Capsule = GetCapsuleComponent())
	{
		Capsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

		if (IsValid(AssassinationVictim))
		{
			Capsule->IgnoreActorWhenMoving(AssassinationVictim, false);
		}
	}
	
	if (UCharacterMovementComponent* Move = GetCharacterMovement())
	{
		if (Move->MovementMode == MOVE_None)
		{
			Move->SetMovementMode(MOVE_Walking);
		}
	}

	AssassinationVictim = nullptr;
}

void ANinja::TryGetVictimTargetTransform(FTransform& OutTransform, bool& bOutHasTransform) const
{
	bOutHasTransform = false;

	if (!IsValid(Victim))
	{
		return;
	}

	// Buscar propiedad "VictimTarget" que sea un SceneComponent
	static const FName VictimTargetPropName(TEXT("VictimTarget"));

	if (FObjectProperty* ObjProp = FindFProperty<FObjectProperty>(Victim->GetClass(), VictimTargetPropName))
	{
		UObject* ObjValue = ObjProp->GetObjectPropertyValue_InContainer(Victim);
		if (USceneComponent* SceneComp = Cast<USceneComponent>(ObjValue))
		{
			OutTransform = SceneComp->GetComponentTransform();
			bOutHasTransform = true;
		}
	}
}

// ---------------- Smoke Bomb ----------------

void ANinja::LanzarHumo()
{
	if (BombCount <= 0)
	{
		return;
	}

	if (SmokeSystem && GetWorld())
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			GetWorld(),
			SmokeSystem,
			GetActorLocation(),
			FRotator::ZeroRotator,
			SmokeSystemScale,
			true,
			true,
			ENCPoolMethod::None,
			true
		);
	}

	if (SoundOnSmokeBomb)
	{
		UGameplayStatics::PlaySoundAtLocation(this, SoundOnSmokeBomb, GetActorLocation());
	}
	BombCount -= 1;
	UE_LOG(LogTemp, Warning, TEXT("BombCount: %d"), BombCount);
	if (BombCount < 0)
	{
		BombCount = 0;
	}

	//Recoger enemigoa en radio
	TArray<AActor*> OverlappingActors;
	UKismetSystemLibrary::SphereOverlapActors
	(
		GetWorld(), GetActorLocation(), SmokeBombRadius,
		TArray<TEnumAsByte<EObjectTypeQuery>>{ UEngineTypes::ConvertToObjectType(ECC_Pawn) },	AEnemy::StaticClass(),
		TArray<AActor*>{ this },OverlappingActors
	);

	for (AActor* Actor : OverlappingActors)
	{
		AEnemy* Enemy = Cast<AEnemy>(Actor);
		if (!IsValid(Enemy))
		{
			continue;
		}

		if (AEnemyAIController* AIC = Cast<AEnemyAIController>(Enemy->GetController()))
		{
			AIC->SetPerceptionBlocked(true, SmokeBombDuration);
		}
	}

	bThrowBomb = true;
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(
			SmokeBombThrowResetHandle,
			[this]() { bThrowBomb = false; },
			SmokeBombDuration,
			false
		);
	}
}



// ---------------- Shuriken Attack ----------------

void ANinja::SetAiming(bool bNewAiming)
{
	bIsAiming = bNewAiming;
	if (UCharacterMovementComponent* Move = GetCharacterMovement())
	{
		if (bIsAiming)
		{
			//Desactivamos la rotacion en funcion del movimiento
			Move->bOrientRotationToMovement = false;
			bUseControllerRotationYaw = false;
			AimOffsetUMG = FVector2D::ZeroVector;
		}
		else
		{
			Move->bOrientRotationToMovement = true;
			AimOffsetUMG = FVector2D::ZeroVector;

			if (APlayerController* PC = Cast<APlayerController>(GetController()))
			{
				PC->bShowMouseCursor = false;
				FInputModeGameOnly NormalMode;
				PC->SetInputMode(NormalMode);
			}
		}
	}
	
}

void ANinja::UpdateAimFromCrosshair(float DeltaTime)
{
	if (!CrossHair)
	{
		return;
	}
	
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (!PC)
	{
		return;
	}

	FVector2D ScreenPx;
	if (!GetCrosshairScreenPointPx(ScreenPx))
	{
		return;
	}
	//Posicionamos el Slot que contiene el Crosshair
	if (UCanvasPanelSlot* Slot = Cast<UCanvasPanelSlot>(CrossHair->Slot))
	{
		const float Scale = UWidgetLayoutLibrary::GetViewportScale(this);
		const FVector2D PosUMG = ScreenPx /Scale;

		Slot->SetAnchors(FAnchors(0.f,0.f,0.f,0.f));
		Slot->SetAlignment(FVector2D(0.5f, 0.5f));
		Slot->SetPosition(PosUMG);
	}

	//Deprojectamos desde el crosshair, para obtener la posición en el mundo 3D
	FVector WorldOrigin, WorldDirection;
	if (!PC->DeprojectScreenPositionToWorld(ScreenPx.X,ScreenPx.Y, WorldOrigin, WorldDirection))
	{
		TargetEnemy = nullptr;
		SetCrossHairTint(CrossHairColorBase);
		return;
	}

	//Realizamos un linetrace para orientar al player y detectar si tenemos un enemigo bajo el crosshair
	const FVector Start = WorldOrigin;
	const FVector End = Start + (WorldDirection*ShurikenTraceDistance);

	FHitResult Hit;
	FCollisionQueryParams Params(TEXT("NinjaAimTrace"),false);
	Params.AddIgnoredActor(this);

	const bool bHit = GetWorld()->LineTraceSingleByChannel(Hit,Start,End,ECC_Visibility,Params);

	AActor* HitActor = bHit ? Hit.GetActor() : nullptr;
	const FVector AimPoint = bHit ? Hit.ImpactPoint : End;

	//Orientamos al player hacia el crosshair
	FVector ToAim = AimPoint - GetActorLocation();
	ToAim.Z = 0.0f;

	if (ToAim.SizeSquared() > 1.0f)
	{
		const float TargetYaw = ToAim.Rotation().Yaw;
		const FRotator CurrentRot = GetActorRotation();
		const FRotator TargetRot (0.f,TargetYaw,0.f);

		const FRotator NewRot = FMath::RInterpTo(CurrentRot,TargetRot,DeltaTime,AimTurnSpeed);
		SetActorRotation(NewRot);
	}

	//Detectamos si la colision es con un enemigo y tintamos el punto de mira
	if (HitActor && HitActor!=this && HitActor->FindComponentByClass<UHealthComponent>())
	{
		TargetEnemy = HitActor;
		SetCrossHairTint(CrossHairColorOverEnemy);
	}
	else
	{
		TargetEnemy = nullptr;
		SetCrossHairTint(CrossHairColorBase);
	}
}

void ANinja::UpdateAimOffsetFromMouse()
{
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (!PC)
	{
		return;
	}
	float MouseX = 0.f, MouseY = 0.f;
	if (!UWidgetLayoutLibrary::GetMousePositionScaledByDPI(PC,MouseX,MouseY))
	{
		return;
	}
	int32 SizeX=0, SizeY=0;
	PC->GetViewportSize(SizeX,SizeY);

	const float Scale = UWidgetLayoutLibrary::GetViewportScale(this);
	const FVector2D ViewSizeUMG = FVector2D((float)SizeX, (float)SizeY)/Scale;
	const FVector2D CenterUMG = ViewSizeUMG * 0.5f;

	const FVector2D MouseUMG(MouseX,MouseY);
	AimOffsetUMG = MouseUMG - CenterUMG;
}

bool ANinja::GetCrosshairScreenPointPx(FVector2D& OutPx) 
{
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (!PC)
	{
		return false;
	}

	int32 SizeX=0,SizeY=0;
	PC->GetViewportSize(SizeX,SizeY);

	const float Scale = UWidgetLayoutLibrary::GetViewportScale(this);
	if (Scale<=0)
	{
		return false;
	}

	//TODO Revisar Casteos a C++
	const FVector2D ViewSizeUMG = FVector2D((float)SizeX, (float)SizeY)/Scale;
	const FVector2D CenterUMG = ViewSizeUMG * 0.5f;

	//Clampeo a limites de pantalla
	const FVector2D Half = CrossHairSizeUMG * 0.5f;

	FVector2D DesireUMG = CenterUMG + AimOffsetUMG;
	DesireUMG.X = FMath::Clamp(DesireUMG.X, Half.X, ViewSizeUMG.X -Half.X);
	DesireUMG.Y  = FMath::Clamp(DesireUMG.Y,Half.Y, ViewSizeUMG.Y -Half.Y);

	AimOffsetUMG = DesireUMG -CenterUMG;
	OutPx = DesireUMG * Scale;
	return true;
}

void ANinja::OnNinjaFireTriggered(const FInputActionValue& Value)
{
	if (ShurikensCount <= 0)
	{
		return;
	}
	//Activar un puntero invisible para ubicar nuestro crosshair
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		PC->bShowMouseCursor = true;
		FInputModeGameOnly AimMode;
		PC->SetInputMode(AimMode);
	}
	
	SetAiming(true);
	SetCrossHairVisible(true);
}

void ANinja::OnNinjaFireCompleted(const FInputActionValue& Value)
{
	SetCrossHairVisible(false);
	SetAiming(false);
	
	if (ShurikensCount <= 0)
	{
		return;
	}
	ShurikensCount = FMath::Max(0, ShurikensCount - 1);

	if (SoundOnShurikenThrow)
	{
		UGameplayStatics::PlaySoundAtLocation(this, SoundOnShurikenThrow, GetActorLocation());
	}
	ApplyShurikenDamageToTarget();
}

void ANinja::SetCrossHairVisible(bool bVisible)
{
	if (!CrossHair)
	{
		return;
	}

	CrossHair->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
}

void ANinja::SetCrossHairTint(const FLinearColor& Tint)
{
	if (!CrossHair)
	{
		return;
	}

	// Equivalente práctico al nodo "Set Brush Tint Color"
	CrossHair->SetColorAndOpacity(Tint);
}


void ANinja::ApplyShurikenDamageToTarget()
{
	if (!IsValid(TargetEnemy))
	{
		return;
	}

	if (UHealthComponent* TargetHealth = TargetEnemy->FindComponentByClass<UHealthComponent>())
	{
		TargetHealth->ApplyDelta(-ShurikenDamage);
	}
}
