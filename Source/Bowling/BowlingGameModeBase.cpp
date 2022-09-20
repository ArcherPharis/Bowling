// Copyright Epic Games, Inc. All Rights Reserved.


#include "BowlingGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "PinKeeper.h"

void ABowlingGameModeBase::StartingBowlingGame()
{

	UGameplayStatics::GetPlayerController(this, 0)->SetInputMode(FInputModeGameOnly());
	APinKeeper* pinKeeper = Cast<APinKeeper>(UGameplayStatics::GetActorOfClass(this, APinKeeper::StaticClass()));

	if (pinKeeper)
	{
		pinKeeper->onScoreCollected.AddDynamic(this, &ABowlingGameModeBase::ScoreCollected);
	}
	currentPlayerIndex = 0;
	currentRound = 0;
	
}

bool ABowlingGameModeBase::AddPlayer(const FString& playerName)
{
	if (playerScores.Contains(playerName))
		return false;

	playerScores.Add(playerName, 0);
	return true;
}

void ABowlingGameModeBase::RemovePlayer(const FString& playerName)
{
	playerScores.Remove(playerName);

}

void ABowlingGameModeBase::ScoreCollected(int score)
{
	TArray<FString> keys;
	playerScores.GenerateKeyArray(keys);
	playerScores[keys[currentPlayerIndex]] = score;
	currentPlayerIndex++;
	
	if (currentPlayerIndex >= keys.Num()) //returns number of items in an array
	{
		currentRound++;
		currentPlayerIndex = 0;
		if (currentRound > numOfRounds)
		{
			GameFinished();
		}
	}
	nextPlayerTurn.Broadcast(currentPlayerIndex);

	for (auto playerNameScore : playerScores)
	{
		FString playerName = playerNameScore.Key;
		int playerScore = playerNameScore.Value;

		UE_LOG(LogTemp, Warning, TEXT("Player %s has a score of: %d"), *playerName, playerScore);
	}
}

void ABowlingGameModeBase::GameFinished()
{
	UE_LOG(LogTemp, Warning, TEXT("Game is finished"));
	currentPlayerIndex = 0;
	currentRound = 0;
}

