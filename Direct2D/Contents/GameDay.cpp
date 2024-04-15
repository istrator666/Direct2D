#include "PreCompile.h"
#include "GameDay.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/DefaultSceneComponent.h>

AGameDay::AGameDay()
{
	UDefaultSceneComponent* DayRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	NewGameIntroRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	NewGameIntroRenderer->SetupAttachment(DayRoot);
	NewGameIntroRenderer->SetSprite("IntroEndings.png", 4);
	NewGameIntroRenderer->SetScale(FVector(1280.0f, 720.0f, 100.0f));
	NewGameIntroRenderer->SetOrder(10);

	DayBackgroundRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	DayBackgroundRenderer->SetupAttachment(DayRoot);
	DayBackgroundRenderer->SetSprite("DayBackground.png", 0);
	DayBackgroundRenderer->SetScale(FVector(1280.0f, 720.0f, 100.0f));
	DayBackgroundRenderer->SetOrder(9);

	DailyRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	DailyRenderer->SetupAttachment(DayRoot);
	DailyRenderer->SetSprite("Day.png", 0);
	DailyRenderer->SetAutoSize(1.0f, true);
	DailyRenderer->SetOrder(10);
	DailyRenderer->SetActive(false);

	SetRoot(DayRoot);
}

AGameDay::~AGameDay()
{
}

void AGameDay::BeginPlay()
{
	Super::BeginPlay();
	DelayCallBack(1.0f, [this]() { NewGameIntroRenderer->SetActive(false), DailyRenderer->SetActive(true); });
	DelayCallBack(2.0f, [this]() { DailyRenderer->SetActive(false), DayBackgroundRenderer->SetActive(false); });

}

void AGameDay::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}
