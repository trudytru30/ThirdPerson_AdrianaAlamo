// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_MeleeAttack.generated.h"

/**
 * 
 */
UCLASS()
class PELEAMELEE_API UBTTask_MeleeAttack : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_MeleeAttack();

protected:
	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector IsAttackingKey;

	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector TargetActorKey;

	// IMPORTANT: Este key lo actualiza tu BTService_UpdateAttackRange
	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector InAttackRangeKey;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTNodeResult::Type TaskResult) override;

private:
	UPROPERTY()
	UBehaviorTreeComponent* CachedOwnerComp = nullptr;

	UPROPERTY()
	UAnimInstance* CachedAnimInstance = nullptr;

	UPROPERTY()
	UAnimMontage* CachedMontage = nullptr;

	FOnMontageBlendingOutStarted MontageBlendOutDelegate;
	FOnMontageEnded MontageEndDelegate;

	bool bFinishing = false;

	void OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted);
	void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	void ClearMontageDelegates();
	void CleanupState();
	bool ShouldRepeatAttack() const;
	bool PlayAttackMontage();

	void FinishAttackTask(bool bInterrupted);
};
