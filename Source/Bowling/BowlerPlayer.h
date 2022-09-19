
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BowlerPlayer.generated.h"

UCLASS()
class BOWLING_API ABowlerPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABowlerPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		int GetScore();


	void Timer();
	FTimerHandle timerHandle;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	USceneComponent* root;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	USceneComponent* verticalArm;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	USceneComponent* spawnPoint;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	class UCameraComponent* playerEye;

	UPROPERTY(EditDefaultsOnly, Category = "Control")
	float lookSpeed;
	UPROPERTY(EditDefaultsOnly, Category = "Control")
	float ballLaunchSpeed;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABall> ballClass;

	UPROPERTY(EditAnywhere)
	class APinKeeper* pinKeeper;

	ABall* ball;

	void SpawnBall();

	void LookRight(float val);
	void Throw();

	bool canFire = true;



	

};
