// Fill out your copyright notice in the Description page of Project Settings.


#include "ABFountainAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

AABFountainAIController::AABFountainAIController()
{
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("/Game/Book/AI/BB_ABFountain.BB_ABFountain"));
	if (BBObject.Succeeded()) {
		BBAsset = BBObject.Object;
	}

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("/Game/Book/AI/BT_ABFountain.BT_ABFountain"));
	if (BTObject.Succeeded()) {
		BTAsset = BTObject.Object;
	}
}

void AABFountainAIController::OnPossess(APawn * inPawn)
{
	Super::OnPossess(inPawn);

	if (UseBlackboard(BBAsset, Blackboard)) {
		Blackboard->SetValueAsFloat(FName("Radius"), 500.0f);

		if (!RunBehaviorTree(BTAsset)) {

			ABLOG(Error, TEXT("AIController couldn't run behavior tree!"));
		}
	}
}
