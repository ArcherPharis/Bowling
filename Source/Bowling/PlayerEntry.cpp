// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerEntry.h"
#include "Components/TextBlock.h"
#include "Blueprint/WidgetTree.h"
#include "Components/HorizontalBox.h"
#include "Styling/SlateColor.h"

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

void UPlayerEntry::PlayerTurn()
{

	FLinearColor CurrentColor;
	CurrentColor.R = 0;
	CurrentColor.G = 1.f;
	CurrentColor.B = 0;
	CurrentColor.A = 1;

	nameText->SetColorAndOpacity(CurrentColor);
}

void UPlayerEntry::PlayerWait()
{
	FLinearColor CurrentColor;
	CurrentColor.R = 1.f;
	CurrentColor.G = 1.f;
	CurrentColor.B = 1.f;
	CurrentColor.A = 1;

	nameText->SetColorAndOpacity(CurrentColor);
}
