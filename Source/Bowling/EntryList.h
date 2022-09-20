// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EntryList.generated.h"


class UPlayerEntry;
UCLASS()
class BOWLING_API UEntryList : public UUserWidget
{
	GENERATED_BODY()

public:

	void AddEntry(const FString& name, int roundCount);
	void RemoveEntry(const FString& name);
	void ReturnToNormalColor();
	UPlayerEntry* GetEntry(int index);
	


private:
	UPROPERTY(meta=(bindWidget))
	class UVerticalBox* root;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UPlayerEntry> EntryClass;

	UPROPERTY()
	TArray<UPlayerEntry*> entries;
	
};
