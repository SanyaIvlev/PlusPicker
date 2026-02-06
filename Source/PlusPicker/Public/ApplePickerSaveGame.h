// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "ApplePickerSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class PLUSPICKER_API UApplePickerSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	int HighScore;
};
