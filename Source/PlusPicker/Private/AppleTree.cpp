// Fill out your copyright notice in the Description page of Project Settings.


#include "AppleTree.h"

// Sets default values
AAppleTree::AAppleTree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAppleTree::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* world = GetWorld();
	
	FTimerHandle appleTimerHandle;
	world->GetTimerManager().SetTimer(
		appleTimerHandle,
		this,
		&AAppleTree::DropApple,
		AppleDropDelay,
		true,
		2
		);
	
	FTimerHandle rotationTimerHandle;
	world->GetTimerManager().SetTimer(
		rotationTimerHandle,
		this,
		&AAppleTree::TryRotateRandomly,
		RandomRotationCheckDelay,
		true
		);
	
}

// Called every frame
void AAppleTree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AAppleTree::TryRotateOnEdge()
{
	
};
void AAppleTree::TryRotateRandomly()
{
	UE_LOG(LogTemp, Log, TEXT("TryRotateRandomly"));
};

void AAppleTree::DropApple()
{
	UE_LOG(LogTemp, Log, TEXT("DropApple"));
}

