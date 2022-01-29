// Copyright Epic Games, Inc. All Rights Reserved.

#include "XGameMode.h"
#include "Characters/XCharacter.h"
#include "Characters/Player/XPlayerController.h"
#include "UObject/ConstructorHelpers.h"

AXGameMode::AXGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AXPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/MyData/Characters/Player/PlayerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}