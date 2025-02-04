// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include "../Actors/GeneratorActor.h"
#include "GeneratorClientComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGeneratorClientOnSwitchedSignature, bool, bIsOn);

class AGeneratorActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIRSTPROJ_API UGeneratorClientComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditInstanceOnly)
	AGeneratorActor* Generator;

	UPROPERTY(BlueprintAssignable)
	FGeneratorClientOnSwitchedSignature OnGeneratorClientSwitched;

	UFUNCTION()
	void OnGeneratorSwitched(bool bIsOn);
};
