// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasketController.generated.h"

class UScoreIndicatorWidget;
class ABasket;
/**
 * 
 */
UCLASS()
class PLUSPICKER_API ABasketController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basket")
	TSubclassOf<UScoreIndicatorWidget> ScoreIndicatorWidgetClass;
	
	virtual void BeginPlay() override;
	
private:
	 UPROPERTY()
	 ABasket* BasketPawnPtr;
	
	 virtual void Tick(float DeltaTime) override;
	
};
