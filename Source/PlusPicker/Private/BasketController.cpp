// Fill out your copyright notice in the Description page of Project Settings.


#include "BasketController.h"

#include "Basket.h"

void ABasketController::BeginPlay()
{
	bAutoManageActiveCameraTarget = false;
	ABasket* pawn = GetPawn<ABasket>();
	BasketPawn = pawn;
	
	SetShowMouseCursor(true);
	// construct widget
	
	
	BasketPawn->Move(FVector(0,0,100));
	BasketPawn->SetActorRotation(FRotator(0,0,0));
	
} 

void ABasketController::Tick(float DeltaTime)
{
	if (BasketPawn == nullptr)
		return;
	
	float xLocation, yLocation;
	bool isMouseInWindow = GetMousePosition(xLocation, yLocation);
	
	if (!isMouseInWindow)
		return;
	
	FVector mouseWorldLocation;
	FVector mouseWorldDirection;
	this->DeprojectScreenPositionToWorld(xLocation, yLocation, mouseWorldLocation, mouseWorldDirection);
	
	UE_LOG(LogTemp, Log, TEXT("x: %f"), mouseWorldLocation.X);
	
	FVector basketLocation = BasketPawn->GetActorLocation();
	BasketPawn->Move(FVector(mouseWorldLocation.X, basketLocation.Y, basketLocation.Z));
}