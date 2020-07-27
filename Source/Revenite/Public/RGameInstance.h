// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "RGameInstance.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FLevelData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowedClasses = "Texture2D"))
	TArray<FSoftObjectPath> LoadingScreenImages;
};

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
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Loading Screen")
	TMap<FString, FLevelData> LevelsData;
};