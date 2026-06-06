// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MeleeAttack.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Enemy.h"
#include "GameFramework/CharacterMovementComponent.h"

UBTTask_MeleeAttack::UBTTask_MeleeAttack()
{
	NodeName = TEXT("Melee Attack");
	bNotifyTick = false;
	bCreateNodeInstance = true;

	IsAttackingKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_MeleeAttack, IsAttackingKey));
	TargetActorKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_MeleeAttack, TargetActorKey), AActor::StaticClass());
	InAttackRangeKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_MeleeAttack, InAttackRangeKey));
}

EBTNodeResult::Type UBTTask_MeleeAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	bFinishing = false;
	CachedOwnerComp = &OwnerComp;

	UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent();
	AAIController* AIC = OwnerComp.GetAIOwner();
	ACharacter* Character = AIC ? Cast<ACharacter>(AIC->GetPawn()) : nullptr;

	if (!BB || !Character || !Character->GetMesh())
	{
		return EBTNodeResult::Failed;
	}

	AEnemy* Enemy = Cast<AEnemy>(Character);
	if (!Enemy)
	{
		return EBTNodeResult::Failed;
	}

	// Marcamos atacando (evita spam en el BT)
	BB->SetValueAsBool(IsAttackingKey.SelectedKeyName, true);

	// Paramos el movimiento
	if (UCharacterMovementComponent* Move = Character->GetCharacterMovement())
	{
		Move->StopMovementImmediately();
	}

	// Orientamos al target
	AActor* Target = Cast<AActor>(BB->GetValueAsObject(TargetActorKey.SelectedKeyName));
	if (Target)
	{
		FVector To = Target->GetActorLocation() - Character->GetActorLocation();
		To.Z = 0.f;

		if (To.SizeSquared() > 1.f)
		{
			Character->SetActorRotation(FRotator(0.f, To.Rotation().Yaw, 0.f));
		}
	}

	// Montage + Anim
	UAnimMontage* AttackMontage = Enemy->GetAttackMontage();
	UAnimInstance* Anim = Character->GetMesh()->GetAnimInstance();
	if (!AttackMontage || !Anim)
	{
		BB->SetValueAsBool(IsAttackingKey.SelectedKeyName, false);
		return EBTNodeResult::Failed;
	}

	CachedAnimInstance = Anim;
	CachedMontage = AttackMontage;

	// Limpieza por si quedara algo anterior
	ClearMontageDelegates();

	// Lanzamos el ataque
	if (!PlayAttackMontage())
	{
		BB->SetValueAsBool(IsAttackingKey.SelectedKeyName, false);
		CleanupState();
		return EBTNodeResult::Failed;
	}

	return EBTNodeResult::InProgress;
}

bool UBTTask_MeleeAttack::PlayAttackMontage()
{
	if (!CachedAnimInstance || !CachedMontage)
	{
		return false;
	}

	// 1) Reproducir primero y comprobar que arrancó
	const float PlayedLen = CachedAnimInstance->Montage_Play(CachedMontage, 1.0f);
	if (PlayedLen <= 0.f)
	{
		return false;
	}

	// 2) Delegates después (más fiable)
	MontageBlendOutDelegate.BindUObject(this, &UBTTask_MeleeAttack::OnMontageBlendingOut);
	CachedAnimInstance->Montage_SetBlendingOutDelegate(MontageBlendOutDelegate, CachedMontage);

	MontageEndDelegate.BindUObject(this, &UBTTask_MeleeAttack::OnMontageEnded);
	CachedAnimInstance->Montage_SetEndDelegate(MontageEndDelegate, CachedMontage);

	return true;
}

bool UBTTask_MeleeAttack::ShouldRepeatAttack() const
{
	if (!CachedOwnerComp)
	{
		return false;
	}

	const UBlackboardComponent* BB = CachedOwnerComp->GetBlackboardComponent();
	if (!BB)
	{
		return false;
	}

	// Debe seguir existiendo target y estar en rango
	const AActor* Target = Cast<AActor>(BB->GetValueAsObject(TargetActorKey.SelectedKeyName));
	if (!Target)
	{
		return false;
	}

	return BB->GetValueAsBool(InAttackRangeKey.SelectedKeyName);
}

void UBTTask_MeleeAttack::OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted)
{
	if (bFinishing || !CachedOwnerComp || !CachedMontage)
	{
		return;
	}

	if (Montage != CachedMontage)
	{
		return;
	}

	// Si se interrumpe (abort / otro montage / etc.), cerramos la task.
	// Si NO se interrumpe, dejamos que OnMontageEnded decida repetir o terminar.
	if (bInterrupted)
	{
		FinishAttackTask(true);
	}
}

void UBTTask_MeleeAttack::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (bFinishing || !CachedOwnerComp || !CachedMontage)
	{
		return;
	}

	if (Montage != CachedMontage)
	{
		return;
	}

	if (bInterrupted)
	{
		FinishAttackTask(true);
		return;
	}

	// Si sigue en rango -> repetir ataque (no finaliza la task)
	if (ShouldRepeatAttack())
	{
		PlayAttackMontage();
		return;
	}

	// Si ya no está en rango -> terminar para que el BT vuelva a perseguir / lo que toque
	FinishAttackTask(false);
}

void UBTTask_MeleeAttack::ClearMontageDelegates()
{
	if (!CachedAnimInstance || !CachedMontage)
	{
		return;
	}

	FOnMontageBlendingOutStarted EmptyBlend;
	CachedAnimInstance->Montage_SetBlendingOutDelegate(EmptyBlend, CachedMontage);

	FOnMontageEnded EmptyEnd;
	CachedAnimInstance->Montage_SetEndDelegate(EmptyEnd, CachedMontage);
}

void UBTTask_MeleeAttack::CleanupState()
{
	CachedOwnerComp = nullptr;
	CachedMontage = nullptr;
	CachedAnimInstance = nullptr;
	bFinishing = false;
}

void UBTTask_MeleeAttack::FinishAttackTask(bool bInterrupted)
{
	if (!CachedOwnerComp || bFinishing)
	{
		return;
	}

	bFinishing = true;

	if (UBlackboardComponent* BB = CachedOwnerComp->GetBlackboardComponent())
	{
		BB->SetValueAsBool(IsAttackingKey.SelectedKeyName, false);
	}

	ClearMontageDelegates();

	const EBTNodeResult::Type Result = bInterrupted ? EBTNodeResult::Failed : EBTNodeResult::Succeeded;
	FinishLatentTask(*CachedOwnerComp, Result);
}

EBTNodeResult::Type UBTTask_MeleeAttack::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Limpieza de blackboard
	if (UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent())
	{
		BB->SetValueAsBool(IsAttackingKey.SelectedKeyName, false);
	}

	// Parar montage si estaba activo
	if (CachedAnimInstance && CachedMontage)
	{
		CachedAnimInstance->Montage_Stop(0.1f, CachedMontage);
		ClearMontageDelegates();
	}

	CleanupState();
	return EBTNodeResult::Aborted;
}

void UBTTask_MeleeAttack::OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTNodeResult::Type TaskResult)
{
	Super::OnTaskFinished(OwnerComp, NodeMemory, TaskResult);

	// Seguridad: que no quede el bool enganchado si se termina externamente
	if (UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent())
	{
		BB->SetValueAsBool(IsAttackingKey.SelectedKeyName, false);
	}

	ClearMontageDelegates();
	CleanupState();
}
