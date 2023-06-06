// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRCharacter.h"
#include "CampfireVRCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTCAMPFIRE_API ACampfireVRCharacter : public AVRCharacter
{
	GENERATED_BODY()

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>&) const override;

	virtual void PossessedBy(AController* NewController) override;

public:
	
	UFUNCTION()
	void MoveForward(float AxisInput);

	UFUNCTION()
	void MoveRight(float AxisInput);

};
