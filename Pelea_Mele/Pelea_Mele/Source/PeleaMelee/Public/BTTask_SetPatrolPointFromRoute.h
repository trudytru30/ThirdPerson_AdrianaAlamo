// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_SetPatrolPointFromRoute.generated.h"

/**
 * 
 */
UCLASS()
class PELEAMELEE_API UBTTask_SetPatrolPointFromRoute : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_SetPatrolPointFromRoute();

protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector PatrolRouteKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector PatrolIndexKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector PatrolPointKey;

	virtual EBTNodeResult:: Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
