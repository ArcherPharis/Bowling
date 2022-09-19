// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerEntry.h"
#include "Components/TextBlock.h"
#include "Blueprint/WidgetTree.h"
#include "Components/HorizontalBox.h"

void UPlayerEntry::Init(const FString& name, int roundCount)
{

	nameText->SetText(FText::FromString(name));
	for (int i = 0; i < roundCount; ++i)
	{
		//this is a widget, not a userwidget, as in a whole class. needs to be spawned differently.
		UTextBlock* newScoreText = WidgetTree->ConstructWidget<UTextBlock>();
		scoresRoot->AddChild(newScoreText);
		newScoreText->SetText(FText::FromString("-"));
	}
}

bool UPlayerEntry::IsForPlayer(const FString& name) const
{
	return nameText->GetText().ToString() == name;
}
