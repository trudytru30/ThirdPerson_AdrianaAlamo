#include "Ninja.h"

#include "PeleaMeleeGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/Image.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
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
#include "UObject/UnrealType.h"

ANinja::ANinja()
{
	PrimaryActorTick.bCanEverTick = true;
	PawnNoiseEmitter = CreateDefaultSubobject<UPawnNoiseEmitterComponent>(TEXT("PawnNoiseEmitter"));
	MotionWarping = CreateDefaultSubobject<UMotionWarpingComponent>(TEXT("MotionWarping"));
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

		if (HUDWidgetClass)
		{
			IHUD = CreateWidget<UUserWidget>(PC, HUDWidgetClass);
			if (IHUD)
			{
				IHUD->AddToViewport(HUDZOrder);
			}
		}
	}

	// Recuperar valores del GameInstance
	if (UPeleaMeleeGameInstance* GI = Cast<UPeleaMeleeGameInstance>(GetGameInstance()))
	{
		ShurikensCount = GI->ShurikensCount;
		BombCount = GI->BombCount;
	}
}

void ANinja::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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
	Health -= HealthToLoss;

	if (Health <= 0.0f)
	{
		Death();
	}
}

// ---------------- Game Over ----------------

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

	if (DeathSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
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
	AddControllerYawInput(LookAxis.X);
	AddControllerPitchInput(LookAxis.Y);
}

// ---------------- Movement Input (Move) ----------------

void ANinja::OnNinjaMoveTriggered(const FInputActionValue& Value)
{
	const FVector2D MoveAxis = Value.Get<FVector2D>();

	const FRotator ControlRot = Controller ? Controller->GetControlRotation() : GetActorRotation();
	const FRotator YawRot(0.0f, ControlRot.Yaw, 0.0f);

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
		Move->bOrientRotationToMovement = false;
		Move->bUseControllerDesiredRotation = true;
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

	// Ninja montage (Play Montage en Mesh)
	if (AssassinMontage && GetMesh() && GetMesh()->GetAnimInstance())
	{
		GetMesh()->GetAnimInstance()->Montage_Play(AssassinMontage, 1.0f);
	}

	// Victim montage (Play Anim Montage en Victim si es Character)
	if (VictimAssassinatedMontage)
	{
		if (ACharacter* VictimChar = Cast<ACharacter>(Victim))
		{
			VictimChar->PlayAnimMontage(VictimAssassinatedMontage, 1.0f);
		}
	}

	// Victim.Dead = true (por reflexión)
	{
		static const FName DeadPropName(TEXT("Dead"));
		if (FBoolProperty* DeadProp = FindFProperty<FBoolProperty>(Victim->GetClass(), DeadPropName))
		{
			DeadProp->SetPropertyValue_InContainer(Victim, true);
		}
	}

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

	// Capsule -> NoCollision
	if (UCapsuleComponent* Capsule = GetCapsuleComponent())
	{
		Capsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	// BP: Set Victim (vacío) + Set Sneaking? false
	Victim = nullptr;
	bSneaking = false;
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

	BombCount -= 1;
	if (BombCount < 0)
	{
		BombCount = 0;
	}
}

// ---------------- Shuriken Attack ----------------

void ANinja::OnNinjaFireTriggered(const FInputActionValue& Value)
{
	if (ShurikensCount <= 0)
	{
		return;
	}

	EnsureCrossHairReference();
	SetCrossHairVisible(true);
	UpdateTargetEnemyFromTrace();
}

void ANinja::OnNinjaFireCompleted(const FInputActionValue& Value)
{
	if (ShurikensCount <= 0)
	{
		return;
	}

	EnsureCrossHairReference();
	SetCrossHairVisible(false);

	ShurikensCount = FMath::Max(0, ShurikensCount - 1);

	ApplyShurikenDamageToTarget();
}

void ANinja::EnsureCrossHairReference()
{
	if (CrossHair)
	{
		return;
	}

	if (IHUD)
	{
		if (UWidget* Found = IHUD->GetWidgetFromName(TEXT("CrossHair")))
		{
			CrossHair = Cast<UImage>(Found);
		}
	}
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

void ANinja::UpdateTargetEnemyFromTrace()
{
	//TODO Revisar este codigo
	UCameraComponent* CameraComp = Camera ? Camera : FindComponentByClass<UCameraComponent>();
	if (!CameraComp || !GetWorld())
	{
		TargetEnemy = nullptr;
		SetCrossHairTint(CrossHairColorBase);
		return;
	}

	const FVector Start = CameraComp->GetComponentLocation();
	const FVector End = GetActorLocation() + (CameraComp->GetForwardVector() * ShurikenTraceDistance);

	FHitResult Hit;
	FCollisionQueryParams Params(SCENE_QUERY_STAT(NinjaShurikenTrace), false);
	Params.AddIgnoredActor(this);

	const bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params);
	AActor* HitActor = bHit ? Hit.GetActor() : nullptr;

	// Aproximación al "Cast To BP_Enemy": considerar enemigo si tiene float "Health"
	static const FName HealthPropName(TEXT("Health"));

	if (HitActor && FindFProperty<FFloatProperty>(HitActor->GetClass(), HealthPropName))
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

void ANinja::ApplyShurikenDamageToTarget()
{
	if (!IsValid(TargetEnemy))
	{
		return;
	}

	static const FName HealthPropName(TEXT("Health"));

	if (FFloatProperty* HealthProp = FindFProperty<FFloatProperty>(TargetEnemy->GetClass(), HealthPropName))
	{
		const float CurrentHealth = HealthProp->GetPropertyValue_InContainer(TargetEnemy);
		HealthProp->SetPropertyValue_InContainer(TargetEnemy, CurrentHealth - ShurikenDamage);
	}
}
