// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShootingGameBase.generated.h"


/**
 * 
 */
UCLASS()
class SHOTCPP_API AShootingGameBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void AddScore(int32 point);
	
	//받아올 위젯클래스

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UMainWidget> MainWidget;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UMenuWidget> MenuWidget;

	void ShowMenu();

	int32 currentLife = 10;
	
	void PrintLife();

protected:
	virtual void BeginPlay() override;

private:

	int32 currentScore = 0;

	
	
	class UMainWidget* mainUI;

	class UMenuWidget* menuUI;

	void PrintScore();
	
	
};
