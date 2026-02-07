// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Basket.generated.h"

class AApplePickerGameState;

UCLASS()
class PLUSPICKER_API ABasket : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Basket | Setup") 
	TArray<UStaticMeshComponent*> BasketMeshesPtr;
	
	
	// Sets default values for this pawn's properties
	ABasket();
	
	void Move(FVector);

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Basket | Setup")
	AApplePickerGameState* ApplePickerGameStatePtr;
	
	UFUNCTION()
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void DestroyMesh(UStaticMeshComponent*);

};
