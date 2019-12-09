// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_RangedAttack.h"
#include "ABAIController.h"
#include "ABCharacter.h";

UBTTask_RangedAttack::UBTTask_RangedAttack() 
{
	bNotifyTick = true;
	IsAttacking = false;
}

EBTNodeResult::Type UBTTask_RangedAttack::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto ABCharacter = Cast<AABCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == ABCharacter) {
		return EBTNodeResult::Failed;
	}
	ABCharacter->Attack();	//원거리 공격 추가 필요(ABCharacter::RangedAttack());
	IsAttacking = true;
	ABCharacter->OnAttackEnd.AddLambda([this]()->void {IsAttacking = false; });

	return EBTNodeResult::InProgress;
}

void UBTTask_RangedAttack::TickTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	if (!IsAttacking) {
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}
