// Fill out your copyright notice in the Description page of Project Settings.


#include "Basket.h"

// Sets default values
ABasket::ABasket()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasket::BeginPlay()
{
	Super::BeginPlay();
	// TODO: GameState
}

// Called every frame
void ABasket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasket::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABasket::Move(FVector newPosition)
{
	SetActorLocation(newPosition);
}

void ABasket::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	OtherActor->Destroy();
	// update game score;
}

void ABasket::DestroyMesh(UStaticMeshComponent* MeshPtr)
{
	MeshPtr->DestroyComponent();
}
