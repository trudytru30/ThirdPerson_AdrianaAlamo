// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_AdvancePatrolIndex.h"
#include "PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_AdvancePatrolIndex::UBTTask_AdvancePatrolIndex()
{
	NodeName = TEXT("Advance Patrol Index");

	PatrolRouteKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_AdvancePatrolIndex, PatrolRouteKey), APatrolRoute::StaticClass());
	PatrolIndexKey.AddIntFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_AdvancePatrolIndex, PatrolIndexKey));
}


EBTNodeResult::Type UBTTask_AdvancePatrolIndex::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent();
	if (!BB)
	{
		return EBTNodeResult::Failed;
	}
	
	APatrolRoute* Route = Cast<APatrolRoute>(BB->GetValueAsObject(PatrolRouteKey.SelectedKeyName));
	if (!Route)
	{
		return EBTNodeResult::Failed;
	}

	const int32 Count = Route->NumPoints();

	if (Count <= 0)
	{
		return EBTNodeResult::Failed;
	}

	int32 Index = BB->GetValueAsInt(PatrolIndexKey.SelectedKeyName);
	Index ++;

	if (Route->bLoop)
	{
		Index = (Index % Count + Count) % Count;
	}
	else
	{
		Index = FMath::Clamp(Index, 0, Count - 1);
	}

	BB->SetValueAsInt(PatrolIndexKey.SelectedKeyName, Index);
	return EBTNodeResult::Succeeded;
}
