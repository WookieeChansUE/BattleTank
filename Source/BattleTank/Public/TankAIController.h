// Copyright Curiouser & Curiouser Games

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	//how close ai get to player
	float AcceptanceRadius = 3000;
};
