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
	//버튼2개 할당
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* button_Restart;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* button_Exit;


	// 버튼 기능 구현
	
	UFUNCTION()
	void Restart();
	UFUNCTION()
	void Exit();


protected:
	//델리게이트 위한것
	virtual void NativeConstruct() override;

};
