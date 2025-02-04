// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstActor.h"

// Sets default values
AMyFirstActor::AMyFirstActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyFirstActor::BeginPlay()
{
	Super::BeginPlay();
	SetRandomRotationSpeed();
}

// Called every frame
void AMyFirstActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator Rotator = GetActorRotation();
	Rotator.Yaw += CurrentRotarionSpeed * DeltaTime;
	SetActorRotation(Rotator);
}

void AMyFirstActor::SetRandomRotationSpeed()
{
	CurrentRotarionSpeed = FMath::RandRange(MinRotationSpeed, MaxRotationSpeed);
	GEngine->AddOnScreenDebugMessage(-1, 5, TextColor, FString::Printf(TEXT("Init rotation speed %f"), CurrentRotarionSpeed));
}

