// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

#include "PatrolRoute.h"
#include "Enemy.h"
#include "Ninja.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Engine/TargetPoint.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISense_Sight.h"


static const FName BB_TargetActorKey(TEXT("TargetActor"));
static const FName BB_LastHeardLocationKey(TEXT("LastHeardLocation"));
static const FName BB_HasLineOfSightKey(TEXT("HasLineOfSight"));
static const FName BB_LastKnownLocationKey(TEXT("LastKnownLocation"));
static const FName BB_PatrolRouteKey(TEXT("PatrolRoute"));
static const FName BB_PatrolIndexKey(TEXT("PatrolIndex"));
static const FName BB_PatrolPointKey(TEXT("PatrolPoint"));
static const FName BB_PatrolNeedsResyncKey(TEXT("PatrolNeedsResync"));



// Sets default values
AEnemyAIController::AEnemyAIController()
{
	SetupPerceptionComponent();
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
	}
	UBlackboardComponent* BB = GetBlackboardComponent();
	if (!BB)
	{
		return;
	}

	if (AEnemy* Enemy = Cast<AEnemy>(InPawn))
	{
		if (APatrolRoute* Route = Enemy->GetPatrolRoute())
		{
			BB->SetValueAsObject(BB_PatrolRouteKey,Route);

			const int32 NearestIndex = Route->GetNearestIndex(Enemy->GetActorLocation());

			if (NearestIndex >= 0)
			{
				BB->SetValueAsInt(BB_PatrolIndexKey,NearestIndex);

				if (ATargetPoint* TP = Route->GetPoint(NearestIndex))
				{
					BB->SetValueAsVector(BB_PatrolPointKey, TP->GetActorLocation());
				}
			}
		}
	}
}

void AEnemyAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (!Actor)
	{
		return;
	}

	UBlackboardComponent* BB = GetBlackboardComponent();
	if (!BB)
	{
		return;
	}
	const FAISenseID SightID   = SightConfig   ? SightConfig->GetSenseID()   : FAISenseID::InvalidID();
	const FAISenseID HearingID = HearingConfig ? HearingConfig->GetSenseID() : FAISenseID::InvalidID();

	// Si el estímulo es de vista
	if (Stimulus.Type == SightID)
	{
		const bool bSensed = Stimulus.WasSuccessfullySensed();
		BB->SetValueAsBool(BB_HasLineOfSightKey, bSensed);

		ANinja* Ninja = Cast<ANinja>(Actor);
		if (!Ninja)
		{
			return;
		}

		if (bSensed)
		{
			BB->SetValueAsObject(BB_TargetActorKey, Ninja);
			FVector TargetLocation = Ninja->GetTargetLocation();
			BB->SetValueAsVector(BB_LastKnownLocationKey,TargetLocation);
		}
		else
		{
			BB->SetValueAsVector(BB_LastKnownLocationKey,Stimulus.StimulusLocation);
			BB->SetValueAsBool(BB_PatrolNeedsResyncKey,true);
		}
		return;
	}

	// Si el estímulo es de oído
	if (Stimulus.Type == HearingID)
	{
		if (Stimulus.WasSuccessfullySensed())
		{
			ANinja* Ninja = Cast<ANinja>(Actor);
			if (!Ninja)
			{
				return;
			}

			BB->SetValueAsVector(BB_LastHeardLocationKey,Stimulus.StimulusLocation);
		}
	}
}

void AEnemyAIController::SetupPerceptionComponent()
{
	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	SetPerceptionComponent(*PerceptionComp);

	// ---- Sight ----
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->SightRadius = 1500.0f;
	SightConfig->LoseSightRadius = 1800.0f;
	SightConfig->PeripheralVisionAngleDegrees = 70.0f;
	SightConfig->SetMaxAge(2.0f);

	// Detectar “enemigos”/“neutrales”/“amigos”.
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

	// ---- Hearing ----
	HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("HearingConfig"));
	HearingConfig->HearingRange = 2000.0f;
	HearingConfig->SetMaxAge(3.0f);
	HearingConfig->DetectionByAffiliation.bDetectEnemies = true;
	HearingConfig->DetectionByAffiliation.bDetectNeutrals = true;
	HearingConfig->DetectionByAffiliation.bDetectFriendlies = true;

	PerceptionComp->ConfigureSense(*SightConfig);
	PerceptionComp->ConfigureSense(*HearingConfig);
	PerceptionComp->SetDominantSense(UAISense_Sight::StaticClass());

	PerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAIController::OnTargetPerceptionUpdated);

}



