// Fill out your copyright notice in the Description page of Project Settings.


#include "AIController_ChaseBall.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

AAIController_ChaseBall::AAIController_ChaseBall()
{

	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("/Game/Book/AI/BB_ChaseBall.BB_ChaseBall"));
	if (BBObject.Succeeded()) {
		BBAsset = BBObject.Object;
	}

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("/Game/Book/AI/BT_ChaseBall.BT_ChaseBall"));
	if (BTObject.Succeeded()) {
		BTAsset = BTObject.Object;
	}
}

void AAIController_ChaseBall::OnPossess(APawn * inPawn)
{
	Super::OnPossess(inPawn);

	if (UseBlackboard(BBAsset, Blackboard)) {

		if (!RunBehaviorTree(BTAsset)) {

			ABLOG(Error, TEXT("AIController couldn't run behavior tree!"));
		}
	}
}
