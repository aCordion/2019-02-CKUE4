// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ResetRgdAttackCounts.h"

#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTask_ResetRgdAttackCounts::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	//���Ÿ� ���� ī��Ʈ 0���� �ٲ�
	OwnerComp.GetBlackboardComponent()->SetValueAsInt("RangedAttackCounts", 0);

	return EBTNodeResult::Succeeded;
}