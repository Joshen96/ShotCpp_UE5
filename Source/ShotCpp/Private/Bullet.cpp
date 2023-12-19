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
	//총알크기로 변경
	boxComp->SetWorldScale3D(FVector(0.75f, 0.25f, 1.0f));

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	meshComp->SetupAttachment(boxComp);

	boxComp->SetCollisionProfileName(TEXT("Bullet"));

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	boxComp->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnBulletOverlap); //델리게이트
	
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
	//충돌한오브젝트 = OtherActor 로받아오고 그게 애너미컴포로 변환해보고 존재한다면 파괴

	AEnemyActor* enemy = Cast<AEnemyActor>(OtherActor);// OtherActor 인 AActor 를  AEnemyActor로 변환하여 넣어봄

	if (enemy != nullptr) //유효한 주소면 애너미가 맞으므로 삭제
	{
		OtherActor->Destroy();
		//터지고 이펙트
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), explosionFX, GetActorLocation(), GetActorRotation());
		//생성할 월드, 생성할이펙트, 생성위치, 생성회전값


		// 현재 게임 모드를 받오는 것
		AGameModeBase* currentMode = GetWorld()->GetAuthGameMode();

		//받아온 게임모드를  사용할 게임모드로 캐스트 해줌

		AShootingGameBase* currentGameMode = Cast<AShootingGameBase>(currentMode);

		//게임모드가 맞다면 점수 추가하기
		if (currentGameMode != nullptr)
		{
			currentGameMode->AddScore(1);
		}

	}

	Destroy();

}

