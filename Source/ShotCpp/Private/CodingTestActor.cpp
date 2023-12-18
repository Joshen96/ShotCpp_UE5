// Fill out your copyright notice in the Description page of Project Settings.


#include "CodingTestActor.h"


// Sets default values
ACodingTestActor::ACodingTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACodingTestActor::BeginPlay()
{
	Super::BeginPlay();
	

	//UE_LOG(LogTemp, Warning, TEXT("%d"),number1);
	//UE_LOG(LogTemp, Warning, TEXT("%f"),number2);
	//UE_LOG(LogTemp, Warning, TEXT("%s"),*name);

	UE_LOG(LogTemp, Warning, TEXT("%d"), Add(number1, number2));
	if (number1 >= 10) {

		UE_LOG(LogTemp, Warning, TEXT("number1의 값이 10이상입니다."));
	}

}

// Called every frame
void ACodingTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 ACodingTestActor::Add(int32 _num1, int32 _num2)
{
	int32 result = _num1 + _num2;
	return result;
}

