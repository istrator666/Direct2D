#include "PreCompile.h"
#include "StageUI.h"
#include "ContentsEnum.h"

#include <EngineCore/DefaultSceneComponent.h>

AStageUI::AStageUI()
{
	UDefaultSceneComponent* StageUIRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	
	// 우측 상단 시간 및 날짜 랜더
	{
		AMRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
		AMRenderer->SetupAttachment(StageUIRoot);
		AMRenderer->SetSprite("AM.png");
		AMRenderer->SetAutoSize(1.0f, true);
		AMRenderer->AddPosition(FVector(600.0f, 325.0f, 0.0f));
		AMRenderer->SetOrder(EOrderType::UI);

		TimeRenderer01 = CreateDefaultSubObject<USpriteRenderer>("Render");
		TimeRenderer01->SetupAttachment(StageUIRoot);
		TimeRenderer01->SetSprite("Number01.png");
		TimeRenderer01->SetAutoSize(1.3f, true);
		TimeRenderer01->AddPosition(FVector(525.0f, 325.0f, 0.0f));
		TimeRenderer01->SetOrder(EOrderType::UI);

		TimeRenderer02 = CreateDefaultSubObject<USpriteRenderer>("Render");
		TimeRenderer02->SetupAttachment(StageUIRoot);
		TimeRenderer02->SetSprite("Number02.png");
		TimeRenderer02->SetAutoSize(1.3f, true);
		TimeRenderer02->AddPosition(FVector(550.0f, 325.0f, 0.0f));
		TimeRenderer02->SetOrder(EOrderType::UI);

		NightRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
		NightRenderer->SetupAttachment(StageUIRoot);
		NightRenderer->SetSprite("Night.png");
		NightRenderer->SetAutoSize(1.0f, true);
		NightRenderer->AddPosition(FVector(560.0f, 290.0f, 0.0f));
		NightRenderer->SetOrder(EOrderType::UI);

		DayRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
		DayRenderer->SetupAttachment(StageUIRoot);
		DayRenderer->SetSprite("Number01.png");
		DayRenderer->SetAutoSize(0.8f, true);
		DayRenderer->AddPosition(FVector(610.0f, 290.0f, 0.0f));
		DayRenderer->SetOrder(EOrderType::UI);
	}

	// 배터리 잔량 랜더
	{
		PoewleftRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
		PoewleftRenderer->SetupAttachment(StageUIRoot);
		PoewleftRenderer->SetSprite("Powerleft.png");
		PoewleftRenderer->SetAutoSize(1.0f, true);
		PoewleftRenderer->AddPosition(FVector(-530.0f, -275.0f, 0.0f));
		PoewleftRenderer->SetOrder(EOrderType::UI);

		PoewleftCheckRenderer01 = CreateDefaultSubObject<USpriteRenderer>("Render");
		PoewleftCheckRenderer01->SetupAttachment(StageUIRoot);
		PoewleftCheckRenderer01->SetSprite("Number09.png");
		PoewleftCheckRenderer01->SetAutoSize(1.0f, true);
		PoewleftCheckRenderer01->AddPosition(FVector(-440.0f, -270.0f, 0.0f));
		PoewleftCheckRenderer01->SetOrder(EOrderType::UI);

		PoewleftCheckRenderer02 = CreateDefaultSubObject<USpriteRenderer>("Render");
		PoewleftCheckRenderer02->SetupAttachment(StageUIRoot);
		PoewleftCheckRenderer02->SetSprite("Number09.png");
		PoewleftCheckRenderer02->SetAutoSize(1.0f, true);
		PoewleftCheckRenderer02->AddPosition(FVector(-420.0f, -270.0f, 0.0f));
		PoewleftCheckRenderer02->SetOrder(EOrderType::UI);

		PersentRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
		PersentRenderer->SetupAttachment(StageUIRoot);
		PersentRenderer->SetSprite("Persent.png");
		PersentRenderer->SetAutoSize(1.0f, true);
		PersentRenderer->AddPosition(FVector(-400.0f, -270.0f, 0.0f));
		PersentRenderer->SetOrder(EOrderType::UI);
	}

	// 배터리 사용량 랜더
	{
		UsageRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
		UsageRenderer->SetupAttachment(StageUIRoot);
		UsageRenderer->SetSprite("Usage.png");
		UsageRenderer->SetAutoSize(1.0f, true);
		UsageRenderer->AddPosition(FVector(-563.0f, -315.0f, 0.0f));
		UsageRenderer->SetOrder(EOrderType::UI);

		PowerMeterRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
		PowerMeterRenderer->SetupAttachment(StageUIRoot);
		PowerMeterRenderer->SetSprite("PowerMeter.png", 0);
		PowerMeterRenderer->SetAutoSize(1.0f, true);
		PowerMeterRenderer->AddPosition(FVector(-468.0f, -315.0f, 0.0f));
		PowerMeterRenderer->SetOrder(EOrderType::UI);
	}

	// CCTV or 로비화면 전환 Bar
	{
		ChangeBarRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
		ChangeBarRenderer->SetupAttachment(StageUIRoot);
		ChangeBarRenderer->SetSprite("ChangeBar.png", 0);
		ChangeBarRenderer->SetAutoSize(1.0f, true);
		ChangeBarRenderer->AddPosition(FVector(-75.0f, -310.0f, 0.0f));
		ChangeBarRenderer->SetOrder(EOrderType::UI);

		ColChangeBar = CreateDefaultSubObject<UCollision>("Collision");
		ColChangeBar->SetupAttachment(ChangeBarRenderer);
		ColChangeBar->SetScale(FVector{ 600, 50 });
		ColChangeBar->AddPosition(FVector(-75.0f, -310.0f, 50.0f));
		ColChangeBar->SetCollisionGroup(EColType::ChangeBar);
		ColChangeBar->SetCollisionType(ECollisionType::RotRect);
		ColChangeBar->SetOrder(5);
	}


	SetRoot(StageUIRoot);
}

AStageUI::~AStageUI()
{
}

void AStageUI::BeginPlay()
{
	Super::BeginPlay();



}

void AStageUI::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}