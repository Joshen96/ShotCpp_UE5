// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include <Components/BoxComponent.h>
#include "Components/ArrowComponent.h"
#include "Bullet.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("MY Box Compont"));


	SetRootComponent(boxComp);
	

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Static Mesh"));

	meshComp->SetupAttachment(boxComp);

	FVector boxSize = FVector(50.0f, 50.0f, 50.0f);
	boxComp->SetBoxExtent(boxSize);

	//총알 방향 포지션
	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("Fire Position"));
	firePosition->SetupAttachment(boxComp);
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//입력값을 활용하여 방향을 정해주고
	FVector dir = FVector(0, h, v);
	// 정규화를 통해 대각선 이동 계산
	dir.Normalize();
	//새이동값 받기 = 현재위치 + 방향+ 속도*시간;
	FVector NewLocation = GetActorLocation() + dir * moveSpeed * DeltaTime;
	//그곳으로 현재 위치 세팅 프레임단위로
	SetActorLocation(NewLocation);

}

// 입력 부분
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerPawn::MoveHorizontal);
	PlayerInputComponent->BindAxis("Vertical", this, &APlayerPawn::MoveVertical);
	
	PlayerInputComponent->BindAction("Fire",IE_Pressed, this, &APlayerPawn::Fire);
	
}

void APlayerPawn::MoveHorizontal(float _value)
{
	h = _value;
}

void APlayerPawn::MoveVertical(float _value)
{
	v = _value;
}

void APlayerPawn::Fire()
{
	//불릿 생성 할건데 월드에 스폰할 액터는 총알이고, 위치는 플레이의 파이어 포시션의 위치와 방향이다
	ABullet* bullet = GetWorld()->SpawnActor<ABullet>(bulletFactory, firePosition->GetComponentLocation(), firePosition->GetComponentRotation());

	UE_LOG(LogTemp, Warning, TEXT("hihi shot"));
}

