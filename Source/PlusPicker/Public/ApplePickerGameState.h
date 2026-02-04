// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ApplePickerGameState.generated.h"

class ABasket;
/**
 * 
 */
UCLASS()
class PLUSPICKER_API AApplePickerGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Apple Picker Game State")
	ABasket* BasketPtr;
	
	void HandleAppleMiss();
	
protected:
	virtual void BeginPlay() override;
	
private:
	void DestroyExistingApples();
	void RemoveBasket();
	
};
