// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "AIController.h"
#include "ABFountainAIController.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABFountainAIController : public AAIController
{
	GENERATED_BODY()

public:
	AABFountainAIController();
	virtual void OnPossess(APawn* inPawn) override;

private:
	UPROPERTY()
		class UBehaviorTree* BTAsset;

	UPROPERTY()
		class UBlackboardData* BBAsset;
	
};
