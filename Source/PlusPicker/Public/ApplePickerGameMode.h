 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ApplePickerGameMode.generated.h"

class ABasket;
class AApplePickerGameState;
/**
 * 
 */
UCLASS()
class PLUSPICKER_API AApplePickerGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	// AApplePickerGameMode();
	
	void OnAppleDestroyed() const;
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Apple Picker Game Mode | Setup")
	ABasket* BasketPtr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Apple Picker Game Mode | Setup")
	AApplePickerGameState* ApplePickerGameStatePtr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apple Picker Game Mode | Reload Level")
	TSoftObjectPtr<UWorld> LevelToOpen;
	
	virtual void BeginPlay() override;
	
	
};
