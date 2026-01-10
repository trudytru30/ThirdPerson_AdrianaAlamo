// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_PatrolIndexSynced.h"

#include "AIController.h"
#include "PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_PatrolIndexSynced::UBTTask_PatrolIndexSynced()
{
	NodeName = TEXT("PatrolIndexSynced");

	PatrolRouteKey.AddObjectFilter(this,GET_MEMBER_NAME_CHECKED(UBTTask_PatrolIndexSynced,PatrolRouteKey),APatrolRoute::StaticClass());
	PatrolIndexKey.AddIntFilter(this,GET_MEMBER_NAME_CHECKED(UBTTask_PatrolIndexSynced,PatrolIndexKey));
	PatrolNeedsResyncKey.AddBoolFilter(this,GET_MEMBER_NAME_CHECKED(UBTTask_PatrolIndexSynced,PatrolNeedsResyncKey));
}

EBTNodeResult::Type UBTTask_PatrolIndexSynced::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent();
	AAIController* AIC = OwnerComp.GetAIOwner();
	APawn* Pawn = AIC ? AIC->GetPawn() : nullptr;

	if (!BB || !Pawn)
	{
		return EBTNodeResult::Failed;
	}

	//No necesita recalcular y la patrol sigue su curso normal
	const bool bNeedsResync = BB->GetValueAsBool(PatrolNeedsResyncKey.SelectedKeyName);
	if (!bNeedsResync)
	{
		return EBTNodeResult::Succeeded;
	}

	APatrolRoute* Route = Cast<APatrolRoute>(BB->GetValueAsObject(PatrolRouteKey.SelectedKeyName));
	if (!Route)
	{
		return EBTNodeResult::Failed;
	}

	const int32 NearestIdx = Route->GetNearestIndex((Pawn->GetActorLocation()));

	if (NearestIdx >= 0)
	{
		BB->SetValueAsInt(PatrolIndexKey.SelectedKeyName,NearestIdx);
	}

	//Marcamos que no necesita recalcular para no sobrecargar el tick
	BB->SetValueAsBool(PatrolNeedsResyncKey.SelectedKeyName,false);

	return EBTNodeResult::Succeeded;
}
