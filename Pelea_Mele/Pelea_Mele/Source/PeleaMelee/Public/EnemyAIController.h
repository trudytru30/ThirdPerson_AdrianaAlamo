// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

struct FAIStimulus;

class UBehaviorTree;
class UAIPerceptionComponent;
class UAISenseConfig_Hearing;
class UAISenseConfig_Sight;

UENUM(BlueprintType)
enum class EAwarenessState : uint8
{
	Doubt    UMETA(DisplayName="Doubt"),
	Alert    UMETA(DisplayName="Alert"),
	Detected UMETA(DisplayName="Detected"),
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAwarenessStateChanged, EAwarenessState, NewState);


UCLASS()
class PELEAMELEE_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyAIController();

	// Getter para BP
	UFUNCTION(BlueprintPure, Category="AI|Awareness")
	EAwarenessState GetAwarenessState() const { return CurrentAwarenessState; }

	// Evento para BP (opcional, evita hacer Tick en BP)
	UPROPERTY(BlueprintAssignable, Category="AI|Awareness")
	FAwarenessStateChanged OnAwarenessStateChanged;

	void SetPerceptionBlocked(bool bBlocked, float Duration);
	
protected:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "AI")
	UBehaviorTree* BehaviorTree = nullptr;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "AI|Perception")
	UAIPerceptionComponent* PerceptionComp = nullptr;

	UPROPERTY()
	UAISenseConfig_Sight* SightConfig = nullptr;
	UPROPERTY()
	UAISenseConfig_Hearing* HearingConfig = nullptr;

	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	void SetupPerceptionComponent();

private:
	
	UPROPERTY(EditDefaultsOnly, Category="AI|Awareness")
	float SuspicionMax = 100.f;

	UPROPERTY(EditDefaultsOnly, Category="AI|Awareness")
	float AlertThreshold = 35.f;

	UPROPERTY(EditDefaultsOnly, Category="AI|Awareness")
	float DetectedThreshold = 80.f;

	UPROPERTY(EditDefaultsOnly, Category="AI|Awareness")
	float SuspicionDecayPerSec = 12.f;

	UPROPERTY(EditDefaultsOnly, Category="AI|Awareness")
	float SightGainPerSec = 45.f;

	UPROPERTY(EditDefaultsOnly, Category="AI|Awareness")
	float HearingGainBase = 25.f;

	// Mantener ALERT un rato tras perder visión / tras oír
	UPROPERTY(EditDefaultsOnly, Category="AI|Awareness")
	float AlertHoldAfterLostSightSec = 2.0f;

	UPROPERTY(EditDefaultsOnly, Category="AI|Awareness")
	float AlertHoldAfterHeardSec = 2.5f;

	
	float Suspicion = 0.f;
	float LastSeenTime = -FLT_MAX;
	float LastHeardTime = -FLT_MAX;

	TWeakObjectPtr<AActor> CurrentTarget;
	FVector LastKnownLocation = FVector::ZeroVector;
	FVector LastHeardLocation = FVector::ZeroVector;

	bool bHasLOS = false;

	bool bPerceptionBlocked = false;
	FTimerHandle PerceptionRestoreHandle;

	void UpdateAwareness(float DeltaSeconds);
	void WriteBlackboard(EAwarenessState NewState);

	float ComputeHearingGain(const FAIStimulus& Stimulus, const APawn* ControlledPawn) const;

	UPROPERTY()
	EAwarenessState CurrentAwarenessState = EAwarenessState::Doubt;
};
