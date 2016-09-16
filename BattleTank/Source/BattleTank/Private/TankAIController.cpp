// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto AITargetTank = GetPlayerTank();
	if (!AITargetTank) {
		UE_LOG(LogTemp,Warning,TEXT("tank couldn't find target"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("tank found player %s"),*AITargetTank->GetName())
	}
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
