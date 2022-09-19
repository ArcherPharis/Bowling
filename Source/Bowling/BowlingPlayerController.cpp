

#include "BowlingPlayerController.h"
#include "InGameUI.h"

void ABowlingPlayerController::BeginPlay()
{
	Super::BeginPlay();
	CreateUI();
	SetInputMode(FInputModeUIOnly()); //blocks user input for game, only allowing ui input.

}

void ABowlingPlayerController::CreateUI()
{
	inGameUI = CreateWidget<UInGameUI>(this, UIClass);
	if (inGameUI)
	{
		inGameUI->AddToViewport();
	}

}
