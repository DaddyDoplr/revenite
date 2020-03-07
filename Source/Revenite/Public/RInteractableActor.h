// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RInteractableActor.generated.h"

UCLASS()
class REVENITE_API ARInteractableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARInteractableActor();

	UFUNCTION(BlueprintNativeEvent)
	void Interact();

	virtual void Interact_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void StartFocus();

	virtual void StartFocus_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void EndFocus();

	virtual void EndFocus_Implementation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
