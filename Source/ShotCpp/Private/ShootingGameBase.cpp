// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingGameBase.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.h"
#include "Components/TextBlock.h" // UTextBlock ��� ������ �߰���




void AShootingGameBase::BeginPlay()
{
	Super::BeginPlay();

	if (MainWidget != nullptr)
	{
		mainUI = CreateWidget<UMainWidget>(GetWorld(), MainWidget);

		if (mainUI != nullptr)
		{
			mainUI->AddToViewport();
		}
	}
}

void AShootingGameBase::AddScore(int32 point)
{
	currentScore += point;
	
	PrintScore();

}

void AShootingGameBase::PrintScore()
{
	if (mainUI != nullptr)
	{
		
		mainUI->scoreData->SetText(FText::AsNumber(currentScore)); //������� 
	}
}

void AShootingGameBase::PrintLife()
{
	if (mainUI != nullptr)
	{

		mainUI->playerlife->SetText(FText::AsNumber(currentLife)); //������� 
	}
}


