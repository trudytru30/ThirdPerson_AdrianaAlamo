#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UTextRenderComponent;
class USoundBase;

UCLASS()
class PELEAMELEE_API ADoor : public AActor
{
    GENERATED_BODY()

public:
    ADoor();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    // ── Componentes ───────────────────────────────────────────────

    //Zona de detección de overlap con el Ninja
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    UBoxComponent* TriggerZone = nullptr;

    //Mallas de las dos hojas de la puerta
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    UStaticMeshComponent* HojaIzquierda = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    UStaticMeshComponent* HojaDerecha = nullptr;

    //Texto de interacción
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    UTextRenderComponent* TextRenderComponent = nullptr;

    // ── Sonidos ───────────────────────────────────────────────────
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio")
    USoundBase* SoundOnOpen = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio")
    USoundBase* SoundOnInteract = nullptr;

    // ── Variables de lógica ───────────────────────────────────────
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Door")
    bool bActive = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Door")
    float DoorOpenDuration = 1.0f;

    //Desplazamiento relativo de cada hoja al abrirse
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Door")
    FVector HojaIzquierdaOpenOffset = FVector(-90.f, 0.f, 0.f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Door")
    FVector HojaDerechaOpenOffset = FVector(90.f, 0.f, 0.f);

    // ── Callbacks overlap ─────────────────────────────────────────

    UFUNCTION()
    void OnTriggerBeginOverlap(
        UPrimitiveComponent* OverlappedComponent,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult);

    UFUNCTION()
    void OnTriggerEndOverlap(
        UPrimitiveComponent* OverlappedComponent,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex);

public:
    UFUNCTION(BlueprintCallable, Category="Door")
    void Interact();

private:
    //Posiciones originales de las hojas
    FVector HojaIzquierdaOrigin;
    FVector HojaDerechaOrigin;

    //Tiempo acumulado de la animación de apertura [0, DoorOpenDuration]
    float OpenElapsed = 0.f;
    bool bOpening = false;
};