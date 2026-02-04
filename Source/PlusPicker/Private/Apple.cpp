// Fill out your copyright notice in the Description page of Project Settings.


#include "Apple.h"

#include "ApplePickerGameMode.h"
#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AApple::AApple()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AApple::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AApple::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector appleLocation = AppleMeshComponentPtr->GetComponentLocation();
	
	if (appleLocation.Z < KillAreaZ)
	{
		Destroy();
		
		AGameModeBase* gameModePtr = UGameplayStatics::GetGameMode(this);
		AApplePickerGameMode* ApplePickerGameModePtr = Cast<AApplePickerGameMode>(gameModePtr);
		
		if (ApplePickerGameModePtr != nullptr)
		{
			ApplePickerGameModePtr->OnAppleDestroyed();
		}
	}

}

