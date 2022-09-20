// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerEntry.generated.h"

/**
 * 
 */
UCLASS()
class BOWLING_API UPlayerEntry : public UUserWidget
{
	GENERATED_BODY()

public:
	void Init(const FString& name, int roundCount);
	bool IsForPlayer(const FString& name) const;
	void PlayerTurn();
	void PlayerWait();

private:
	UPROPERTY(meta = (bindWidget))
	class UTextBlock* nameText;

	UPROPERTY(meta = (bindWidget))
	class UHorizontalBox* scoresRoot;

	
};
