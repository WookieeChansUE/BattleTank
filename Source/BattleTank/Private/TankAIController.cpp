// Copyright Curiouser & Curiouser Games

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "Classes/AIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}
// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank))
	{
		//move towards player
		MoveToActor(PlayerTank, AcceptanceRadius); //todo check radius is in cm

		//aim at player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
		ControlledTank->Fire();//todo dont fire every frame, limit fire rate
	}
}

