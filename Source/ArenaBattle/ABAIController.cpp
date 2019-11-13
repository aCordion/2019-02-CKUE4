// Fill out your copyright notice in the Description page of Project Settings.


#include "ABAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
//#include "NavigationSystem.h"
//#include "Blueprint/AIBlueprintHelperLibrary.h"

//const FName AABAIController::StartPosKey(TEXT("StartPosition"));
//const FName AABAIController::DestPosKey(TEXT("DestPosition"));

AABAIController::AABAIController() {
	//RepeatInterval = 3.0f;

	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("/Game/Book/AI/BB_ABCharacter.BB_ABCharacter"));
	if (BBObject.Succeeded()) {
		BBAsset = BBObject.Object;
	}

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("/Game/Book/AI/BT_ABCharacter.BT_ABCharacter"));
	if (BTObject.Succeeded()) {
		BTAsset = BTObject.Object;
	}
}

void AABAIController::OnPossess(APawn* InPawn) {
	Super::OnPossess(InPawn);
	//GetWorld()->GetTimerManager().SetTimer(RepeatTimerHandle, this, &AABAIController::OnRepeatTimer, RepeatInterval, true);

	if (UseBlackboard(BBAsset, Blackboard)) {
		Blackboard->SetValueAsFloat(FName("Timer"), 5.0f);
		Blackboard->SetValueAsFloat(FName("Radius"), 500.0f);
		Blackboard->SetValueAsVector(FName("StartPosition"), GetPawn()->GetActorLocation());

		//Blackboard->SetValueAsVector(StartPosKey, InPawn->GetActorLocation());

		if (!RunBehaviorTree(BTAsset)) {

			ABLOG(Error, TEXT("AIController couldn't run behavior tree!"));
		}
	}
}

//void AABAIController::OnUnPossess() {
//	Super::OnUnPossess();
//	//GetWorld()->GetTimerManager().ClearTimer(RepeatTimerHandle);
//}

//void AABAIController::OnRepeatTimer() {
//	auto CurrentPawn = GetPawn();
//	ABCHECK(nullptr != CurrentPawn);
//
//	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
//	if (nullptr == NavSystem) return;
//
//	FNavLocation NextLocation;
//	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.0f, NextLocation)) {
//		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, NextLocation.Location);
//		//UNavigationSystemV1::SimpleMoveToLocation(this, NextLocation.Location);
//		ABLOG(Warning, TEXT("Next Location : %s"), *NextLocation.Location.ToString());;
//	}
//}