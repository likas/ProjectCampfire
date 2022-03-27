// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CampfireVRCharacter.h"
#include "Components/ActorComponent.h"
#include "FPSCharacterComponent.generated.h"


UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTCAMPFIRE_API UFPSCharacterComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	bool bEnableFPS = false;

	UPROPERTY()
	ACampfireVRCharacter* OwnerCharacter;

	UPROPERTY()
	UInputComponent* FPSInput;

public:	
	// Sets default values for this component's properties
	UFPSCharacterComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
