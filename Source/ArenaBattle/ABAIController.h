// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "AIController.h"
#include "ABAIController.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABAIController : public AAIController
{
	GENERATED_BODY()

public:
	AABAIController();
	virtual void OnPossess(APawn* inPawn) override;
	//virtual void OnUnPossess() override;

	/*static const FName StartPosKey;
	static const FName DestPosKey;*/

private:
	/*void OnRepeatTimer();

	FTimerHandle RepeatTimerHandle;
	float RepeatInterval;*/

	UPROPERTY()
	class UBehaviorTree* BTAsset;

	UPROPERTY()
	class UBlackboardData* BBAsset;

};
