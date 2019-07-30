// Fill out your copyright notice in the Description page of Project Settings.


#include "RRedd.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ARRedd::ARRedd()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false;

	// Camera Boom Arm
	CameraBoomArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArmComponent"));
	CameraBoomArm->SetupAttachment(RootComponent);
	CameraBoomArm->TargetArmLength = 350.f;
	CameraBoomArm->bUsePawnControlRotation = true;
	CameraBoomArm->bEnableCameraLag = true;
	CameraBoomArm->CameraLagSpeed = 5.f;
	CameraBoomArm->CameraLagMaxDistance = 175.f;
	CameraBoomArm->TargetOffset = FVector(0.f, 0.f, 50.f);

	// Camera
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComp->SetupAttachment(CameraBoomArm, FName("Target"));
	CameraComp->FieldOfView = 100.f;
}

// Called when the game starts or when spawned
void ARRedd::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARRedd::MoveForward(float Amount)
{
	FVector WorldDirection = UKismetMathLibrary::GetForwardVector(FRotator(0.f, GetControlRotation().Yaw, 0.f));
	AddMovementInput(WorldDirection, Amount);
}

void ARRedd::MoveRight(float Amount)
{
	FVector WorldDirection = UKismetMathLibrary::GetRightVector(FRotator(0.f, GetControlRotation().Yaw, 0.f));
	AddMovementInput(WorldDirection, Amount);
}

// Called every frame
void ARRedd::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARRedd::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ARRedd::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ARRedd::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &ARRedd::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &ARRedd::AddControllerYawInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ARRedd::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ARRedd::StopJumping);
}

