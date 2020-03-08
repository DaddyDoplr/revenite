// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RPickup.generated.h"

class USphereComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPickUp);

UCLASS()
class REVENITE_API ARPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARPickup();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USphereComponent* CollisionComp;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(BlueprintAssignable)
	FOnPickUp OnPickup;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "FX")
	class UParticleSystem* PickupEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "FX")
	class USoundBase* PickupSound;
};
