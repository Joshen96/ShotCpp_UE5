// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include <Components/BoxComponent.h>
#include "Components/ArrowComponent.h"
#include "Bullet.h"
#include "Kismet/GameplayStatics.h"
#include "ShootingGameBase.h"

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

	//�Ѿ� ���� ������
	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("Fire Position"));
	firePosition->SetupAttachment(boxComp);


	boxComp->SetGenerateOverlapEvents(true);
	boxComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	boxComp->SetCollisionObjectType(ECC_EngineTraceChannel1);

	boxComp->SetCollisionResponseToAllChannels(ECR_Ignore);

	boxComp->SetCollisionResponseToChannel(ECC_EngineTraceChannel2, ECR_Overlap);

	boxComp->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);

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
	

	if (!die) 
	{
		//�Է°��� Ȱ���Ͽ� ������ �����ְ�
		FVector dir = FVector(0, h, v);
		// ����ȭ�� ���� �밢�� �̵� ���
		dir.Normalize();
		//���̵��� �ޱ� = ������ġ + ����+ �ӵ�*�ð�;
		FVector NewLocation = GetActorLocation() + dir * moveSpeed * DeltaTime;
		//�װ����� ���� ��ġ ���� �����Ӵ�����
		SetActorLocation(NewLocation, true);
	}
	else
	{
		Die();
	}


}

// �Է� �κ�
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
	//�Ҹ� ���� �Ұǵ� ���忡 ������ ���ʹ� �Ѿ��̰�, ��ġ�� �÷����� ���̾� ���ü��� ��ġ�� �����̴�
	ABullet* bullet = GetWorld()->SpawnActor<ABullet>(bulletFactory, firePosition->GetComponentLocation(), firePosition->GetComponentRotation());
	//�Ѿ� ���� �߰�
	UGameplayStatics::PlaySound2D(GetWorld(), fireSound);
	
}

void APlayerPawn::EnemyHit(int32 Damage)
{
	AGameModeBase* currentMode = GetWorld()->GetAuthGameMode();



	AShootingGameBase* currentGameMode = Cast<AShootingGameBase>(currentMode);

	if (currentGameMode->currentLife >= 0)
	{
		currentGameMode->currentLife -= Damage;
	}
	else
	{
		currentGameMode->currentLife = 0;
	}
	if (currentGameMode->currentLife == 0)
	{
		die = true;
	}
	currentGameMode->PrintLife();

	
	
}

void APlayerPawn::Die()
{
	Destroy();
}




