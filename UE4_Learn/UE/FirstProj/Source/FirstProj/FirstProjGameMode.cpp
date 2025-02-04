// Copyright Epic Games, Inc. All Rights Reserved.

#include "FirstProjGameMode.h"
#include "FirstProjCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFirstProjGameMode::AFirstProjGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
