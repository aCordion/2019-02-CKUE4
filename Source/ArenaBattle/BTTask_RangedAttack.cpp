// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_RangedAttack.h"
#include "ABAIController.h"
#include "ABCharacter.h"

#include "ChaseBallActor.h"
//#include "ChaseBallActor.generated.h"

#include "Engine/World.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_RangedAttack::UBTTask_RangedAttack() 
{
	bNotifyTick = true;
	IsAttacking = false;

	/*static ConstructorHelpers::FObjectFinder<UBlueprint> balls(TEXT("/Script/ArenaBattle.ChaseBallActor"));
	if (balls.Object) {
		cBall = (UClass*)balls.Object->GeneratedClass;
	}*/
	ChaseBallClass = AChaseBallActor::StaticClass();
}

EBTNodeResult::Type UBTTask_RangedAttack::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto ABCharacter = Cast<AABCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == ABCharacter) {
		return EBTNodeResult::Failed;
	}
	ABCharacter->RangedAttack();
	IsAttacking = true;
	ABCharacter->OnAttackEnd.AddLambda([this]()->void {IsAttacking = false; });
	//원거리 공격 카운트
	OwnerComp.GetBlackboardComponent()->SetValueAsInt("RangedAttackCounts", OwnerComp.GetBlackboardComponent()->GetValueAsInt("RangedAttackCounts") + 1);

	UPROPERTY()
	UWorld* World = GetWorld();
	if (World == nullptr) {
		return EBTNodeResult::Failed;
	}
	auto self = OwnerComp.GetAIOwner()->GetPawn();
	auto target = OwnerComp.GetBlackboardComponent()->GetValueAsObject("Target");
	//AChaseBallActor* Projectile = World->SpawnActor<AChaseBallActor>();

	/*FActorSpawnParameters sParams;
	sParams.Owner = OwnerComp.GetAIOwner()->GetOwner();
	FRotator rotater;
	FVector sLocation = sParams.Owner->GetActorLocation();

	World->SpawnActor<AActor>(cBall, sLocation, rotater, sParams);*/
	//self->GetActorTransform().TransformPosition()
	//auto Projectile = World->SpawnActor<AChaseBallActor>(ChaseBallClass, );
	//Projectile->AddMovementInput(target->GetWorld()->execTransformConst())


	return EBTNodeResult::InProgress;
}

void UBTTask_RangedAttack::TickTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	if (!IsAttacking) {
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}
