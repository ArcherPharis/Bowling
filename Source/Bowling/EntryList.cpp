// Fill out your copyright notice in the Description page of Project Settings.


#include "EntryList.h"
#include "PlayerEntry.h"
#include "Components/VerticalBox.h"

void UEntryList::AddEntry(const FString& name, int roundCount)
{

	for (auto n : entries)
	{
		if (n->IsForPlayer(name))
		{
			return;

		}
	}

	UPlayerEntry* newEntry =  CreateWidget<UPlayerEntry>(this, EntryClass);
	newEntry->Init(name, roundCount);
	root->AddChild(newEntry);
	entries.Add(newEntry);

}

void UEntryList::RemoveEntry(const FString& name)
{

	UPlayerEntry* entryToRemove = nullptr;

	for (auto n : entries)
	{
		if (n->IsForPlayer(name))
		{
			entryToRemove = n;

		}
	}
	entries.Remove(entryToRemove);
	entryToRemove->RemoveFromParent();
	entryToRemove->MarkAsGarbage();
	
}

void UEntryList::ReturnToNormalColor()
{
	for (UPlayerEntry* entry : entries)
	{
		entry->PlayerWait();
	}

}

UPlayerEntry* UEntryList::GetEntry(int index)
{
	return entries[index];
}

