// Fill out your copyright notice in the Description page of Project Settings.

#include "SLoadingScreenWidget.h"
#include "Widgets/Images/SImage.h"
#include "Engine/Texture2D.h"
#include "Engine/Public/Slate/DeferredCleanupSlateBrush.h"

struct FLoadingScreenBrush : public FSlateDynamicImageBrush, public FGCObject
{
	FLoadingScreenBrush(const FName InTextureName, const FVector2D& InImageSize)
		: FSlateDynamicImageBrush(InTextureName, InImageSize)
	{
		SetResourceObject(LoadObject<UObject>(NULL, *InTextureName.ToString()));
	}

	virtual void AddReferencedObjects(FReferenceCollector& Collector) override
	{
		FSlateBrush::AddReferencedObjects(Collector);
	}
};

void SLoadingScreenWidget::Construct(const FArguments& InArgs)
{
	LoadingScreenBrush = MakeShareable(new FLoadingScreenBrush(InArgs._BackgroundImg.GetAssetPathName() , FVector2D(1920, 1080)));

	ChildSlot
		[
			SNew(SOverlay)

			+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.Image(LoadingScreenBrush.Get())
		]
		
	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Bottom)
		[

			SNew(SBox)
			.HeightOverride(200)
			[
				SNew(SOverlay)
				+ SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SColorBlock)
					.Color(FLinearColor(FColor(0, 0, 0, 128)))
				]

				+ SOverlay::Slot()
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Top)
				[
					SNew(STextBlock)
					.Text(InArgs._MapDisplayName)
				]

				+ SOverlay::Slot()
				.HAlign(HAlign_Right)
				.VAlign(VAlign_Bottom)
				.Padding(FMargin(32, 32))
				[
					SNew(SThrobber)
				]
			]
		]
	];
}
