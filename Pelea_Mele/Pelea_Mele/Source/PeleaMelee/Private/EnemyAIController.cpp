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
static const FName BB_AwarenessStateKey(TEXT("AwarenessState"));



// Sets default values
AEnemyAIController::AEnemyAIController()
{
	PrimaryActorTick.bCanEverTick = true;
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

	// Inicializar estado
	Suspicion = 0.f;
	LastSeenTime = -FLT_MAX;
	LastHeardTime = -FLT_MAX;
	CurrentTarget = nullptr;
	LastKnownLocation = FVector::ZeroVector;
	LastHeardLocation = FVector::ZeroVector;
	bHasLOS = false;
	bPerceptionBlocked = false;

	BB->SetValueAsBool(BB_HasLineOfSightKey, false);
	BB->SetValueAsEnum(BB_AwarenessStateKey, (uint8)EAwarenessState::Doubt);

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

void AEnemyAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	UpdateAwareness(DeltaSeconds);
}

void AEnemyAIController::SetPerceptionBlocked(bool bBlocked, float Duration)
{
	bPerceptionBlocked = bBlocked;

	if (!PerceptionComp)
	{
		return;
	}

	if (bBlocked)
	{
		PerceptionComp->SetComponentTickEnabled(false);
	}

	//Cancelar el timer anterior por si se relanza la bomba
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(PerceptionRestoreHandle);

		if (Duration > 0.f)
		{
			//[this]() para saber a que objeto hace referencia la funcion
			World->GetTimerManager().SetTimer(PerceptionRestoreHandle, [this](){SetPerceptionBlocked(false, 0.f);}, Duration, false);
		}
	}
	else
	{
		//Rehabilitar perception
		PerceptionComp->SetComponentTickEnabled(true);
		bPerceptionBlocked = false;

		//Limpiar LOS
		bHasLOS = false;
		if (UBlackboardComponent* BB = GetBlackboardComponent())
		{
			BB->SetValueAsBool(BB_HasLineOfSightKey, false);
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

	const float Now = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.f;
	
	const FAISenseID SightID   = SightConfig   ? SightConfig->GetSenseID()   : FAISenseID::InvalidID();
	const FAISenseID HearingID = HearingConfig ? HearingConfig->GetSenseID() : FAISenseID::InvalidID();

	// Si el estímulo es de vista
	if (Stimulus.Type == SightID)
	{
		ANinja* Ninja = Cast<ANinja>(Actor);
		if (!Ninja)
		{
			return;
		}
		
		const bool bSensed = Stimulus.WasSuccessfullySensed();
		bHasLOS = bSensed;
		
		BB->SetValueAsBool(BB_HasLineOfSightKey, bSensed);

	

		if (bSensed)
		{
			CurrentTarget = Ninja;
			LastKnownLocation = Ninja->GetActorLocation();
			LastSeenTime = Now;
			BB->SetValueAsVector(BB_LastKnownLocationKey,LastKnownLocation);

			Suspicion = FMath::Clamp(Suspicion + 15.f, 0.f, SuspicionMax);
			
		}
		else
		{
			LastKnownLocation = Stimulus.StimulusLocation;
			BB->SetValueAsVector(BB_LastKnownLocationKey, LastKnownLocation);
			BB->SetValueAsBool(BB_PatrolNeedsResyncKey, true);
		}
		return;
	}

	// Si el estímulo es de oído
	if (Stimulus.Type == HearingID)
	{
		if (Stimulus.WasSuccessfullySensed())
		{
			CurrentTarget = Actor; 
			LastHeardTime = Now;

			LastHeardLocation = Stimulus.StimulusLocation;
			BB->SetValueAsVector(BB_LastHeardLocationKey, LastHeardLocation);

			// Normalmente el sonido actualiza dónde buscar
			LastKnownLocation = LastHeardLocation;
			BB->SetValueAsVector(BB_LastKnownLocationKey, LastKnownLocation);

			const APawn* P = GetPawn();
			Suspicion = FMath::Clamp(Suspicion + ComputeHearingGain(Stimulus, P), 0.f, SuspicionMax);
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
	SightConfig->PeripheralVisionAngleDegrees = 120.0f;
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

void AEnemyAIController::UpdateAwareness(float DeltaSeconds)
{
	UBlackboardComponent* BB = GetBlackboardComponent();
	if (!BB)
	{
		return;
	}

	const float Now = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.f;

	if (bPerceptionBlocked)
	{
		Suspicion = FMath::Clamp(Suspicion - SuspicionDecayPerSec * DeltaSeconds, 0.f, SuspicionMax);
		WriteBlackboard(EAwarenessState::Doubt);
		return;
	}

	// Subida/bajada principal de sospecha
	if (bHasLOS && CurrentTarget.IsValid())
	{
		Suspicion = FMath::Clamp(Suspicion + SightGainPerSec * DeltaSeconds, 0.f, SuspicionMax);
	}
	else
	{
		Suspicion = FMath::Clamp(Suspicion - SuspicionDecayPerSec * DeltaSeconds, 0.f, SuspicionMax);
	}
	
	const bool bHoldAlertByLostSight = (Now - LastSeenTime) <= AlertHoldAfterLostSightSec;
	const bool bHoldAlertByHeard     = (Now - LastHeardTime) <= AlertHoldAfterHeardSec;

	EAwarenessState NewState = EAwarenessState::Doubt;

	// Detected: solo con visión 
	if (bHasLOS && CurrentTarget.IsValid() && Suspicion >= DetectedThreshold)
	{
		NewState = EAwarenessState::Detected;
	}
	else if (Suspicion >= AlertThreshold || bHoldAlertByLostSight || bHoldAlertByHeard)
	{
		NewState = EAwarenessState::Alert;
	}
	else
	{
		NewState = EAwarenessState::Doubt;
	}

	WriteBlackboard(NewState);
}

void AEnemyAIController::WriteBlackboard(EAwarenessState NewState)
{
	UBlackboardComponent* BB = GetBlackboardComponent();
	if (!BB)
	{
		return;
	}

	BB->SetValueAsEnum(BB_AwarenessStateKey, (uint8)NewState);

	// Target / LastKnown
	if (NewState == EAwarenessState::Doubt && Suspicion <= KINDA_SMALL_NUMBER)
	{
		// Si ya no hay “sospecha”, limpiamos target (opcional)
		BB->ClearValue(BB_TargetActorKey);
	}
	else
	{
		if (CurrentTarget.IsValid())
		{
			BB->SetValueAsObject(BB_TargetActorKey, CurrentTarget.Get());
		}
	}

	BB->SetValueAsVector(BB_LastKnownLocationKey, LastKnownLocation);

	if (NewState != CurrentAwarenessState)
	{
		CurrentAwarenessState = NewState;
		OnAwarenessStateChanged.Broadcast(NewState);
	}
	
}

float AEnemyAIController::ComputeHearingGain(const FAIStimulus& Stimulus, const APawn* ControlledPawn) const
{
	// Ganancia base modulada por distancia (más cerca = más)
	float Gain = HearingGainBase;

	if (ControlledPawn)
	{
		const float Dist = FVector::Dist(ControlledPawn->GetActorLocation(), Stimulus.StimulusLocation);
		const float Range = HearingConfig ? HearingConfig->HearingRange : 2000.f;

		const float T = (Range > 1.f) ? FMath::Clamp(Dist / Range, 0.f, 1.f) : 1.f;
		const float DistanceFactor = 1.f - T; // 1 cerca, 0 lejos

		Gain *= (0.35f + 0.65f * DistanceFactor); // nunca 0
	}
	Gain *= FMath::Clamp(Stimulus.Strength, 0.25f, 1.0f);

	return Gain;
}



