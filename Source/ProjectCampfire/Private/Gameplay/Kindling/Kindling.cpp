// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Kindling/Kindling.h"

// Sets default values
AKindling::AKindling()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKindling::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKindling::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

