// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

class APatrolRoute;
class UBoxComponent;
class UHealthComponent;

UCLASS()
class PELEAMELEE_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:

	AEnemy();
	virtual void Tick(float DeltaTime) override;

	void SetbDead(bool Dead){bDead = Dead;};

	UFUNCTION(BlueprintCallable, Category="Death")
	void KillByAssassination();

	APatrolRoute* GetPatrolRoute() const {return PatrolRoute;};


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

	//---------AI---------
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="AI")
	APatrolRoute* PatrolRoute = nullptr;
	

	//---------State---------

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="State")
	bool bDead = false;
	
	//---------Death FX---------
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DeathFX")
	UAnimMontage* DeathMontage = nullptr;

	// Si no hay montage, destruimos al enemigo con un timer
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Death")
	float DestroyDelayIfNoMontage = 0.1f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DeathFX")
	USoundBase* DeathSound = nullptr;
	
	//---------Overlaps---------

	UFUNCTION()
	void OnKillZoneBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                            int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnKillZoneEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	
private:
	void HandleDeath();
	
	UFUNCTION()
	void HandleDeathFromHealth();

	UPROPERTY()
	UAnimMontage* PendingDeathMontage = nullptr;
		
	void OnDeathMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted); 
	void OnDeathMontageEnded(UAnimMontage* Montage,bool bInterrupted);
	

	void FreezeMeshPose();
	
	bool bDeathHandled = false;
	FTimerHandle DestroyTimerHandle;
	
	
};
