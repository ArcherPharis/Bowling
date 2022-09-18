// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pin.generated.h"

UCLASS()
class BOWLING_API APin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool IsStanding();
	UStaticMeshComponent* GetMesh();

	FVector StaringLocation();
	FRotator StartingRotation();

private:

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh;

	FVector startingLocation;
	FRotator startingRotation;

};
