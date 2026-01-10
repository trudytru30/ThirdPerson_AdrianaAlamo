// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_SetPatrolPointFromRoute.h"

#include "PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Engine/TargetPoint.h"

UBTTask_SetPatrolPointFromRoute::UBTTask_SetPatrolPointFromRoute()
{
	NodeName = TEXT("Set Patrol Point From Route");

	PatrolRouteKey.AddObjectFilter(this,GET_MEMBER_NAME_CHECKED(UBTTask_SetPatrolPointFromRoute,PatrolRouteKey),APatrolRoute::StaticClass());
	PatrolIndexKey.AddIntFilter(this,GET_MEMBER_NAME_CHECKED(UBTTask_SetPatrolPointFromRoute,PatrolIndexKey));
	PatrolPointKey.AddVectorFilter(this,GET_MEMBER_NAME_CHECKED(UBTTask_SetPatrolPointFromRoute,PatrolPointKey));
}

EBTNodeResult::Type UBTTask_SetPatrolPointFromRoute::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent();
	if (!BB)
	{
		return EBTNodeResult::Failed;
	}

	APatrolRoute* Route = Cast<APatrolRoute>(BB->GetValueAsObject((PatrolRouteKey.SelectedKeyName)));

	if (!Route)
	{
		return EBTNodeResult::Failed;
	}

	const int32 Index = BB->GetValueAsInt(PatrolIndexKey.SelectedKeyName);
	ATargetPoint* TP = Route->GetPoint(Index);
	if (!TP)
	{
		return EBTNodeResult::Failed;
	}
	FVector TP_Position = TP->GetActorLocation();
	BB->SetValueAsVector(PatrolPointKey.SelectedKeyName,TP_Position);

	return EBTNodeResult::Succeeded;
}
