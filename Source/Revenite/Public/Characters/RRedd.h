// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RRedd.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class REVENITE_API ARRedd : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	ARRedd();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* CameraBoomArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* CameraComp;

	void MoveForward(float Amount);
	void MoveRight(float Amount);

	class ARInteractableActor* GetInteractableInView();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Gameplay")
	float InteractRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Gameplay")
	float MaxInteractDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bDebugInteractable;

	bool bHasNewFocus;

	class ARInteractableActor* FocusedInteractableActor;
};
