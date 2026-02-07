// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AppleTree.generated.h"

class AApple;

UCLASS()
class PLUSPICKER_API AAppleTree : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAppleTree();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AppleTree | Setup")
	TSubclassOf<AApple> AppleClassToSpawn;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AppleTree | Movement")
	float MovementVector = 600;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AppleTree | Movement")
	float LeftAndRightEdge = 700;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AppleTree | Movement")
	float ChanceToChangeDirection = 0.02;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AppleTree | Movement")
	float RandomRotationCheckDelay = 0.02;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AppleTree | Apple Drop")
	float AppleDropDelay = 0.6;
	
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	UPROPERTY()
	UWorld* _worldPtr;
	
	void TryRotateOnEdge();
	void TryRotateRandomly();
	void DropApple() const;
	void Move(float);
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
