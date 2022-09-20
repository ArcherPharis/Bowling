// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameUI.generated.h"


UCLASS()
class BOWLING_API UInGameUI : public UUserWidget
{
	GENERATED_BODY()

public:

protected:
	virtual void NativeConstruct() override;

private:

	UPROPERTY(meta = (bindWidget))
	class UWidget* playerSettingRoot;

	UPROPERTY(meta = (bindWidget))
	class UEditableTextBox* textBox;

	UPROPERTY(meta = (bindWidget))
	class UButton* addPlayerButton;

	UPROPERTY(meta = (bindWidget))
	class UButton* removePlayerButton;
	UPROPERTY(meta = (bindWidget))
	class UButton* startButton;

	UPROPERTY(meta = (bindWidget))
	class UEntryList* playerList;

	bool atLeastOnePlayerAdded = false;

	UFUNCTION()
	void AddPlayer();

	UFUNCTION()
	void RemovePlayer();

	UFUNCTION()
	void StartGame();

	UFUNCTION()
	void PlayerTurnNoti(int index);

	UFUNCTION()
	void PlayerScoreUpdate(int index, FString newScore, int currentRound);

	class ABowlingGameModeBase* gameMode;
	
};
