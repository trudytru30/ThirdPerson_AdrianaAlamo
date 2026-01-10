// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolRoute.h"

#include "Engine/TargetPoint.h"


// Sets default values
APatrolRoute::APatrolRoute()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
}

int32 APatrolRoute::NumPoints() const
{
	int32 Count = 0;
	for (ATargetPoint* P : Points)
	{
		if (IsValid(P))
		{
			++Count;
		}
	}
	return Count;
}

ATargetPoint* APatrolRoute::GetPoint(int32 Index) const
{
	//Creamos la ruta desde los puntos, eliminando si existe un posible null
	TArray<ATargetPoint*> ValidPoints;
	for (ATargetPoint* P : Points)
	{
		if (IsValid(P))
		{
			ValidPoints.Add(P);
		}
	}
	if (ValidPoints.Num() ==0)
	{
		return nullptr;
	}

	if (bLoop)
	{
		Index = (Index % ValidPoints.Num()+ValidPoints.Num()) % ValidPoints.Num();;
	}
	else
	{
		Index = FMath::Clamp(Index, 0, ValidPoints.Num()-1);
	}

	return ValidPoints.IsValidIndex(Index) ? ValidPoints[Index] : nullptr;
}

int32 APatrolRoute::GetNearestIndex(const FVector& WorldLocation) const
{
	TArray<ATargetPoint*> ValidPoints;

	for (ATargetPoint* P : Points)
	{
		if (IsValid(P))
		{
			ValidPoints.Add(P);
		}
	}

	if (ValidPoints.Num() ==0)
	{
		return -1;
	}

	int32 BestIndex = 0;
	float BestDistance = FLT_MAX;

	for (int32 Index = 0; Index < ValidPoints.Num(); ++Index)
	{
		const float DistSq = FVector::Dist(WorldLocation, ValidPoints[Index]->GetActorLocation());
		if (DistSq < BestDistance)
		{
			BestDistance = DistSq;
			BestIndex = Index;
		}
	}
	return BestIndex;
}
#if WITH_EDITOR
void APatrolRoute::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	TArray<FVector> ValidLocs;
	for (ATargetPoint* P : Points)
	{
		if (IsValid(P))
		{
			ValidLocs.Add(P->GetActorLocation());
		}
	}

	for (int32 Index = 0; Index < ValidLocs.Num(); ++Index)
	{
		DrawDebugSphere(World, ValidLocs[Index], 25, 12, FColor::Cyan, false,0.f,0,2.f);

		const int32 Next = Index+1;
		if (ValidLocs.IsValidIndex(Next))
		{
			DrawDebugLine(World,ValidLocs[Index],ValidLocs[Next],FColor::Magenta,false,0.f,0,2.f);
		}
		else if (bLoop && ValidLocs.Num() > 1)
		{
			DrawDebugLine(World, ValidLocs[Index], ValidLocs[0], FColor::Purple, false, 0.f, 0, 2.f);
		}
	}

	
}
#endif




