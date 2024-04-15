#include "PreCompile.h"
#include "StageUI.h"
#include <EngineCore/DefaultSceneComponent.h>

AStageUI::AStageUI()
{
	UDefaultSceneComponent* StageUIRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	
	{
		AMRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
		AMRenderer->SetupAttachment(StageUIRoot);
		AMRenderer->SetSprite("AM.png");
		AMRenderer->SetAutoSize(1.0f, true);
		AMRenderer->AddPosition(FVector(600.0f, 325.0f, 100.0f));
		AMRenderer->SetOrder(3);

		TimeRenderer01 = CreateDefaultSubObject<USpriteRenderer>("Render");
		TimeRenderer01->SetupAttachment(StageUIRoot);
		TimeRenderer01->SetSprite("Number01.png");
		TimeRenderer01->SetAutoSize(1.3f, true);
		TimeRenderer01->AddPosition(FVector(525.0f, 325.0f, 100.0f));
		TimeRenderer01->SetOrder(3);

		TimeRenderer02 = CreateDefaultSubObject<USpriteRenderer>("Render");
		TimeRenderer02->SetupAttachment(StageUIRoot);
		TimeRenderer02->SetSprite("Number02.png");
		TimeRenderer02->SetAutoSize(1.3f, true);
		TimeRenderer02->AddPosition(FVector(550.0f, 325.0f, 100.0f));
		TimeRenderer02->SetOrder(3);

		NightRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
		NightRenderer->SetupAttachment(StageUIRoot);
		NightRenderer->SetSprite("Night.png");
		NightRenderer->SetAutoSize(1.0f, true);
		NightRenderer->AddPosition(FVector(560.0f, 290.0f, 100.0f));
		NightRenderer->SetOrder(3);

		DayRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
		DayRenderer->SetupAttachment(StageUIRoot);
		DayRenderer->SetSprite("Number01.png");
		DayRenderer->SetAutoSize(0.8f, true);
		DayRenderer->AddPosition(FVector(610.0f, 290.0f, 100.0f));
		DayRenderer->SetOrder(3);
	}

	{
		PoewleftRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
		PoewleftRenderer->SetupAttachment(StageUIRoot);
		PoewleftRenderer->SetSprite("Powerleft.png");
		PoewleftRenderer->SetAutoSize(1.0f, true);
		PoewleftRenderer->AddPosition(FVector(-530.0f, -275.0f, 100.0f));
		PoewleftRenderer->SetOrder(3);

		PoewleftCheckRenderer01 = CreateDefaultSubObject<USpriteRenderer>("Render");
		PoewleftCheckRenderer01->SetupAttachment(StageUIRoot);
		PoewleftCheckRenderer01->SetSprite("Number01.png");
		PoewleftCheckRenderer01->SetAutoSize(1.0f, true);
		PoewleftCheckRenderer01->AddPosition(FVector(610.0f, 290.0f, 100.0f));
		PoewleftCheckRenderer01->SetOrder(3);

		PoewleftCheckRenderer02 = CreateDefaultSubObject<USpriteRenderer>("Render");
		PoewleftCheckRenderer02->SetupAttachment(StageUIRoot);
		PoewleftCheckRenderer02->SetSprite("Number01.png");
		PoewleftCheckRenderer02->SetAutoSize(1.0f, true);
		PoewleftCheckRenderer02->AddPosition(FVector(610.0f, 290.0f, 100.0f));
		PoewleftCheckRenderer02->SetOrder(3);
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