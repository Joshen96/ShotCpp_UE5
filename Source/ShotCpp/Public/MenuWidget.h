// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOTCPP_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//��ư2�� �Ҵ�
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* button_Restart;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* button_Exit;


	// ��ư ��� ����
	
	UFUNCTION()
	void Restart();
	UFUNCTION()
	void Exit();


protected:
	//��������Ʈ ���Ѱ�
	virtual void NativeConstruct() override;

};
