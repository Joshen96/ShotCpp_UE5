// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/BoxComponent.h"
#include "EnemyActor.h"
#include "Kismet/GameplayStatics.h"
#include "ShootingGameBase.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	SetRootComponent(boxComp);
	boxComp->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	//�Ѿ�ũ��� ����
	boxComp->SetWorldScale3D(FVector(0.75f, 0.25f, 1.0f));

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	meshComp->SetupAttachment(boxComp);

	boxComp->SetCollisionProfileName(TEXT("Bullet"));

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	boxComp->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnBulletOverlap); //��������Ʈ
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector newLocation = GetActorLocation() + GetActorForwardVector() * moveSpeed * DeltaTime;

	SetActorLocation(newLocation);

}

void ABullet::OnBulletOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//�浹�ѿ�����Ʈ = OtherActor �ι޾ƿ��� �װ� �ֳʹ������� ��ȯ�غ��� �����Ѵٸ� �ı�

	AEnemyActor* enemy = Cast<AEnemyActor>(OtherActor);// OtherActor �� AActor ��  AEnemyActor�� ��ȯ�Ͽ� �־

	if (enemy != nullptr) //��ȿ�� �ּҸ� �ֳʹ̰� �����Ƿ� ����
	{
		OtherActor->Destroy();
		//������ ����Ʈ
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), explosionFX, GetActorLocation(), GetActorRotation());
		//������ ����, ����������Ʈ, ������ġ, ����ȸ����


		// ���� ���� ��带 �޿��� ��
		AGameModeBase* currentMode = GetWorld()->GetAuthGameMode();

		//�޾ƿ� ���Ӹ�带  ����� ���Ӹ��� ĳ��Ʈ ����

		AShootingGameBase* currentGameMode = Cast<AShootingGameBase>(currentMode);

		//���Ӹ�尡 �´ٸ� ���� �߰��ϱ�
		if (currentGameMode != nullptr)
		{
			currentGameMode->AddScore(1);
		}

	}

	Destroy();

}

