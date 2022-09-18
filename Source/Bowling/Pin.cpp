// Fill out your copyright notice in the Description page of Project Settings.


#include "Pin.h"

// Sets default values
APin::APin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>("mesh");
	RootComponent = mesh;

}

// Called when the game starts or when spawned
void APin::BeginPlay()
{
	Super::BeginPlay();
	startingLocation = GetActorLocation();
	startingRotation = GetActorRotation();
	
}

// Called every frame
void APin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	


}

bool APin::IsStanding()
{
	return GetActorUpVector().Z > 0.9;
}

UStaticMeshComponent* APin::GetMesh()
{
	return mesh;
}

FVector APin::StaringLocation()
{
	return startingLocation;
}

FRotator APin::StartingRotation()
{
	return startingRotation;
}

