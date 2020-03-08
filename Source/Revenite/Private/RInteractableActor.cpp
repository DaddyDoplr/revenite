// Fill out your copyright notice in the Description page of Project Settings.


#include "RInteractableActor.h"
#include "Engine/Engine.h"

// Sets default values
ARInteractableActor::ARInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ARInteractableActor::Interact_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, "Interacted");
}

void ARInteractableActor::StartFocus_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, "Looked at interactable");
}

void ARInteractableActor::EndFocus_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, "Stopped looking at interactable");
}

// Called when the game starts or when spawned
void ARInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

