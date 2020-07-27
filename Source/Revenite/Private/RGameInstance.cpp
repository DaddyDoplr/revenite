// Fill out your copyright notice in the Description page of Project Settings.


#include "RGameInstance.h"
#include "Runtime/MoviePlayer/Public/MoviePlayer.h"

void URGameInstance::Init()
{
	Super::Init();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &URGameInstance::BeginLoadingScreen);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &URGameInstance::EndLoadingScreen);
}

void URGameInstance::BeginLoadingScreen(const FString& MapName)
{
	if (!IsRunningDedicatedServer())
	{
		FLoadingScreenAttributes LoadingScreen;

		LoadingScreen.bAutoCompleteWhenLoadingCompletes = true;
		//TSharedPtr<class SWidget> LoadingScreenWidget = SNew(SLoadingScreenWidget);
		//SAssignNew(LoadingScreenWidget, SLoadingScreenWidget).MapName(MapName);
		//SAssignNew(LoadingScreenWidget, SLoadingScreenWidget).BackgroundImg(LoadingScreenImages[0]);
		//FMath::Rand() % (LoadingScreenImages.Num() - 1)

		//LoadingScreen.WidgetLoadingScreen = LoadingScreenWidget;
		LoadingScreen.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();

		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
	}
}

void URGameInstance::EndLoadingScreen(UWorld* InLoadedWorld)
{

}