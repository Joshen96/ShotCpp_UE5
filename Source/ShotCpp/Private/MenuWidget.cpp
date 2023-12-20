// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"
#include "Kismet/GameplayStatics.h" // 레벨 로드 다시하기위한 헤더
#include "Components/Button.h"

void UMenuWidget::Restart()
{
	//레벨 다시 로드 하기
	UGameplayStatics::OpenLevel(GetWorld(), "ShootingMap");
}

void UMenuWidget::Exit()
{
	UWorld* currentWorld = GetWorld();

	//QuitGame(실행중인월드, 플레이어 제어컨트롤러, 종료타입, 플랫폼 제한무시)
	UKismetSystemLibrary::QuitGame(currentWorld, currentWorld->GetFirstPlayerController(), EQuitPreference::Quit, false);
}

void UMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//델리게이트로 기능 탑재
	button_Restart->OnClicked.AddDynamic(this, &UMenuWidget::Restart);
	
	button_Exit->OnClicked.AddDynamic(this, &UMenuWidget::Exit);

		
}


