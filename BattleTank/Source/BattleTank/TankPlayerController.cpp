// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControllerTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Not Possesing A Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Possesing A %s"), *(ControlledTank->GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"));
}


// Tick
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Aim towards crosshair function.
	AimTowardsCrosshair();
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Ticking"));
}
	
ATank* ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControllerTank()) { return; }

	// Get world location from lintrace through crosshair
	// If it hits landscape
		// Tell controlled tank to aim at this point	
}