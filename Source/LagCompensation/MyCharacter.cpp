// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"
// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it. 
	PrimaryActorTick.bCanEverTick = true;

}


void AMyCharacter::AddPositionToHistory()
{
if (MHTime.Num() == NULL)

		if (MHTime.Num() >= 100)
		{
			ClearLastHistory();
		}
		MHTime.Add(GetWorld()->GetTimeSeconds());
		MHLocation.Add(GetMesh()->GetSocketLocation("pelvis"));
		LastActorLocation = GetActorLocation();

		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("My Location is: %s | Time is: %f"), *GetActorLocation().ToString(), GetWorld()->GetTimeSeconds()));

}

void AMyCharacter::ClearLastHistory()
{
		MHTime.RemoveAt(0);
		MHLocation.RemoveAt(0);
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddPositionToHistory();

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyCharacter::CheckHit(FVector HitLocation, float HitTime, bool& Success, float& Distance, float& BetweenTime, FVector& LocationInHistory, float& TimeInHistory)
{
	for (int i = 0; i < MHTime.Num(); i++)
	{
		if (MHTime[i] - HitTime <= AccessTime)
		{
			if (HitLocation.Distance(MHLocation[i], HitLocation) <= AccessDistance)
			{
				Success = true;
				Distance = HitLocation.Distance(MHLocation[i], HitLocation);
				BetweenTime = MHTime[i] - HitTime;
				TimeInHistory = MHTime[i];
				LocationInHistory = MHLocation[i];
			}

		}
	}
}
