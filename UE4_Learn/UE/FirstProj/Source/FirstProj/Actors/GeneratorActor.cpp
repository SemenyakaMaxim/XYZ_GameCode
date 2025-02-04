// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneratorActor.h"

void AGeneratorActor::SwitchGenerator()
{


	if (OnGeneratorSwitched.IsBound())
	{
		bIsOn = !bIsOn;
		OnGeneratorSwitched.Broadcast(bIsOn);
	}
}

float AGeneratorActor::GetCooldownFromRate(float InRotationRate) const
{
	float Result = .0f;
	if (IsValid(CooldownCurve))
	{
		Result = CooldownCurve->GetFloatValue(InRotationRate);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta,
			FString::Printf(TEXT("AGeneratorActor::GetCooldownFromRate. Rate: %f, cooldown %f")
				, InRotationRate, Result));
	}
	return Result;
}
