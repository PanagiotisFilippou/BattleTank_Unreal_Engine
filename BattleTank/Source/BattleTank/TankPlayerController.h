// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControllerTank() const;

	 virtual void BeginPlay() override;

	 virtual void Tick(float DeltaTime) override;

	 // Start moving the barrel to your target through the crosshair
	 void AimTowardsCrosshair();
	
	 // Return an OUT parameter, true if hit landscape
	 bool GetSightRayHitLocation(FVector& HitLocation) const;
	
};
