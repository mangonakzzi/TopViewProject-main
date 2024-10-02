// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/ArrowComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<UBoxComponent>(FName("Collison Mesh"));
	Collision->SetRelativeScale3D(FVector(1.5f, 1.5f, 1.5f));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("None"));

	Mesh->SetStaticMesh(StaticMesh.Object);
	Mesh->SetRelativeScale3D(FVector(0.25f, 0.25f, 0.25f));
	Mesh->SetupAttachment(Collision);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(SceneComponent);
	ProjectileMovementComponent->InitialSpeed = 500.f;
	ProjectileMovementComponent->MaxSpeed = 500.f;
	ProjectileMovementComponent->ProjectileGravityScale = 0;

	Arrow = CreateDefaultSubobject<UArrowComponent>(FName("Arrow"));
	Arrow->SetupAttachment(Collision);
	Arrow->SetRelativeLocation(FVector(60.f, 0.f, 0.f));

	Particle = CreateDefaultSubobject<UParticleSystemComponent>(FName("Particle"));
	Particle->SetupAttachment(Mesh);
	Particle->SetRelativeScale3D(FVector(1.f, 1.f, 1.f));
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}