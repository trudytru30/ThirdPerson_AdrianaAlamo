// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifyState_MeleeWindow.h"

#include "AnimNotifyMeleeInterface.h"

void UAnimNotifyState_MeleeWindow::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                               float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	if (!MeshComp) return;

	AActor* Owner = MeshComp->GetOwner();
	if (!Owner) return;

	if (Owner->GetClass()->ImplementsInterface(UAnimNotifyMeleeInterface::StaticClass()))
	{
		IAnimNotifyMeleeInterface::Execute_SetMeleeWindowActive(Owner, true);
	}
}

void UAnimNotifyState_MeleeWindow::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	if (!MeshComp) return;

	AActor* Owner = MeshComp->GetOwner();
	if (!Owner) return;

	if (Owner->GetClass()->ImplementsInterface(UAnimNotifyMeleeInterface::StaticClass()))
	{
		IAnimNotifyMeleeInterface::Execute_SetMeleeWindowActive(Owner, false);
	}
}
