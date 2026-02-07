// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UScoreIndicatorWidget.generated.h"

class AApplePickerGameState;
class UTextBlock;
/**
 * 
 */
UCLASS()
class PLUSPICKER_API UScoreIndicatorWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION()
	void UpdateScore(int newScore);
	
	UFUNCTION()
	void UpdateHighScore(int newHighScore);
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score Indicator")
	UTextBlock* ScoreTextBlockPtr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score Indicator")
	UTextBlock* HighScoreTextBlockPtr;
	
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
private:
	UPROPERTY(VisibleAnywhere, Category = "Score Indicator")
	AApplePickerGameState* ApplePickerGameStatePtr;
};
