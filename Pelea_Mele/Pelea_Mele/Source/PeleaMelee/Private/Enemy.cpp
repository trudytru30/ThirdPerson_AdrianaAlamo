// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "AIController.h"
#include "HealthComponent.h"
#include "Ninja.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/BoxComponent.h"

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
	
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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