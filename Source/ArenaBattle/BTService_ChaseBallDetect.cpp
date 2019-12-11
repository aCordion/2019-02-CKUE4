// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_ChaseBallDetect.h"
#include "ABAIController.h"
#include "ABCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

UBTService_ChaseBallDetect::UBTService_ChaseBallDetect() {
	NodeName = TEXT("cbDetect");
	Interval = 1.0f;
}

void UBTService_ChaseBallDetect::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	auto CurPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == CurPawn) { return; }
	auto Center = CurPawn->GetActorLocation();
	auto World = CurPawn->GetWorld();
	float DetectRadius = 300.0f;	//Å½Áö ¹üÀ§ 300cm

	if (nullptr == World) return;
	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, CurPawn);
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(DetectRadius),
		CollisionQueryParam
	);

	if (bResult) {
		for (auto OverlapResult : OverlapResults) {
			AABCharacter* ABCharacter = Cast<AABCharacter>(OverlapResult.GetActor());
			if (ABCharacter && ABCharacter->GetController()->IsPlayerController())
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), ABCharacter);
				DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Yellow, false, 0.2f);
				DrawDebugPoint(World, ABCharacter->GetActorLocation(), 10.0f, FColor::Blue, false, 0.2f);
				DrawDebugLine(World, CurPawn->GetActorLocation(), ABCharacter->GetActorLocation(), FColor::Red, false, 0.2f);
				return;
			}
		}
	}
	else {
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), nullptr);
	}

	DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Red, false, 0.2f);

}
