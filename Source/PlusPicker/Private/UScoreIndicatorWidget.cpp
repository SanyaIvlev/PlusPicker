// Fill out your copyright notice in the Description page of Project Settings.


#include "UScoreIndicatorWidget.h"

#include "ApplePickerGameState.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UScoreIndicatorWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	AGameStateBase* gameStatePtr = UGameplayStatics::GetGameState(this);
	ApplePickerGameStatePtr = Cast<AApplePickerGameState>(gameStatePtr);
	
	ApplePickerGameStatePtr->OnScoreUpdated.AddDynamic(this, &UScoreIndicatorWidget::UpdateScore);
	ApplePickerGameStatePtr->OnHighScoreUpdated.AddDynamic(this, &UScoreIndicatorWidget::UpdateHighScore);
	
	UpdateHighScore(ApplePickerGameStatePtr->HighScore);
}

void UScoreIndicatorWidget::UpdateHighScore(int newHighScore)
{
	FText highScoreText = FText::AsNumber(newHighScore);
	HighScoreTextBlockPtr->SetText(highScoreText);
}

void UScoreIndicatorWidget::UpdateScore(int newScore)
{
	FText highScoreText = FText::AsNumber(newScore);
	ScoreTextBlockPtr->SetText(highScoreText);
}

void UScoreIndicatorWidget::NativeDestruct()
{
	ApplePickerGameStatePtr->OnScoreUpdated.RemoveDynamic(this, &UScoreIndicatorWidget::UpdateScore);
	ApplePickerGameStatePtr->OnHighScoreUpdated.RemoveDynamic(this, &UScoreIndicatorWidget::UpdateHighScore);
}
