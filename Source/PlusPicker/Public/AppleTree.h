// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AppleTree.generated.h"

UCLASS()
class PLUSPICKER_API AAppleTree : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAppleTree();

protected:
	UPROPERTY(BlueprintReadWrite, Category="AppleTree")
	float MovementVector = 600;
	
	UPROPERTY(BlueprintReadWrite, Category="AppleTree")
	float LeftAndRightEdge = 700;
	
	UPROPERTY(BlueprintReadWrite, Category="AppleTree")
	float ChanceToChangeDirection = 0.02;
	
	UPROPERTY(BlueprintReadWrite, Category="AppleTree")
	float AppleDropDelay = 0.6;
	
	UPROPERTY(BlueprintReadWrite, Category="AppleTree")
	float RandomRotationCheckDelay = 0.02;
	
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	
	
	void TryRotateOnEdge();
	void TryRotateRandomly();
	void DropApple();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
