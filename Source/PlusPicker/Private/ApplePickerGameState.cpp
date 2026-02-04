// Fill out your copyright notice in the Description page of Project Settings.


#include "ApplePickerGameState.h"

#include "Apple.h"
#include "Basket.h"
#include "Kismet/GameplayStatics.h"

void AApplePickerGameState::BeginPlay()
{
	APawn* pawnPtr = UGameplayStatics::GetPlayerPawn(this, 0); // !
	BasketPtr = Cast<ABasket>(pawnPtr);
}

void AApplePickerGameState::HandleAppleMiss()
{
	DestroyExistingApples();
	RemoveBasket();
}

void AApplePickerGameState::DestroyExistingApples()
{
	TArray<AActor*> apples;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AApple::StaticClass(), apples);
	
	for (AActor* Apple : apples)
	{
		Apple->Destroy();
	}
}

void AApplePickerGameState::RemoveBasket()
{
	TArray<UStaticMeshComponent*>& meshesPtr = BasketPtr->BasketMeshesPtr;
	
	if (meshesPtr.IsEmpty())
		return;
	
	UStaticMeshComponent* topMeshPtr = meshesPtr.Last();
	
	topMeshPtr->DestroyComponent();
	meshesPtr.Remove(topMeshPtr);
}
