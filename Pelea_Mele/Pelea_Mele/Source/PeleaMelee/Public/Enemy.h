// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

class UBoxComponent;
class UHealthComponent;

UCLASS()
class PELEAMELEE_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:

	AEnemy();
	virtual void Tick(float DeltaTime) override;

protected:
	
	virtual void BeginPlay() override;

	//---------Components---------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    UHealthComponent* HealthComp = nullptr;

	//Zona donde el player puede ejecutar el asesinato
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MotionWarping")
	UBoxComponent* KillZone = nullptr;

	//Punto para usar con el motionwarping
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MotionWarping")
	USceneComponent* VictimTarget = nullptr;

	//---------State---------

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="State")
	bool bDead = false;

	//---------Overlaps---------

	UFUNCTION()
	void OnKillZoneBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                            int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnKillZoneEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	
};
