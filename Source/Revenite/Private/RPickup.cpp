// Fill out your copyright notice in the Description page of Project Settings.


#include "RPickup.h"
#include "Components/SphereComponent.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Sets default values
ARPickup::ARPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollisionComponent"));
	CollisionComp->InitSphereRadius(50.f);
	RootComponent = CollisionComp;
}

void ARPickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OnPickup.Broadcast();
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, "Picked up");

	FTransform EmitterTransform;
	EmitterTransform.SetLocation(GetActorLocation());

	if (PickupEffect) {
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), PickupEffect, EmitterTransform);
	}

	if (PickupSound)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), PickupSound, GetActorLocation());
	}

	Destroy();
}

// Called when the game starts or when spawned
void ARPickup::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ARPickup::OnOverlapBegin);
}

