// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CampfireVRCharacter.h"

void ACampfireVRCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& LifetimeProperties) const
{
	Super::GetLifetimeReplicatedProps(LifetimeProperties);
}

void ACampfireVRCharacter::MoveForward(float AxisInput)
{
	AddMovementInput(GetVRForwardVector(), AxisInput);
}

void ACampfireVRCharacter::MoveRight(float AxisInput)
{
	AddMovementInput(GetVRRightVector(), AxisInput);
}

void ACampfireVRCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}
