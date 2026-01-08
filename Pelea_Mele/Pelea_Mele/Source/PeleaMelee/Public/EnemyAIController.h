// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

struct FAIStimulus;
class UAISenseConfig_Hearing;
class UAISenseConfig_Sight;


UCLASS()
class PELEAMELEE_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemyAIController();

protected:
	virtual void OnPossess(APawn* InPawn) override;

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
};
