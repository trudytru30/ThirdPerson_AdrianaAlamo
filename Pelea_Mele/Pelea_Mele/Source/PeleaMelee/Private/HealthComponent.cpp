// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


float UHealthComponent::ApplyDelta(float Delta)
{
	if (Delta == 0.0f)
	{
		return CurrentHealth;
	}

	const float OldHealth = CurrentHealth;
	CurrentHealth  = FMath::Clamp(CurrentHealth+Delta,0.0f,MaxHealth);
	if (!FMath::IsNearlyEqual(OldHealth,CurrentHealth))
	{
		OnHealthChanged.Broadcast(CurrentHealth,MaxHealth);
	}
	return CurrentHealth;
}


