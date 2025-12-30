#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PeleaMeleGameInstance.generated.h"

UCLASS()
class PELEA_MELE_API UPeleaMeleGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunState")
	int32 ShurikensCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunState")
	int32 BombCount = 0;
};
