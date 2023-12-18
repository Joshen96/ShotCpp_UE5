// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"



UCLASS()
class SHOTCPP_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//�ڽ��ݶ��̴�
	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

	// �Ž� 
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere)
	float moveSpeed = 500;


	//�ѱ���ġ
	UPROPERTY(EditAnywhere)
	class UArrowComponent* firePosition;

	// �Ѿ� ���� ������
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABullet> bulletFactory;


private:
	float h;
	float v;

	void MoveHorizontal(float _value);
	void MoveVertical(float _value);

	
	void Fire();


};
