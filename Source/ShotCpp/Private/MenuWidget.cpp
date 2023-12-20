// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"
#include "Kismet/GameplayStatics.h" // ���� �ε� �ٽ��ϱ����� ���
#include "Components/Button.h"

void UMenuWidget::Restart()
{
	//���� �ٽ� �ε� �ϱ�
	UGameplayStatics::OpenLevel(GetWorld(), "ShootingMap");
}

void UMenuWidget::Exit()
{
	UWorld* currentWorld = GetWorld();

	//QuitGame(�������ο���, �÷��̾� ������Ʈ�ѷ�, ����Ÿ��, �÷��� ���ѹ���)
	UKismetSystemLibrary::QuitGame(currentWorld, currentWorld->GetFirstPlayerController(), EQuitPreference::Quit, false);
}

void UMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//��������Ʈ�� ��� ž��
	button_Restart->OnClicked.AddDynamic(this, &UMenuWidget::Restart);
	
	button_Exit->OnClicked.AddDynamic(this, &UMenuWidget::Exit);

		
}


