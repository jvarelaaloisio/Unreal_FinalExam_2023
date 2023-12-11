// Copyright Epic Games, Inc. All Rights Reserved.

#include "Unreal_Final_2023GameMode.h"
#include "Unreal_Final_2023Character.h"
#include "UObject/ConstructorHelpers.h"

AUnreal_Final_2023GameMode::AUnreal_Final_2023GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
