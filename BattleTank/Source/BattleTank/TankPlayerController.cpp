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
								///UE_LOG(LogTemp, Warning, TEXT("Player Controller Ticking"));
}
	
ATank* ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControllerTank()) { return; }

	
	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation)) // Is going to line trace

	UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());

	// If it hits landscape
		// TODO Tell controlled tank to aim at this point	
}

// Get world location from lintrace through crosshair, true if it hits somewhere
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair possition
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());
	// De-project the screen position of the crosshair to a world direction
	// Line-trace along that look direction, and see what we hit (upt to max range)
	return true;
}