// Copyright Curiouser & Curiouser Games

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "Components/SceneComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "TankMovementComponent.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Dildo: Tank C++ Construct"), *TankName)
}
void ATank::BeginPlay()
{
	//NEEDED FOR BP BEGIN PLAY TO RUN!!!
	Super::BeginPlay();
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Dildo: Tank C++ Begin play"), *TankName)
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);

}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (isReloaded) 
	{
	//spawn projectile at socket location on barrel
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
		);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
