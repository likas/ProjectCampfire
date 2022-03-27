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


public:
	
	UFUNCTION()
	void MoveForward(float AxisInput);

	UFUNCTION()
	void MoveRight(float AxisInput);
	
};
