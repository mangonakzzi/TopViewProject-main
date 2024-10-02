// Fill out your copyright notice in the Description page of Project Settings.


#include "TopViewAnimInstance.h"
#include "TopViewCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UTopViewAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

}

void UTopViewAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	auto Pawn = TryGetPawnOwner();

	if (IsValid(Pawn))
	{
		Character = Cast<ATopViewCharacter>(Pawn);

		if (IsValid(Character))
		{
			CharacterMovement = Character->GetCharacterMovement();
			CharacterMovement->bOrientRotationToMovement = true;
		}

	}

}

void UTopViewAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (IsValid(Character))
	{
		Velocity = CharacterMovement->Velocity;
		Speed = Velocity.Size2D();

		auto Acceleration = CharacterMovement->GetCurrentAcceleration();
		ShouldMove = Speed > 3.f && Acceleration != FVector::Zero();
		IsFalling = CharacterMovement->IsFalling();

		FRotator Rotation = Character->GetActorRotation();
		FVector UnRotateVector = Rotation.UnrotateVector(Velocity);
		Vertical = UnRotateVector.X;
		Horizontal = UnRotateVector.Y;

		Rotator = Character->GetBaseAimRotation();
		FRotator VelocityRotation = UKismetMathLibrary::MakeRotFromX(Velocity);

		FRotator DeltaRotation = VelocityRotation - Rotator;
		DeltaRotation.Normalize();

		YawOffset = DeltaRotation.Yaw;
	}


}
