// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CampfireVRCharacter.h"

void ACampfireVRCharacter::MoveForward(float AxisInput)
{
	AddMovementInput(GetVRForwardVector(), AxisInput);
}

void ACampfireVRCharacter::MoveRight(float AxisInput)
{
	AddMovementInput(GetVRRightVector(), AxisInput);
}
