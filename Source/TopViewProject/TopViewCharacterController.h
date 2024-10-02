// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TopViewCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class TOPVIEWPROJECT_API ATopViewCharacterController : public APlayerController
{
	GENERATED_BODY()
	

public:
	ATopViewCharacterController();

public:
	virtual void BeginPlay() override;

public:
	void LookLeftRight(float Value);
	void LookUpDown(float Value);
	void MoveUpDown(float Value);
	void MoveLeftRight(float Value);

	void Jump();
};
