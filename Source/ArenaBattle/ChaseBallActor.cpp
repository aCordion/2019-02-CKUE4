// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaseBallActor.h"
#include "DrawDebugHelpers.h"
#include "AIController_ChaseBall.h"

// Sets default values
AChaseBallActor::AChaseBallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->InitSphereRadius(10.0f);
	GetCapsuleComponent()->InitCapsuleSize(10.0f, 10.0f);
	Core = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Core"));
	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	RootComponent = GetCapsuleComponent();

	Sphere->SetupAttachment(RootComponent);
	Core->SetupAttachment(Sphere);
	Light->SetupAttachment(Core);

	Light->SetRelativeLocation(FVector::ZeroVector);

	//GetCapsuleComponent()->SetRelativeLocation(FVector::ZeroVector);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Core(TEXT("/Game/ChaseBall/Sphere.Sphere"));

	if (SM_Core.Succeeded()) {
		Core->SetStaticMesh(SM_Core.Object);
	}


	pjtileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("pjtileMovement"));
	pjtileMovement->SetUpdatedComponent(Sphere);
	pjtileMovement->InitialSpeed = 300.0f;
	pjtileMovement->MaxSpeed = 500.0f;
	pjtileMovement->bRotationFollowsVelocity = true;
	pjtileMovement->bShouldBounce = false;


	AIControllerClass = AAIController_ChaseBall::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;


}

// Called when the game starts or when spawned
void AChaseBallActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (DirectionToMove.SizeSquared() > 0.0f) {
		GetController()->SetControlRotation(FRotationMatrix::MakeFromX(DirectionToMove).Rotator());
		AddMovementInput(DirectionToMove);
	}
}

// Called every frame
void AChaseBallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChaseBallActor::FireInDirection(const FVector & dir)
{
	pjtileMovement->Velocity = dir * pjtileMovement->InitialSpeed;
}


