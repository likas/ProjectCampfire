// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FPSInputComponent.h"

UFPSInputComponent::UFPSInputComponent()
{
	UE_LOG(LogTemp, Log, TEXT("%s: Constructor has fired"), *GetName());
}

void UFPSInputComponent::Activate(bool bReset)
{
	Super::Activate(bReset);

	UE_LOG(LogTemp, Log, TEXT("%s: Component Activated"), *GetName());
}

