// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), hidecategories = ("Collision") )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	

public:
	//-1 max down +1 max up movement
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = BarrelSetup)
	float MaxDegreesPerSecond = 8.75;
	
	UPROPERTY(EditDefaultsOnly, Category = BarrelSetup)
	float MaxElevationDegrees = 40;
	
	UPROPERTY(EditDefaultsOnly, Category = BarrelSetup)
	float MinElevationDegrees = 0;
	
};
