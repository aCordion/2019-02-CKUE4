// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_SelfDestruct.h"
#include "ABAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_SelfDestruct::UBTTask_SelfDestruct() {

}

EBTNodeResult::Type UBTTask_SelfDestruct::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{

	auto curPawn = OwnerComp.GetAIOwner()->GetPawn();

	curPawn->Destroy();
	return EBTNodeResult::Succeeded;
}
