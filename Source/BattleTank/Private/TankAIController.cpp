// Copyright Curiouser & Curiouser Games

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "Classes/AIController.h"
// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}
// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	//move towards player
	MoveToActor(PlayerTank, AcceptanceRadius); //todo check radius is in cm

	//aim at player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
		
	//todo fix firing
	//ControlledTank->Fire();//todo dont fire every frame, limit fire rate
}

