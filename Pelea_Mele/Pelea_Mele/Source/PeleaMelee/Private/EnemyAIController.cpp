// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Sight.h"


static const FName BB_TargetActorKey(TEXT("TargetActor"));
static const FName BB_LastHeardLocationKey(TEXT("LastHeardLocation"));
static const FName BB_HasLineOfSightKey(TEXT("HasLineOfSight"));


// Sets default values
AEnemyAIController::AEnemyAIController()
{
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
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

		if (bSensed)
		{
			BB->SetValueAsObject(BB_TargetActorKey, Actor);
		}
		else
		{
			// Si pierde visión, no siempre conviene borrar el TargetActor (depende de tu BT)
			// Por ahora lo dejamos, y tu BT decide si persigue/olvida.
		}
		return;
	}

	// Si el estímulo es de oído
	if (Stimulus.Type == HearingID)
	{
		if (Stimulus.WasSuccessfullySensed())
		{
			BB->SetValueAsVector(BB_LastHeardLocationKey, Stimulus.StimulusLocation);

			// Si no tengo target, puedo “adquirir” al actor que generó ruido
			if (!BB->GetValueAsObject(BB_TargetActorKey))
			{
				BB->SetValueAsObject(BB_TargetActorKey, Actor);
			}
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
	// De momento lo dejamos amplio para que vea al player sin configurar equipos.
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



