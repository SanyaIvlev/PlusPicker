// Fill out your copyright notice in the Description page of Project Settings.


#include "ApplePickerGameMode.h"
#include "ApplePickerGameState.h"
#include "Basket.h"
#include "BasketController.h"
#include "Kismet/GameplayStatics.h"

// AApplePickerGameMode::AApplePickerGameMode()
// {
// 	DefaultPawnClass = ABasket::StaticClass();
//
// 	// 2. Устанавливаем класс контроллера (PlayerController)
// 	PlayerControllerClass = ABasketController::StaticClass();
//
// 	// 3. Устанавливаем класс состояния игры (GameState)
// 	GameStateClass = AApplePickerGameState::StaticClass();
// }



void AApplePickerGameMode::BeginPlay()
{
	APawn* pawnPtr = UGameplayStatics::GetPlayerPawn(this, 0); // !
	BasketPtr = Cast<ABasket>(pawnPtr);
	
	AGameStateBase* gameStatePtr = UGameplayStatics::GetGameState(this);
	ApplePickerGameStatePtr = Cast<AApplePickerGameState>(gameStatePtr);
}

void AApplePickerGameMode::OnAppleDestroyed() const
{
	ApplePickerGameStatePtr->HandleAppleMiss();
	
	bool isNoBasketsLeft = BasketPtr->BasketMeshesPtr.IsEmpty();
	UE_LOG(LogTemp, Log, TEXT("Num of baskets: %d"), BasketPtr->BasketMeshesPtr.Num());
	
	
	if (isNoBasketsLeft)
	{
		//save score
		
		if (!LevelToOpen.IsNull())
		{
			UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(), LevelToOpen, true);
			
		}
	}
}
