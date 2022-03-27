// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FPSCharacterComponent.h"

// Sets default values for this component's properties
UFPSCharacterComponent::UFPSCharacterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFPSCharacterComponent::BeginPlay()
{
	Super::BeginPlay();

	//TODO Move to function
	if(!bEnableFPS) return;
	
	OwnerCharacter = Cast<ACampfireVRCharacter>(GetOwner());
	if(!IsValid(OwnerCharacter)) return;
	TArray<UReplicatedVRCameraComponent*> VRCameraComponents;
	TArray<UGripMotionControllerComponent*> GripControllers;
	TArray<UVRCharacterMovementComponent*> MovementComponents;

	OwnerCharacter->GetComponents(VRCameraComponents, false);
	OwnerCharacter->GetComponents(GripControllers, false);
	OwnerCharacter->GetComponents(MovementComponents, false);

	if(VRCameraComponents.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("No VR Camera found by FPS Char Component"))
		return;
	}
	
	if(VRCameraComponents.Num() > 1)
	{
		UE_LOG(LogTemp, Warning, TEXT("More than one Camera found by FPS Char Component, using the first one:"))
		for (auto CameraComponent : VRCameraComponents)
		{
			UE_LOG(LogTemp, Warning, TEXT("		%s"), *CameraComponent->GetName());
		}
	}

	if(GripControllers.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("No Grip ontrollers found by FPS Char Component"))
		return;
	}

	if(GripControllers.Num() != 2)
	{
		UE_LOG(LogTemp, Warning, TEXT("Incorrect number of controllers found by FPS Char Component (%d instead of \
			2):"), GripControllers.Num());
		for (auto GripController : GripControllers)
		{
			UE_LOG(LogTemp, Warning, TEXT("		%s"), *GripController->GetName());
		}
	}

	if(MovementComponents.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("No VR Movement Component found by FPS Char Component"))
		return;
	}
	
	if(MovementComponents.Num() > 1)
	{
		UE_LOG(LogTemp, Warning, TEXT("More than one Movement Component found by FPS Char Component, using the first one:"))
		for (auto MovementComponent : MovementComponents)
		{
			UE_LOG(LogTemp, Warning, TEXT("		%s"), *MovementComponent->GetName());
		}
	}
		
	if(VRCameraComponents.IsEmpty() || GripControllers.Num() < 2) return;

	FAttachmentTransformRules AttachmentRules = FAttachmentTransformRules::KeepRelativeTransform;
	AttachmentRules.bWeldSimulatedBodies = true;

	for (auto Controller : GripControllers)
	{
		Controller->AttachToComponent(VRCameraComponents[0], AttachmentRules);
		Controller->RemoveTickPrerequisiteComponent(VRCameraComponents[0]);
		if(Controller->MotionSource == "Right")
		{
			Controller->SetRelativeLocation(FVector(30.f, 20.f, 0.f));
		}
		else if(Controller->MotionSource == "Left")
		{
			Controller->SetRelativeLocation(FVector(30.f, -20.f, 0.f));
		}
	}

	VRCameraComponents[0]->bUsePawnControlRotation = true;
	VRCameraComponents[0]->AddRelativeLocation(FVector(0.f, 0.f, 120.f));

	MovementComponents[0]->bUseClientControlRotation = true;

	//Create InputComponent

	FPSInput = NewObject<UInputComponent>(this);

	//Re-bind input settings:

	APlayerController* OwnerPC = Cast<APlayerController>(OwnerCharacter->GetController());
	if(!IsValid(OwnerPC)) return;
	
	FPSInput->BindAction("Jump", IE_Pressed, OwnerCharacter, &ACharacter::Jump);
	FPSInput->BindAction("Jump", IE_Released, OwnerCharacter, &ACharacter::StopJumping);
	
	FPSInput->BindAxis("MoveForward", OwnerCharacter, &ACampfireVRCharacter::MoveForward);
	FPSInput->BindAxis("MoveRight", OwnerCharacter, &ACampfireVRCharacter::MoveRight);
	FPSInput->BindAxis("LookUp", OwnerCharacter, &APawn::AddControllerPitchInput);
	FPSInput->BindAxis("Turn", OwnerCharacter, &APawn::AddControllerYawInput);
	
	OwnerPC->PushInputComponent(FPSInput);
	
}


// Called every frame
void UFPSCharacterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

