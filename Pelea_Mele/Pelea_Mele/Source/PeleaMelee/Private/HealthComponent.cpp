// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = FMath::Clamp(CurrentHealth, 0.0f, MaxHealth);
	BroadcastHealth();
	
}

float UHealthComponent::ApplyDelta(float Delta)
{
	if (Delta == 0.0f || bHitReactActive)
	{
		return CurrentHealth;
	}

	const float OldHealth = CurrentHealth;
	CurrentHealth  = FMath::Clamp(CurrentHealth+Delta,0.0f,MaxHealth);

	const bool bChanged = !FMath::IsNearlyEqual(CurrentHealth,OldHealth);

	if (bChanged)
	{
		BroadcastHealth();
	}

	//Si el delta es por daño y no por curacion
	const bool bDamageApplied = (Delta < 0.0f) && (CurrentHealth < OldHealth);

	//Si no nos mata aplicamos hitReact
	if (bDamageApplied && CurrentHealth > 0.0f)
	{
		TryPlayHitReact();
	}

	//Si nos mata aplicamos Death
	if (OldHealth > 0.0f &&  CurrentHealth <=0.0f)
	{
		OnDeath.Broadcast();
	}

	return CurrentHealth;
}


void UHealthComponent::BroadcastHealth()
{
	OnHealthChanged.Broadcast(CurrentHealth,MaxHealth);
}

void UHealthComponent::TryPlayHitReact()
{
	if (bHitReactActive)
	{
		return;
	}
	
	USkeletalMeshComponent* Skel = GetOwner()->FindComponentByClass<USkeletalMeshComponent>();
	UAnimInstance* Anim = Skel ? Skel->GetAnimInstance() : nullptr;

	Anim->Montage_Play(HitReactMontage,1);
	bHitReactActive = true;
	PendingHitReactMontage = HitReactMontage;

	FOnMontageBlendingOutStarted BlenDel;
	BlenDel.BindUObject(this,&UHealthComponent::OnHitReactBlendingOut);
	Anim->Montage_SetBlendingOutDelegate(BlenDel,HitReactMontage);

	//Por seguridad enlazo el end de la animacion
	FOnMontageEnded EndDel;
	EndDel.BindUObject(this,&UHealthComponent::OnHitReactEnded);
	Anim->Montage_SetEndDelegate(EndDel,HitReactMontage);


}

void UHealthComponent::OnHitReactBlendingOut(UAnimMontage* Montage, bool bInterrupted)
{
	if (!Montage || Montage != PendingHitReactMontage)
	{
		return;
	}

	bHitReactActive = false;
	PendingHitReactMontage = nullptr;

	
	
}

void UHealthComponent::OnHitReactEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (!Montage || Montage != PendingHitReactMontage)
	{
		return;
	}

	bHitReactActive = false;
	PendingHitReactMontage = nullptr;
}


