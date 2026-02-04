// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Basket.generated.h"

UCLASS()
class PLUSPICKER_API ABasket : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasket();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Basket") 
	TArray<UStaticMeshComponent*> BasketMeshesPtr;
	
	// UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Basket") 
	// UBoxComponent* BasketCollisionPtr;
	
	UFUNCTION()
	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void Move(FVector);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void DestroyMesh(UStaticMeshComponent*);

};
