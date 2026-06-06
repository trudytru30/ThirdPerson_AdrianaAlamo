// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AnimNotifyMeleeInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAnimNotifyMeleeInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PELEAMELEE_API IAnimNotifyMeleeInterface
{
	GENERATED_BODY()
public:
	// True: activa ventana de colisiones / False: desactiva
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AnimNotifyMeleeInterface")
	void SetMeleeWindowActive(bool bActive);
};
