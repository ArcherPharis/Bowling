// Fill out your copyright notice in the Description page of Project Settings.


#include "ResetBox.h"
#include "Components/BoxComponent.h"
#include "Ball.h"

// Sets default values
AResetBox::AResetBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	triggerBox = CreateDefaultSubobject<UBoxComponent>("triggerBox");
	triggerBox->SetupAttachment(RootComponent);

	triggerBox->OnComponentBeginOverlap.AddDynamic(this, &AResetBox::OnOverlapBegin);

}

// Called when the game starts or when spawned
void AResetBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AResetBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AResetBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hello"));
	}
}

