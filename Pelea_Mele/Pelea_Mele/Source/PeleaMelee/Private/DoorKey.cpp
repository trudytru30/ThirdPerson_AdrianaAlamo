#include "DoorKey.h"

#include "Door.h"
#include "Ninja.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

ADoorKey::ADoorKey()
{
    PrimaryActorTick.bCanEverTick = false;

    USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    SetRootComponent(Root);

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(Root);
    Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    TriggerZone = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerZone"));
    TriggerZone->SetupAttachment(Root);
    TriggerZone->SetSphereRadius(80.f);
    TriggerZone->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    TriggerZone->SetCollisionObjectType(ECC_WorldDynamic);
    TriggerZone->SetCollisionResponseToAllChannels(ECR_Ignore);
    TriggerZone->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

void ADoorKey::BeginPlay()
{
    Super::BeginPlay();

    TriggerZone->OnComponentBeginOverlap.AddDynamic(this, &ADoorKey::OnTriggerBeginOverlap);
}

void ADoorKey::OnTriggerBeginOverlap(
    UPrimitiveComponent* OverlappedComponent,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    if (bPickedUp)
    {
        return;
    }
    
    if (!Cast<ANinja>(OtherActor))
    {
        return;
    }

    bPickedUp = true;

    //Buscar la ADoor más cercana en el nivel
    TArray<AActor*> Doors;
    UGameplayStatics::GetAllActorsOfClass(this, ADoor::StaticClass(), Doors);

    ADoor* NearestDoor = nullptr;
    float MinDist = FLT_MAX;
    for (AActor* Actor : Doors)
    {
        const float Dist = FVector::Dist(GetActorLocation(), Actor->GetActorLocation());
        if (Dist < MinDist)
        {
            MinDist = Dist;
            NearestDoor = Cast<ADoor>(Actor);
        }
    }

    if (NearestDoor)
    {
        NearestDoor->Interact();
    }

    if (SoundOnPickup)
    {
        UGameplayStatics::PlaySoundAtLocation(this, SoundOnPickup, GetActorLocation());
    }

    Destroy();
}