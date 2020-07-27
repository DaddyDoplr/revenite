// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class REVENITE_API URGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	UFUNCTION()
		virtual void BeginLoadingScreen(const FString& MapName);
	UFUNCTION()
		virtual void EndLoadingScreen(UWorld* InLoadedWorld);

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Loading screen")
		TArray<FString> MoviePaths;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Images, meta = (AllowedClasses = "Texture2D"))
		TArray<FSoftObjectPath> LoadingScreenImages;
	
};
