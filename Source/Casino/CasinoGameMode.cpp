// Copyright Epic Games, Inc. All Rights Reserved.

#include "CasinoGameMode.h"
#include "CasinoCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACasinoGameMode::ACasinoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
