#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorKey.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class USoundBase;

UCLASS()
class PELEAMELEE_API ADoorKey : public AActor
{
	GENERATED_BODY()

public:
	ADoorKey();

protected:
	virtual void BeginPlay() override;

	// ── Componentes ───────────────────────────────────────────────

	// Zona de detección de overlap con el Ninja
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USphereComponent* TriggerZone = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY(EditAnywhere, Category="Audio")
	USoundBase* SoundOnPickup = nullptr;

private:
	bool bPickedUp = false;

	UFUNCTION()
	void OnTriggerBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
};