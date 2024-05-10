#include "PreCompile.h"
#include "GameOver.h"
#include "ContentsEnum.h"

#include <EngineCore/DefaultSceneComponent.h>

AGameOver::AGameOver()
{
	UDefaultSceneComponent* GameOverRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	USpriteRenderer* GameOverBackRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	GameOverBackRenderer->SetupAttachment(GameOverRoot);
	GameOverBackRenderer->SetSprite("GameOver", 0);
	GameOverBackRenderer->SetAutoSize(1.0f, true);
	//GameOverBackRenderer->AddPosition(FVector(-750.0f, -50.0f, 0.0f));
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

	DelayCallBack(3.0f, [this]() { GEngine->ChangeLevel("TitleLevel"); });
}

void AGameOver::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
