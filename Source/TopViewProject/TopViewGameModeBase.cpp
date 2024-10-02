// Fill out your copyright notice in the Description page of Project Settings.


#include "TopViewGameModeBase.h"
#include "TopViewCharacter.h"
#include "TopViewCharacterController.h"
#include "UObject/ConstructorHelpers.h"

ATopViewGameModeBase::ATopViewGameModeBase()
{
	static ConstructorHelpers::FClassFinder<ATopViewCharacter> BP_Character(TEXT("/Script/Engine.Blueprint'/Game/BluePrint/BP_Character.BP_Character_C'"));

	if (BP_Character.Succeeded())
	{
		DefaultPawnClass = BP_Character.Class;

	}

	PlayerControllerClass = ATopViewCharacterController::StaticClass();
	
}