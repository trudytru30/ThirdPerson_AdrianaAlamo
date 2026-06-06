// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_UpdateAttackRange.generated.h"

/**
 * 
 */
UCLASS()
class PELEAMELEE_API UBTService_UpdateAttackRange : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService_UpdateAttackRange();
	
protected:
	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector TargetActorKey;

	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector InAttackRangeKey;

	UPROPERTY(EditAnywhere, Category="Attack")
	float AttackRange = 150.0f;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
