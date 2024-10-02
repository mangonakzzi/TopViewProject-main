// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TopViewCharacter.generated.h"


UCLASS()
class TOPVIEWPROJECT_API ATopViewCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATopViewCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USpringArmComponent* Spring;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USpringArmComponent* SceneSpring;
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere)
	class USceneCaptureComponent2D* SceneCapture;

public:
	void LookLeftRight(float Value);
	void LookUpDown(float Value);
	void MoveUpDown(float Value);
	void MoveLeftRight(float Value);

};