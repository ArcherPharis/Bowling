// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameUI.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "EntryList.h"
#include "PlayerEntry.h"
#include "Kismet/GameplayStatics.h"
#include "BowlingGameModeBase.h"


void UInGameUI::NativeConstruct()
{
	Super::NativeConstruct();
	addPlayerButton->OnReleased.AddDynamic(this, &UInGameUI::AddPlayer);
	removePlayerButton->OnReleased.AddDynamic(this, &UInGameUI::RemovePlayer);
	startButton->OnReleased.AddDynamic(this, &UInGameUI::StartGame);
	gameMode = Cast<ABowlingGameModeBase>(UGameplayStatics::GetGameMode(this));

	if (gameMode)
	{
		gameMode->nextPlayerTurn.AddDynamic(this, &UInGameUI::PlayerTurnNoti);
		gameMode->onUpdateScore.AddDynamic(this, &UInGameUI::PlayerScoreUpdate);
	}
}

void UInGameUI::AddPlayer()
{
	FText playerName = textBox->GetText();
	FString nameStr = playerName.ToString();

	playerList->AddEntry(nameStr,gameMode->GetNumOfRounds());
	gameMode->AddPlayer(nameStr);
}

void UInGameUI::RemovePlayer()
{
	FText playerName = textBox->GetText();
	FString nameStr = playerName.ToString();
	playerList->RemoveEntry(nameStr);
	gameMode->RemovePlayer(nameStr);

}

void UInGameUI::StartGame()
{

	gameMode->StartingBowlingGame();
	playerSettingRoot->SetVisibility(ESlateVisibility::Hidden);
	playerList->GetEntry(0)->PlayerTurn();



}

void UInGameUI::PlayerTurnNoti(int index)
{
		
	playerList->ReturnToNormalColor();
	playerList->GetEntry(index)->PlayerTurn();
}

void UInGameUI::PlayerScoreUpdate(int index, FString newScore, int currentRound)
{
	playerList->GetEntry(index)->UpdateScore(currentRound, newScore);
}
