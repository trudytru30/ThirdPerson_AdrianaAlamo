// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolRoute.generated.h"

class ATargetPoint;

UCLASS()
class PELEAMELEE_API APatrolRoute : public AActor
{
	GENERATED_BODY()

public:
	
	APatrolRoute();

	UFUNCTION(BlueprintCallable, Category = "Patrol")
	int32 NumPoints() const;

	UFUNCTION(BlueprintCallable, Category = "Patrol")
	ATargetPoint* GetPoint(int32 Index) const;

    //Retorna el indice del punto de la ruta más cercano. Si no existe devuelve -1	
	UFUNCTION(BLueprintPure, Category = "Patrol")
	int32 GetNearestIndex(const FVector& WorldLocation) const;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Patrol")
	bool bLoop = true;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Patrol")
	TArray<ATargetPoint*> Points;

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Components")
	USceneComponent* Root;

#if WITH_EDITOR
	virtual void OnConstruction(const FTransform& Transform) override;
#endif
	
};
