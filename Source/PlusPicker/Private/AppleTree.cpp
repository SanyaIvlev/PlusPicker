// Fill out your copyright notice in the Description page of Project Settings.


#include "AppleTree.h"
#include "Apple.h"

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
	
	
	_world = GetWorld();
	_spawnParameters = new FActorSpawnParameters();
	
	FTimerHandle appleTimerHandle;
	_world->GetTimerManager().SetTimer(
		appleTimerHandle,
		this,
		&AAppleTree::DropApple,
		AppleDropDelay,
		true,
		2
		);
	
	FTimerHandle rotationTimerHandle;
	_world->GetTimerManager().SetTimer(
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
	FTransform actorTransform = GetActorTransform();
	
	_world->SpawnActor<AApple>(AppleClassToSpawn, actorTransform.GetLocation(), actorTransform.GetRotation().Rotator(), FActorSpawnParameters());
	
	UE_LOG(LogTemp, Log, TEXT("DropApple"));
}

