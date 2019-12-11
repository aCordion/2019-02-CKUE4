// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "ChaseBallActor.generated.h"
#include "GameFramework/ProjectileMovementComponent.h"

UCLASS()
class ARENABATTLE_API AChaseBallActor : public ACharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChaseBallActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USphereComponent *Sphere;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *Core;

	UPROPERTY(VisibleAnywhere)
	UPointLightComponent *Light;

	UPROPERTY(VisibleAnywhere)
	FVector DirectionToMove = FVector::ZeroVector;

	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* pjtileMovement;

	void FireInDirection(const FVector& dir);

};
