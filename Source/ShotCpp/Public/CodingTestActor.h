// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CodingTestActor.generated.h"

UCLASS()
class SHOTCPP_API ACodingTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACodingTestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	int32 number1 = 10;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 number2 = 30;

	UPROPERTY(EditInstanceOnly)
	FString name = TEXT("조창현");

	UFUNCTION(BlueprintPure)
	int32 Add(int32 _num1, int32 _num2);


	

};
