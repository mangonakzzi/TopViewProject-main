// Fill out your copyright notice in the Description page of Project Settings.


#include "TopViewCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "TopViewCharacterController.h"

// Sets default values
ATopViewCharacter::ATopViewCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonMuriel/Characters/Heroes/Muriel/Meshes/Muriel_GDC.Muriel_GDC'"));

	if (SkeletalMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SkeletalMesh.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -90.f), FRotator(0.f, -90.f, 0.f));
	}

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Main Camera"));
	Spring = CreateDefaultSubobject<USpringArmComponent>(TEXT("SparingArm"));

	Spring->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(Spring);

	Spring->TargetArmLength = 1000;	
	Spring->SetRelativeLocation(FVector(0.f, 0.f, 90.f));

	Camera->SetWorldRotation(FRotator(0.f, 0.f, 0.f));
	Camera->bUsePawnControlRotation = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	Scene->SetupAttachment(GetCapsuleComponent());
	Scene->SetRelativeLocation(FVector(50.f, 0.f, 0.f));

	SceneSpring = CreateDefaultSubobject<USpringArmComponent>(TEXT("SceneSpring"));
	SceneSpring->SetupAttachment(GetCapsuleComponent());	
	SceneSpring->SetRelativeRotation(FRotator(-90.f, 0.f, 0.f));
	SceneSpring->TargetArmLength = 500;
	SceneSpring->bInheritPitch = false;
	SceneSpring->bInheritRoll = false;
	SceneSpring->bInheritYaw = false;

	SceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCapture"));
	SceneCapture->SetupAttachment(SceneSpring);

}

// Called when the game starts or when spawned
void ATopViewCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	

}

// Called every frame
void ATopViewCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATopViewCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("LookLeftRight"), this, &ATopViewCharacter::LookLeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookUpDown"), this, &ATopViewCharacter::LookUpDown);
	PlayerInputComponent->BindAxis(TEXT("MoveUpDown"), this, &ATopViewCharacter::MoveUpDown);
	PlayerInputComponent->BindAxis(TEXT("MoveLeftRight"), this, &ATopViewCharacter::MoveLeftRight);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ATopViewCharacter::Jump);
}
void ATopViewCharacter::LookLeftRight(float Value)
{
	ATopViewCharacterController* LookLeftRightController = Cast<ATopViewCharacterController>(GetController());
	if (Controller)
	{
		LookLeftRightController->LookLeftRight(Value);
	}

}
void ATopViewCharacter::LookUpDown(float Value)
{
	ATopViewCharacterController* LookUpDownController = Cast<ATopViewCharacterController>(GetController());
	if (Controller)
	{
		LookUpDownController->LookUpDown(Value);
	}

}

void ATopViewCharacter::MoveUpDown(float Value)
{
	ATopViewCharacterController* MoveUpDownController = Cast<ATopViewCharacterController>(GetController());
	if (Controller)
	{
		MoveUpDownController->MoveUpDown(Value);
	}

}

void ATopViewCharacter::MoveLeftRight(float Value)
{
	ATopViewCharacterController* MoveLeftRightController = Cast<ATopViewCharacterController>(GetController());
	if (Controller)
	{
		MoveLeftRightController->MoveLeftRight(Value);
	}

}
