// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AnimNotifyMeleeInterface.h"
#include "Components/SphereComponent.h"
#include "Enemy.generated.h"

class APatrolRoute;
class UBoxComponent;
class UHealthComponent;


UCLASS()
class PELEAMELEE_API AEnemy : public ACharacter, public IAnimNotifyMeleeInterface
{
	GENERATED_BODY()

public:

	AEnemy();
	virtual void Tick(float DeltaTime) override;

	void SetbDead(bool Dead){bDead = Dead;};

	UFUNCTION(BlueprintCallable, Category="Death")
	void KillByAssassination();
	
	UFUNCTION()
	UAnimMontage* GetAttackMontage(){return AttackMontage;}

	APatrolRoute* GetPatrolRoute() const {return PatrolRoute;};

	//---------State---------

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="State")
	bool bDead = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="State")
	bool bDoubt = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="State")
	bool bAlert = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="State")
	bool bDetected = false;

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
		
	//---------Death FX---------
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DeathFX")
	UAnimMontage* DeathMontage = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DeathFX")
	USoundBase* DeathSound = nullptr;

	// Si no hay montage, destruimos al enemigo con un timer
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Death")
	float DestroyDelayIfNoMontage = 0.1f;
	
	//---------Attack---------
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attack")
	UAnimMontage* AttackMontage = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat|Melee")
	float MeleeDamage = 25.0f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat|Melee")
	USphereComponent* MeleeHitbox = nullptr;

	// socket del mesh donde se engancha la esfera 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat|Melee")
	FName MeleeHitboxAttachBone = TEXT("hand_r");

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat|Melee")
	float MeleeHitboxRadius = 15.0f;

	void TryApplyMeleeHit(AActor* OtherActor);
	
	//---------Overlaps---------
	UFUNCTION()
	void OnKillZoneBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                            int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnKillZoneEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void OnMeleeHitboxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
								   int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


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

	// Estado ventana de golpe
	bool bMeleeWindowActive = false;
	bool bHitAppliedThisWindow = false;
	
	//Implementacion de la Interface
	virtual void SetMeleeWindowActive_Implementation(bool bActive) override;
	
};
