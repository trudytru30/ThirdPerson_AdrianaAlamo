#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PeleaMeleeGameInstance.generated.h"

UCLASS()
class PELEAMELEE_API UPeleaMeleeGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunState")
	int32 ShurikensCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunState")
	int32 BombCount = 0;

};
