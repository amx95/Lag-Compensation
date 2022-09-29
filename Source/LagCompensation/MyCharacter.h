// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class LAGCOMPENSATION_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

	FVector LastActorLocation;

	UPROPERTY(EditAnywhere)
	float AccessDistance = 10.0f;

	UPROPERTY(EditAnywhere)
	float AccessTime = 1.0f;

	UPROPERTY(EditAnywhere)
	TArray<float> MHTime;

	UPROPERTY(EditAnywhere)
	TArray<FVector> MHLocation;


	virtual void AddPositionToHistory();

	virtual void ClearLastHistory();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	virtual void CheckHit(FVector HitLocation, float HitTime, bool& Success, float& Distance, float& BetweenTime, FVector& LocationInHistory, float& TimeInHistory);

};
