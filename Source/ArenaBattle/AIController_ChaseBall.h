// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "AIController.h"
#include "AIController_ChaseBall.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AAIController_ChaseBall : public AAIController
{
	GENERATED_BODY()
	
public:
	AAIController_ChaseBall();
	virtual void OnPossess(APawn* inPawn) override;

private:

	UPROPERTY()
		class UBehaviorTree* BTAsset;

	UPROPERTY()
		class UBlackboardData* BBAsset;
};
