// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PinKeeper.generated.h"

class APin;

UCLASS()
class BOWLING_API APinKeeper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APinKeeper();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	int CurrentScore();
	void increaseScore();
	void SpawnPins();

private:
	UPROPERTY(EditAnywhere, Category = "Pins")
	TArray<APin*> pins;

	int currentscore = 0;

};
