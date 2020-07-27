// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SCompoundWidget.h"
#include "SlateBasics.h"
#include "SlateExtras.h"

/**
 * 
 */

class SLoadingScreenWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLoadingScreenWidget) {}

	SLATE_ARGUMENT(FText, MapDisplayName)
	SLATE_ARGUMENT(FSoftObjectPath, BackgroundImg)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:
	TSharedPtr<FSlateDynamicImageBrush> LoadingScreenBrush;
};