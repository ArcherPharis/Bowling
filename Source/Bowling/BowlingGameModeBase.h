// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BowlingGameModeBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNextPlayerTurn, int, index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FUpdateScore, int, index, FString, newScore, int, currentRound);
UCLASS()
class BOWLING_API ABowlingGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	void StartingBowlingGame();
	bool AddPlayer(const FString& playerName);
	void RemovePlayer(const FString& playerName);

	FOnNextPlayerTurn nextPlayerTurn;
	FUpdateScore onUpdateScore;

	FORCEINLINE int GetNumOfRounds() const { return numOfRounds; } //forcedinline makes it read here in the header, more performant

private:
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	int numOfRounds = 10;

	UPROPERTY()
	TMap<FString, int> playerScores;

	UFUNCTION()
	void ScoreCollected(int score);

	int currentPlayerIndex = 0;
	int currentRound = 0;

	void GameFinished();
	
};
