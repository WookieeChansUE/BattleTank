// Copyright Curiouser & Curiouser Games

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 *  TankTrack is used to set maximu driving force, and to apply forces to tank
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	//Sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	//Max force per track, IN NEWTONS
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000000.0; //assume 40ton tank and 1g accelleration

private:
	UTankTrack(); 

	TArray<class ASprungWheel*> GetWheels() const;
		
	void DriveTrack(float CurrentThrottle);

};

 
