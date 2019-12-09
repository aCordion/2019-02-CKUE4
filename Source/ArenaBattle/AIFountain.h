// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "AIFountain.generated.h"

UCLASS()
class ARENABATTLE_API AAIFountain : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAIFountain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
