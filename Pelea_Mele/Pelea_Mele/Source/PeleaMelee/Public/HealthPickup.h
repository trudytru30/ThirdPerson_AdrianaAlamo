// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthPickup.generated.h"

class UHealthComponent;
class UTextRenderComponent;
class USphereComponent;

UCLASS()
class PELEAMELEE_API AHealthPickup : public AActor
{
	GENERATED_BODY()

public:
	AHealthPickup();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USceneComponent* Root = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USphereComponent* Collision = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* Mesh = nullptr;
	

	// Positivo = cura, negativo = veneno/daño
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Potion")
	float HealthDelta = 25.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Potion")
	USoundBase* PickupSound = nullptr;
	// Si no cambia la vida, no se consume
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Potion")
	bool bConsumeOnlyIfApplied = true;


private:
	UFUNCTION()
	void OnCollisionBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);


	void Consume(UHealthComponent* HC);
	bool bConsumed = false;
};
