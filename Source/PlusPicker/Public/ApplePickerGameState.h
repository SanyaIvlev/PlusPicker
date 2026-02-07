// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ApplePickerGameState.generated.h"

class UApplePickerSaveGame;
class ABasket;
/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FScoreUpdate, int32, NewScore);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHighScoreUpdate, int32, NewHighScore);

UCLASS()
class PLUSPICKER_API AApplePickerGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Apple Picker Game State | Setup")
	ABasket* BasketPtr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apple Picker Game State | Score")
	int Score;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apple Picker Game State | Score")
	int HighScore;
	
	UPROPERTY(BlueprintAssignable, Category = "Apple Picker Game State | Events")
	FScoreUpdate OnScoreUpdated;
	
	UPROPERTY(BlueprintAssignable, Category = "Apple Picker Game State | Events")
	FHighScoreUpdate OnHighScoreUpdated;
	
	
	void HandleAppleMiss() const;
	void UpdateGameScore();
	void SaveHighScore() const;
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Apple Picker Game State | Setup")
	UApplePickerSaveGame* SaveGame;
	
	UPROPERTY()
	FString SaveSlotName = TEXT("HighScoreSaveGame");
	
	
	virtual void BeginPlay() override;
	void TryLoadHighScore();
	
private:
	void DestroyExistingApples() const;
	void RemoveBasket() const;
	
};
