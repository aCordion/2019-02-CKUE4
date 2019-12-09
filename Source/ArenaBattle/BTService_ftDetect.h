// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "BehaviorTree/BTService.h"
#include "BTService_ftDetect.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UBTService_ftDetect : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_ftDetect();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
