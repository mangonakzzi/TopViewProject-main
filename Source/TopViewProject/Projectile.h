// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOPVIEWPROJECT_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UBoxComponent* Collision;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UProjectileMovementComponent* ProjectileMovementComponent;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneComponent;
	UPROPERTY(VisibleAnywhere)
	class UArrowComponent* Arrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed", meta = (ExposeOnSpawn = "true"))
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UParticleSystemComponent* Particle;

public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frameS
	virtual void Tick(float DeltaTime) override;

};
