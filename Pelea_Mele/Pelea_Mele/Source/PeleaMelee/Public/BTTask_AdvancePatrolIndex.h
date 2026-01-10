// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_AdvancePatrolIndex.generated.h"

/**
 * 
 */
UCLASS()
class PELEAMELEE_API UBTTask_AdvancePatrolIndex : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AdvancePatrolIndex();

protected:
	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector PatrolRouteKey;

	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector PatrolIndexKey;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
