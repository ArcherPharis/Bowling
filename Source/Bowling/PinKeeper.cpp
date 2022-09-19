// Fill out your copyright notice in the Description page of Project Settings.


#include "PinKeeper.h"
#include "Pin.h"

// Sets default values
APinKeeper::APinKeeper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APinKeeper::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APinKeeper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


int APinKeeper::CurrentScore()
{
	
	return currentscore;
}

void APinKeeper::increaseScore()
{
	int score = 0;
	for (APin* pin : pins)
	{
		if (!pin->IsStanding())
		{
			score++;
		}
	}
	onScoreCollected.Broadcast(score);
	


}

void APinKeeper::SpawnPins()
{
	for (APin* pin : pins)
	{
		pin->GetMesh()->SetSimulatePhysics(false);
		pin->SetActorLocation(pin->StaringLocation());
		pin->SetActorRotation(pin->StartingRotation());
		pin->GetMesh()->SetSimulatePhysics(true);

	}

}

