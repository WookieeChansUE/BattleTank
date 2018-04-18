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
	
protected:
	//how close ai get to player
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float AcceptanceRadius = 7000.0;

private:
	void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

};
