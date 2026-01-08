// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "AIController.h"
#include "BrainComponent.h"
#include "HealthComponent.h"
#include "Ninja.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"


static const FName BB_UnderAttackKey(TEXT("UnderAttack"));

AEnemy::AEnemy()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComp"));

	//Punto para el MotionWarping
	VictimTarget = CreateDefaultSubobject<USceneComponent>(TEXT("VictimTarget"));
	VictimTarget->SetupAttachment(GetRootComponent());

	//Zona de Asesinato
	KillZone = CreateDefaultSubobject<UBoxComponent>(TEXT("KillZone"));
	KillZone->SetupAttachment(GetRootComponent());
	KillZone->SetBoxExtent(FVector(80.f,80.f,80.f));

	KillZone->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	KillZone->SetCollisionObjectType(ECC_WorldDynamic);
	KillZone->SetCollisionResponseToAllChannels(ECR_Ignore);
	KillZone->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
	KillZone->SetGenerateOverlapEvents(true);
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	if (KillZone)
	{
		KillZone->OnComponentBeginOverlap.AddDynamic(this,&AEnemy::OnKillZoneBeginOverlap);
		KillZone->OnComponentEndOverlap.AddDynamic(this,&AEnemy::OnKillZoneEndOverlap);
	}
	
	if (HealthComp)
	{
		HealthComp->OnDeath.AddDynamic(this, &AEnemy::HandleDeathFromHealth);
	}
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AEnemy::KillByAssassination()
{
	if (bDead)
	{
		return;
	}
	bDead = true;
	HandleDeath();
}


void AEnemy::HandleDeathFromHealth()
{
	if (!bDead)
	{
		bDead = true;
	}
	HandleDeath();
}


void AEnemy::HandleDeath()
{
	if (bDeathHandled)
	{
		return;
	}
	bDeathHandled = true;

	//FX Audio
	if (DeathSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this,DeathSound,GetActorLocation());
	}
	
	// Desactivar killzone para que no vuelva a disparar overlaps
	if (KillZone)
	{
		KillZone->SetGenerateOverlapEvents(false);
		KillZone->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
	
	if (UCharacterMovementComponent* Move = GetCharacterMovement())
	{
		Move->StopMovementImmediately();
		Move->DisableMovement();
	}

	// Desactivar colisiones
	SetActorEnableCollision(false);

	// Parar AI + blackboard
	if (AAIController* AIC = Cast<AAIController>(GetController()))
	{
		AIC->StopMovement();

		if (UBlackboardComponent* BB = AIC->GetBlackboardComponent())
		{
			BB->SetValueAsBool(BB_UnderAttackKey, false);
		}

		if (UBrainComponent* Brain = AIC->GetBrainComponent())
		{
			Brain->StopLogic(TEXT("Dead"));
		}
	}

	if (DeathMontage && GetMesh())
	{
		if (UAnimInstance* Anim = GetMesh()->GetAnimInstance())
		{
			PlayAnimMontage(DeathMontage,0.5);

			FOnMontageBlendingOutStarted BlendDelegate;
			BlendDelegate.BindUObject(this, &AEnemy::OnDeathMontageBlendingOut);
			Anim->Montage_SetBlendingOutDelegate(BlendDelegate, DeathMontage);
			
			PendingDeathMontage = DeathMontage;
			FOnMontageEnded EndDelegate;
			EndDelegate.BindUObject(this,&AEnemy::OnDeathMontageEnded);
			Anim->Montage_SetEndDelegate(EndDelegate,DeathMontage);
			
			return;
		}
	}

	//Si no tenemos una animacion deleteamos al enemigo con un timer
	if (UWorld* World =  GetWorld())
	{
		World->GetTimerManager().SetTimer(
			DestroyTimerHandle,
			this,
			&AActor::K2_DestroyActor,
			FMath::Max(0.0f,DestroyDelayIfNoMontage),
			false);
	}
	else
	{
		Destroy();
	}

	
}

void AEnemy::OnDeathMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted)
{
	if (Montage && Montage == PendingDeathMontage)
	{
		FreezeMeshPose();        // evita “vuelta a idle”
		PendingDeathMontage = nullptr;
		Destroy();
	}
}

void AEnemy::FreezeMeshPose()
{
	if (USkeletalMeshComponent* Skel = GetMesh())
	{
		Skel->bPauseAnims = true;
		Skel->SetComponentTickEnabled(false); // evita que el AnimBP vuelva a evaluar (idle)
	}
}

void AEnemy::OnDeathMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (Montage && Montage == PendingDeathMontage)
	{
		FreezeMeshPose();  
		PendingDeathMontage = nullptr;
		Destroy();
	}
}


void AEnemy::OnKillZoneBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (bDead)
	{
		return;
	}
	ANinja* Ninja = Cast<ANinja>(OtherActor);
	if (!Ninja)
	{
		return;
	}

	Ninja->Victim = this;
	Ninja->bSneaking = true;
	Ninja->bCanAttack = true;
	Ninja->bAttacking = true;

	if (AAIController* AIC = Cast<AAIController>(GetController()))
	{
		if (UBlackboardComponent* BB = AIC->GetBlackboardComponent())
		{
			BB->SetValueAsBool(BB_UnderAttackKey,true);
		}
	}
}

void AEnemy::OnKillZoneEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (bDead)
	{
		return;
	}
	ANinja* Ninja = Cast<ANinja>(OtherActor);
	if (!Ninja)
	{
		return;
	}

	if (Ninja->Victim == this)
	{
		Ninja->Victim =nullptr;
	}

	Ninja->bSneaking = false;
	Ninja->bCanAttack = false;
	Ninja->bAttacking = false;

	if (AAIController* AIC = Cast<AAIController>(GetController()))
	{
		if (UBlackboardComponent* BB = AIC->GetBlackboardComponent())
		{
			BB->SetValueAsBool(BB_UnderAttackKey,false);
		}
	}
}