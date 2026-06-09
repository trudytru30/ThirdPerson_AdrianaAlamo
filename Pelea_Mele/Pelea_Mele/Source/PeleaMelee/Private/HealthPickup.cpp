// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPickup.h"

#include "HealthComponent.h"
#include "Ninja.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AHealthPickup::AHealthPickup()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->SetupAttachment(Root);
	Collision->SetSphereRadius(60.0f);

	Collision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Collision->SetCollisionObjectType(ECC_WorldDynamic);
	Collision->SetCollisionResponseToAllChannels(ECR_Ignore);
	Collision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
}

// Called when the game starts or when spawned
void AHealthPickup::BeginPlay()
{
	Super::BeginPlay();
	if (Collision)
	{
		Collision->OnComponentBeginOverlap.AddDynamic(this, &AHealthPickup::OnCollisionBeginOverlap);
	}
	
}

// Called every frame
void AHealthPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHealthPickup::OnCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (bConsumed)
	{
		return;
	}
	
	ANinja* Ninja = Cast<ANinja>(OtherActor);
	if (!Ninja)
	{
		return;
	}
	
	if (bConsumed ||!IsValid(OtherActor) || OtherActor == this)
	{
		return;
	}

	UHealthComponent* HealthComp = OtherActor->FindComponentByClass<UHealthComponent>();
	if (!HealthComp)
	{
		return;
	}
	Consume(HealthComp);

	
}

void AHealthPickup::Consume(UHealthComponent* HC)
{
	if (FMath::IsNearlyEqual(HC->GetMaxHealt(), HC->GetCurrentHealt()) && HealthDelta > 0.0f)
	{
		return;
	}
	
	HC->ApplyDelta(HealthDelta);
	bConsumed = true;

	if (PickupSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, PickupSound, GetActorLocation());
	}

	Destroy();
}

