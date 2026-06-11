#include "Door.h"

#include "Ninja.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"

ADoor::ADoor()
{
    PrimaryActorTick.bCanEverTick = true;

    USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    SetRootComponent(Root);

    HojaIzquierda = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HojaIzquierda"));
    HojaIzquierda->SetupAttachment(Root);

    HojaDerecha = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HojaDerecha"));
    HojaDerecha->SetupAttachment(Root);
    
    TriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerZone"));
    TriggerZone->SetupAttachment(Root);
    TriggerZone->SetBoxExtent(FVector(150.f, 150.f, 100.f));
    TriggerZone->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    TriggerZone->SetCollisionObjectType(ECC_WorldDynamic);
    TriggerZone->SetCollisionResponseToAllChannels(ECR_Ignore);
    TriggerZone->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
    
    TextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextRenderComponent"));
    TextRenderComponent->SetupAttachment(Root);
    TextRenderComponent->SetText(FText::FromString(TEXT("Presiona E para abrir")));
    TextRenderComponent->SetHorizontalAlignment(EHTA_Center);
    TextRenderComponent->SetVisibility(false);
}

void ADoor::BeginPlay()
{
    Super::BeginPlay();

    //Posiciones originales de las hojas para el Lerp de apertura
    HojaIzquierdaOrigin = HojaIzquierda->GetRelativeLocation();
    HojaDerechaOrigin   = HojaDerecha->GetRelativeLocation();

    TriggerZone->OnComponentBeginOverlap.AddDynamic(this, &ADoor::OnTriggerBeginOverlap);
    TriggerZone->OnComponentEndOverlap.AddDynamic(this, &ADoor::OnTriggerEndOverlap);
}

void ADoor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!bOpening)
    {
        return;
    }

    OpenElapsed = FMath::Min(OpenElapsed + DeltaTime, DoorOpenDuration);

    // Alpha normalizado [0,1]
    const float Alpha = (DoorOpenDuration > 0.f)
                            ? (OpenElapsed / DoorOpenDuration)
                            : 1.f;

    //Suavizado ease-in/out
    const float SmoothedAlpha = FMath::InterpEaseInOut(0.f, 1.f, Alpha, 2.f);

    HojaIzquierda->SetRelativeLocation(
        FMath::Lerp(HojaIzquierdaOrigin, HojaIzquierdaOrigin + HojaIzquierdaOpenOffset, SmoothedAlpha));

    HojaDerecha->SetRelativeLocation(
        FMath::Lerp(HojaDerechaOrigin, HojaDerechaOrigin + HojaDerechaOpenOffset, SmoothedAlpha));

    //Al terminar la interpolación, ocultar el prompt de interacción
    if (FMath::IsNearlyEqual(Alpha, 1.f))
    {
        bOpening = false;
        TextRenderComponent->SetVisibility(false);
    }
}

void ADoor::OnTriggerBeginOverlap(
    UPrimitiveComponent* OverlappedComponent,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    if (!Cast<ANinja>(OtherActor))
    {
        return;
    }

    if (!bActive)
    {
        TextRenderComponent->SetVisibility(true);
    }

    if (SoundOnInteract)
    {
        UGameplayStatics::PlaySoundAtLocation(this, SoundOnInteract, GetActorLocation());
    }
}

void ADoor::OnTriggerEndOverlap(
    UPrimitiveComponent* OverlappedComponent,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex)
{
    if (!Cast<ANinja>(OtherActor))
    {
        return;
    }

    TextRenderComponent->SetVisibility(false);
}

void ADoor::Interact()
{
    if (bActive)
    {
        return;
    }

    bActive     = true;
    bOpening    = true;
    OpenElapsed = 0.f;

    if (SoundOnOpen)
    {
        UGameplayStatics::PlaySoundAtLocation(this, SoundOnOpen, GetActorLocation());
    }
}