// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_UpdateAttackRange.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_UpdateAttackRange::UBTService_UpdateAttackRange()
{
	NodeName = TEXT("Update Attack Range");
	bNotifyBecomeRelevant = true;
	bNotifyTick = true;
	Interval = 0.1f; // 10 veces por segundo, suficiente

	TargetActorKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTService_UpdateAttackRange, TargetActorKey), AActor::StaticClass());
	InAttackRangeKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(UBTService_UpdateAttackRange, InAttackRangeKey));
}

void UBTService_UpdateAttackRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	
	UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent();
	AAIController* AIC = OwnerComp.GetAIOwner();
	APawn* Pawn = AIC ? AIC->GetPawn() : nullptr;

	if (!BB || !Pawn)
	{
		return;
	}

	AActor* Target = Cast<AActor>(BB->GetValueAsObject(TargetActorKey.SelectedKeyName));
	if (!Target)
	{
		BB->SetValueAsBool(InAttackRangeKey.SelectedKeyName, false);
		return;
	}

	const float Dist2D= FVector::Dist2D(Target->GetActorLocation(), Pawn->GetActorLocation());

	bool bInRange = Dist2D<= AttackRange ? true : false;

	
	BB->SetValueAsBool(InAttackRangeKey.SelectedKeyName,bInRange);
}
