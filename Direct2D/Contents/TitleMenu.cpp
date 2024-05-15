#include "PreCompile.h"
#include "TitleMenu.h"
#include "ContentsEnum.h"

#include <EngineCore/DefaultSceneComponent.h>

ATitleMenu::ATitleMenu() 
{
	UDefaultSceneComponent* TitleRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	TitleBackgroundRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	TitleBackgroundRenderer->SetupAttachment(TitleRoot);
	TitleBackgroundRenderer->SetScale(FVector(1280.0f, 740.0f, 100.0f));
	TitleBackgroundRenderer->SetSprite("IntroEndings.png", 0);
	TitleBackgroundRenderer->SetOrder(EOrderType::Background);

	NoiseRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	NoiseRenderer->SetupAttachment(TitleRoot);
	NoiseRenderer->SetScale(FVector(1280.0f, 740.0f, 100.0f));
	NoiseRenderer->SetMaterial("OverlayMaterial");
	NoiseRenderer->CreateAnimation("Noise", "static.png", 0.1f, true, 0, 7);
	NoiseRenderer->ChangeAnimation("Noise");
	NoiseRenderer->SetOrder(EOrderType::Overlay);

	ScanLineRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	ScanLineRenderer->SetupAttachment(TitleRoot);
	ScanLineRenderer->SetAutoSize(1.0f, true);
	ScanLineRenderer->SetSprite("TitleScanLine.png");
	ScanLineRenderer->SetMulColor({ 1.0f, 1.0f, 1.0f, 0.3f });
	ScanLineRenderer->SetOrder(EOrderType::Overlay);
	ScanLineRenderer->SetPosition(FVector(0.0f, DownLineSpeedY, 0.0f));

	CameraEffectsRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	CameraEffectsRenderer->SetupAttachment(TitleRoot);
	CameraEffectsRenderer->SetAutoSize(1.0f, true);
	CameraEffectsRenderer->SetMulColor({ 1.0f, 1.0f, 1.0f, 0.3f });
	CameraEffectsRenderer->SetOrder(2);

	TitleNameRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	TitleNameRenderer->SetupAttachment(TitleRoot);
	TitleNameRenderer->SetMaterial("OverlayMaterial");
	TitleNameRenderer->SetAutoSize(1.0f, true);
	TitleNameRenderer->SetSprite("GameTitle.png", 0);
	TitleNameRenderer->AddPosition(FVector(-350.0f, -20.0f, 100.0f));
	TitleNameRenderer->SetOrder(EOrderType::Overlay);

	TitleSelectRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	TitleSelectRenderer->SetMaterial("OverlayMaterial");
	TitleSelectRenderer->SetAutoSize(1.0f, true);
	TitleSelectRenderer->SetSprite("Select.png", 0);
	TitleSelectRenderer->AddPosition(FVector(-500.0f, -70.0f, 100.0f));
	TitleSelectRenderer->SetOrder(2);

	ColStart = CreateDefaultSubObject<UCollision>("Collision");
	ColStart->SetupAttachment(TitleRoot);
	ColStart->SetScale(FVector{ 200,50 });
	ColStart->AddPosition(FVector(-350.0f, -70.0f, 0.0f));
	ColStart->SetCollisionGroup(EColType::Start);
	ColStart->SetCollisionType(ECollisionType::Rect);

	ColContinue = CreateDefaultSubObject<UCollision>("Collision");
	ColContinue->SetupAttachment(TitleRoot);
	ColContinue->SetScale(FVector{ 200,50 });
	ColContinue->AddPosition(FVector(-350.0f, -140.0f, 0.0f));
	ColContinue->SetCollisionGroup(EColType::Continue);
	ColContinue->SetCollisionType(ECollisionType::Rect);

	SetRoot(TitleRoot);
}

ATitleMenu::~ATitleMenu()
{
}

void ATitleMenu::BeginPlay()
{
	Super::BeginPlay();
}

void ATitleMenu::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AccumulatedTime += _DeltaTime;
	TitleBackTime += _DeltaTime;
	ScanTime += _DeltaTime;
	if (AccumulatedTime >= 0.01f)
	{
		DownLineSpeedY -= 0.2f;
		AccumulatedTime = 0.0f;
		ScanLineRenderer->SetPosition(FVector(0.0f, DownLineSpeedY, 0.0f));
	}

	if (DownLineSpeedY < -360.0f)
	{
		DownLineSpeedY = 300.0f;
		ScanLineRenderer->SetPosition(FVector(0.0f, DownLineSpeedY, 0.0f));
	}

	if (Random.RandomFloat(3.0f, 5.0f) < TitleBackTime)
	{
		TitleBackTime = 0.0f;

		int index = Random.RandomInt(1, 3);
		TitleBackgroundRenderer->SetSprite("IntroEndings.png", index);
	}
	else if (0.1f < TitleBackTime)
	{
		TitleBackgroundRenderer->SetSprite("IntroEndings.png", 0);
	}

	if (Random.RandomFloat(0.7f, 1.0f) < ScanTime)
	{
		ScanTime = 0.0f;
		int index = Random.RandomInt(10, 15);
		CameraEffectsRenderer->SetActive(true);
		CameraEffectsRenderer->SetSprite("CameraEffects.png", index);
	}
	else if (0.5 < ScanTime)
	{
		CameraEffectsRenderer->SetActive(false);
	}
}