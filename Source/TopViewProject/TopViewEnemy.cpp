// Fill out your copyright notice in the Description page of Project Settings.


#include "TopViewEnemy.h"

// Sets default values
ATopViewEnemy::ATopViewEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/SKnight_modular/Skeleton/mesh/SK_Skeleton_base.SK_Skeleton_base'"));

	if (SkeletalMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SkeletalMesh.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -90.f), FRotator(0.f, -90.f, 0.f));
	}

}

// Called when the game starts or when spawned
void ATopViewEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATopViewEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATopViewEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

