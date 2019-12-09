// Fill out your copyright notice in the Description page of Project Settings.


#include "AIFountain.h"

// Sets default values
AAIFountain::AAIFountain()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAIFountain::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAIFountain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAIFountain::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

