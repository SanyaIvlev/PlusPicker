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
	
	srand(time(0));
	
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
	Move(DeltaTime);
	TryRotateOnEdge();

}
void AAppleTree::TryRotateOnEdge()
{
	FVector actorLocation = GetActorLocation();
	
	if (actorLocation.X < -LeftAndRightEdge)
	{
		MovementVector = abs(MovementVector);
	}
	else
	{
		if (actorLocation.X > LeftAndRightEdge)
		{
			MovementVector = -abs(MovementVector);
		}
	}
	
};
void AAppleTree::TryRotateRandomly()
{
	int randomNumber = rand() % 100;
	
	if (randomNumber < ChanceToChangeDirection)
	{
		MovementVector = -MovementVector;	
	}

	UE_LOG(LogTemp, Log, TEXT("TryRotateRandomly"));
};

void AAppleTree::DropApple() const
{
	FTransform actorTransform = GetActorTransform();
	
	_world->SpawnActor<AApple>(AppleClassToSpawn, actorTransform.GetLocation(), actorTransform.GetRotation().Rotator(), FActorSpawnParameters());
	
	UE_LOG(LogTemp, Log, TEXT("DropApple"));
}

void AAppleTree::Move(float deltaSeconds)
{
	FVector actorLocation = GetActorLocation();
	
	float xLocation = actorLocation.X + MovementVector * deltaSeconds;
	
	SetActorLocation(FVector(xLocation, actorLocation.Y, actorLocation.Z));
}

