// Fill out your copyright notice in the Description page of Project Settings.


#include "BowlerPlayer.h"
#include "Camera/CameraComponent.h"
#include "Ball.h"
#include "PinKeeper.h"

// Sets default values
ABowlerPlayer::ABowlerPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	root = CreateDefaultSubobject<USceneComponent>("root");
	RootComponent = root;
	verticalArm = CreateDefaultSubobject<USceneComponent>("verticalArm");
	verticalArm->SetupAttachment(root);
	playerEye = CreateDefaultSubobject<UCameraComponent>("playerEye");
	playerEye->SetupAttachment(verticalArm);
	spawnPoint = CreateDefaultSubobject<USceneComponent>("spawnPoint");
	spawnPoint->SetupAttachment(playerEye);

	
	


}

// Called when the game starts or when spawned
void ABowlerPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnBall();
	
}

// Called every frame
void ABowlerPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void ABowlerPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("LookRight", this, &ABowlerPlayer::LookRight);
	PlayerInputComponent->BindAction("Throw", EInputEvent::IE_Released, this, &ABowlerPlayer::Throw);

}

int ABowlerPlayer::GetScore()
{
	return pinKeeper->CurrentScore();
}



void ABowlerPlayer::Timer()
{
	pinKeeper->increaseScore();
	pinKeeper->SpawnPins();
	ball->Destroy();
	SpawnBall();
	canFire = true;
}



void ABowlerPlayer::SpawnBall()
{
	ball = GetWorld()->SpawnActor<ABall>(ballClass, spawnPoint->GetComponentLocation(), FRotator::ZeroRotator);
	ball->AttachToComponent(spawnPoint, FAttachmentTransformRules::KeepWorldTransform);

}

void ABowlerPlayer::LookRight(float val)
{
	playerEye->AddLocalRotation(FRotator(0, val * lookSpeed, 0));
}

void ABowlerPlayer::Throw()
{
	if (canFire)
	{
		canFire = false;
		ball->Launch(playerEye->GetForwardVector(), ballLaunchSpeed);
		GetWorldTimerManager().SetTimer(timerHandle, this, &ABowlerPlayer::Timer, 5.0f, false);
	}
	
}



