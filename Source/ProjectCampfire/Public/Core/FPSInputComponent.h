// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "FPSInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTCAMPFIRE_API UFPSInputComponent : public UInputComponent
{
	GENERATED_BODY()

	UFPSInputComponent();

	virtual void Activate(bool bReset) override;
	
};
