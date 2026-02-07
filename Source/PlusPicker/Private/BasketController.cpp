// Fill out your copyright notice in the Description page of Project Settings.


#include "BasketController.h"

#include "Basket.h"
#include "UScoreIndicatorWidget.h"
#include "Blueprint/UserWidget.h"

void ABasketController::BeginPlay()
{
	bAutoManageActiveCameraTarget = false;
	ABasket* pawn = GetPawn<ABasket>();
	BasketPawnPtr = pawn;
	
	SetShowMouseCursor(true);
	
	UScoreIndicatorWidget* createdWidget = CreateWidget<UScoreIndicatorWidget>(this, ScoreIndicatorWidgetClass);
	createdWidget->AddToViewport();
	
} 

void ABasketController::Tick(float DeltaTime)
{
	if (BasketPawnPtr == nullptr)
		return;
	
	float xLocation, yLocation;
	bool isMouseInWindow = GetMousePosition(xLocation, yLocation);
	
	if (!isMouseInWindow)
		return;
	
	FVector mouseWorldLocation;
	FVector mouseWorldDirection;
	this->DeprojectScreenPositionToWorld(xLocation, yLocation, mouseWorldLocation, mouseWorldDirection);
	
	FVector basketLocation = BasketPawnPtr->GetActorLocation();
	BasketPawnPtr->Move(FVector(mouseWorldLocation.X, basketLocation.Y, basketLocation.Z));
}