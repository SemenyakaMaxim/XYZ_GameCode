// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneratorClientComponent.h"
#include "../Actors/GeneratorActor.h"

// Called when the game starts
void UGeneratorClientComponent::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(Generator))
	{
		Generator->OnGeneratorSwitched.AddUObject(this, &UGeneratorClientComponent::OnGeneratorSwitched);
	}
}

void UGeneratorClientComponent::OnGeneratorSwitched(bool bIsOn)
{
	FString OnOffString = bIsOn ? TEXT("ON") : TEXT("OFF");
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green,
		FString::Printf(TEXT("UGeneratorClientComponent::OnGeneratorSwitched for %s generator is %s"),
			*GetOwner()->GetName(), *OnOffString));

	if (OnGeneratorClientSwitched.IsBound())
	{
		OnGeneratorClientSwitched.Broadcast(bIsOn);
	}
}
