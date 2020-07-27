// Fill out your copyright notice in the Description page of Project Settings.


#include "RGameInstance.h"
#include "Runtime/MoviePlayer/Public/MoviePlayer.h"
#include "SLoadingScreenWidget.h"

void URGameInstance::Init()
{
	Super::Init();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &URGameInstance::BeginLoadingScreen);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &URGameInstance::EndLoadingScreen);

}

void URGameInstance::BeginLoadingScreen(const FString& MapName)
{
	

	if (IsMoviePlayerEnabled() && !GetMoviePlayer()->IsStartupMoviePlaying())
	{
		int i = FMath::RandRange(0, LevelsData[MapName].LoadingScreenImages.Num() - 1);

		const TCHAR* bruh = *LevelsData[MapName].LoadingScreenImages[i].GetAssetPathName().ToString();

		LoadObject<UObject>(NULL, bruh);

		FLoadingScreenAttributes LoadingScreen;

		LoadingScreen.bAutoCompleteWhenLoadingCompletes = true;
		TSharedPtr<class SWidget> LoadingScreenWidget = SNew(SLoadingScreenWidget)
			.MapDisplayName(LevelsData[MapName].DisplayName)
			.BackgroundImg(LevelsData[MapName].LoadingScreenImages[i]);

		

		LoadingScreen.WidgetLoadingScreen = LoadingScreenWidget;

		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
	}
}

void URGameInstance::EndLoadingScreen(UWorld* InLoadedWorld)
{

}