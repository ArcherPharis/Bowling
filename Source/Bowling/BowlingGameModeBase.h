// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BowlingGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BOWLING_API ABowlingGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	void StartingBowlingGame();
	bool AddPlayer(const FString& playerName);
	void RemovePlayer(const FString& playerName);

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
