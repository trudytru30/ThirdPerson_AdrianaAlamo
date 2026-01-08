// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangedSignature,float,CurrentHealth,float,MaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FonDeathSignature);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PELEAMELEE_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthComponent();


	UFUNCTION(BlueprintCallable, Category="Health")
	float ApplyDelta(float Delta);
	
	UFUNCTION(BlueprintCallable, Category="Health")
	float GetCurrentHealt() {return CurrentHealth;}

	UFUNCTION(BlueprintCallable, Category="Health")
	float GetMaxHealt() {return MaxHealth;}

	UFUNCTION(BlueprintCallable, Category="Health")
	bool IsDead() {return CurrentHealth<=0.0f;}

	UFUNCTION(BlueprintCallable, Category="Health")
	bool IsInvulnerable() {return bHitReactActive;}

	UPROPERTY(BlueprintAssignable, Category="Health")
	FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="Health")
	FonDeathSignature OnDeath;

	
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Health")
	float MaxHealth = 100;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Health")
	float CurrentHealth = 100;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category="Health")
	UAnimMontage* HitReactMontage;


private:
	void BroadcastHealth();
	void TryPlayHitReact();

	void OnHitReactBlendingOut(UAnimMontage* Montage, bool bInterrupted);
	void OnHitReactEnded(UAnimMontage* Montage, bool bInterrupted);
	
	bool bHitReactActive = false;

	UPROPERTY()
	UAnimMontage* PendingHitReactMontage = nullptr;
	

	
	
};
