// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyFirstActor.generated.h"

UCLASS()
class FIRSTPROJ_API AMyFirstActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyFirstActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SetRandomRotationSpeed();

	UPROPERTY(EditAnywhere)
	int MyFirstProperty = 100;

	UPROPERTY(EditAnywhere)
	FColor TextColor = FColor::Green;

	UPROPERTY(EditAnywhere)
	float MinRotationSpeed = 0.0f;
	UPROPERTY(EditAnywhere)
	float MaxRotationSpeed = 360.0f;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float CurrentRotarionSpeed=  0.0f;

};
