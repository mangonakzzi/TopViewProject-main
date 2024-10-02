// Fill out your copyright notice in the Description page of Project Settings.


#include "TopViewCharacterController.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

ATopViewCharacterController::ATopViewCharacterController()
{
}

void ATopViewCharacterController::BeginPlay()
{
	Super::BeginPlay();

}

void ATopViewCharacterController::LookLeftRight(float Value)
{
	APawn* Controller = GetPawn();
	if (Controller)
	{
		Controller->AddControllerYawInput(Value);
	}

}

void ATopViewCharacterController::LookUpDown(float Value)
{
	APawn* Controller = GetPawn();
	if (Controller)
	{
		Controller->AddControllerPitchInput(Value);
	}

}

void ATopViewCharacterController::MoveUpDown(float Value)
{
	APawn* Controller = GetPawn();
	if (Controller && Value != 0.0f)
	{
		const FRotator Rotation = Controller->GetActorRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		Controller->AddMovementInput(Direction, Value);

	}

}

void ATopViewCharacterController::MoveLeftRight(float Value)
{
	APawn* Controller = GetPawn();
	if (Controller && Value != 0.0f)
	{
		const FRotator Rotation = Controller->GetActorRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		Controller->AddMovementInput(Direction, Value);

	}

}

void ATopViewCharacterController::Jump()
{
	ACharacter* Controller = Cast<ACharacter>(GetPawn());
	if (Controller)
	{
		Controller->Jump();

	}

}
