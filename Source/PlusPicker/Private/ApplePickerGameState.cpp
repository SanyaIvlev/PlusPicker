// Fill out your copyright notice in the Description page of Project Settings.


#include "ApplePickerGameState.h"

#include "Apple.h"
#include "ApplePickerSaveGame.h"
#include "Basket.h"
#include "Kismet/GameplayStatics.h"

void AApplePickerGameState::BeginPlay()
{
	Super::BeginPlay();
	
	APawn* pawnPtr = UGameplayStatics::GetPlayerPawn(this, 0); // !
	BasketPtr = Cast<ABasket>(pawnPtr);
	
	TryLoadHighScore();
}

void AApplePickerGameState::HandleAppleMiss()
{
	DestroyExistingApples();
	RemoveBasket();
}

void AApplePickerGameState::UpdateGameScore()
{
	Score += 100;
	OnScoreUpdated.Broadcast(Score);
	
	if (Score > HighScore)
	{
		HighScore = Score;
		OnHighScoreUpdated.Broadcast(HighScore);
		SaveHighScore();
	}
}

void AApplePickerGameState::SaveHighScore() const
{
	SaveGame->HighScore = HighScore;
	UGameplayStatics::SaveGameToSlot(SaveGame, SaveSlotName, 0);
	
	UE_LOG(LogTemp, Log, TEXT("Score: %d, highest: %d"), Score, SaveGame->HighScore);
}

void AApplePickerGameState::TryLoadHighScore()
{
	if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, 0))
	{
		USaveGame* loadedSaveGame = UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0);
		SaveGame = Cast<UApplePickerSaveGame>(loadedSaveGame);
		HighScore = SaveGame->HighScore;
	}
	else
	{
		USaveGame* createdSaveGame = UGameplayStatics::CreateSaveGameObject(UApplePickerSaveGame::StaticClass());
		SaveGame = Cast<UApplePickerSaveGame>(createdSaveGame);
	}
	
	UE_LOG(LogTemp, Log, TEXT("LOADED HIGH SCORE --> %d"), SaveGame->HighScore);
}

void AApplePickerGameState::DestroyExistingApples() const
{
	TArray<AActor*> apples;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AApple::StaticClass(), apples);
	
	for (AActor* Apple : apples)
	{
		Apple->Destroy();
	}
}

void AApplePickerGameState::RemoveBasket() const
{
	TArray<UStaticMeshComponent*>& meshesPtr = BasketPtr->BasketMeshesPtr;
	
	if (meshesPtr.IsEmpty())
		return;
	
	UStaticMeshComponent* topMeshPtr = meshesPtr.Last();
	
	topMeshPtr->DestroyComponent();
	meshesPtr.Remove(topMeshPtr);
}
