// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_IsInRAttackRange.h"
#include "ABAIController.h"
#include "ABCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_IsInRAttackRange::UBTDecorator_IsInRAttackRange() {
	NodeName = TEXT("CanRangedAttack");
}

bool UBTDecorator_IsInRAttackRange::CalculateRawConditionValue(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto cPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == cPawn) {
		return false;
	}

	auto Target = Cast<AABCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("Target"));
	if (nullptr == Target) {
		return false;
	}

	bResult = (Target->GetDistanceTo(cPawn) > 200.0f && Target->GetDistanceTo(cPawn) <= 600.0f);

	return bResult;
}
