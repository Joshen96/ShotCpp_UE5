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



	//박스콜라이더
	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

	// 매쉬 
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;
	//움직임 속도
	UPROPERTY(EditAnywhere)
	float moveSpeed = 500;
	//체력
	
	UPROPERTY(EditAnywhere)
	bool die = false;

	//총구위치
	UPROPERTY(EditAnywhere)
	class UArrowComponent* firePosition;

	// 총알 블프 프리탭
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABullet> bulletFactory;


	
	



	UPROPERTY(EditAnywhere)
	class USoundBase* fireSound;

	void EnemyHit(int32 Damage);

	void Die();

	

private:
	float h;
	float v;

	void MoveHorizontal(float _value);
	void MoveVertical(float _value);

	UPROPERTY(EditAnywhere)
	int32 Life = 0;
	
	void Fire();

	

};
