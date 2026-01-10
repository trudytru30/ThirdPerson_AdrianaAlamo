// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_PatrolIndexSynced.generated.h"

/**
 * 
 */
UCLASS()
class PELEAMELEE_API UBTTask_PatrolIndexSynced : public UBTTaskNode
{
	GENERATED_BODY()

	UBTTask_PatrolIndexSynced();

protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector PatrolRouteKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector PatrolIndexKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector PatrolNeedsResyncKey;

	virtual EBTNodeResult:: Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
