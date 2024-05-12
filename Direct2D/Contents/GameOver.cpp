#include "PreCompile.h"
#include "GameOver.h"
#include "ContentsEnum.h"

#include <EngineCore/DefaultSceneComponent.h>

AGameOver::AGameOver()
{
	UDefaultSceneComponent* GameOverRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	GameOverStaticRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	GameOverStaticRenderer->SetupAttachment(GameOverRoot);
	GameOverStaticRenderer->CreateAnimation("Noise", "Static.png", 0.1f, true, 0, 7);
	GameOverStaticRenderer->ChangeAnimation("Noise");
	GameOverStaticRenderer->SetAutoSize(1.0f, true);
	GameOverStaticRenderer->SetOrder(EOrderType::FrontActor);

	GameOverScanLineRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	GameOverScanLineRenderer->SetupAttachment(GameOverRoot);
	GameOverScanLineRenderer->CreateAnimation("ScanLineAni", "ScanLine", 0.1f, false, 0, 6);
	GameOverScanLineRenderer->ChangeAnimation("ScanLineAni");
	GameOverScanLineRenderer->SetAutoSize(1.0f, true);
	GameOverScanLineRenderer->SetOrder(EOrderType::Overlay);

	USpriteRenderer* GameOverBackRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	GameOverBackRenderer->SetupAttachment(GameOverRoot);
	GameOverBackRenderer->SetSprite("GameOver", 0);
	GameOverBackRenderer->SetAutoSize(1.0f, true);
	GameOverBackRenderer->SetOrder(EOrderType::Background);

	USpriteRenderer* GameOverRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	GameOverRenderer->SetupAttachment(GameOverRoot);
	GameOverRenderer->SetSprite("GameOver", 1);
	GameOverRenderer->SetAutoSize(1.0f, true);
	GameOverRenderer->SetOrder(EOrderType::BackActor);

	SetRoot(GameOverRoot);
}

AGameOver::~AGameOver()
{
}

void AGameOver::BeginPlay()
{
	Super::BeginPlay();

	DelayCallBack(3.0f, [this]() { GameOverStaticRenderer->SetActive(false), GameOverScanLineRenderer->SetActive(false); });
	DelayCallBack(5.0f, [this]() { GEngine->ChangeLevel("TitleLevel"); });
}

void AGameOver::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
