#include "PreCompile.h"
#include "GameDay.h"
#include "ContentsEnum.h"

#include <EngineCore/Image.h>

AGameDay::AGameDay()
{

}

AGameDay::~AGameDay()
{
}

void AGameDay::BeginPlay()
{
	Super::BeginPlay();

	TitleMusic = UEngineSound::SoundPlay("TitleMusic.wav");
	StaticLong = UEngineSound::SoundPlay("StaticLong.wav");
	MenuSwitchSound = UEngineSound::SoundPlay("CCTVSwitch.wav");
	MenuSwitchSound.Off();

	{
		DecreaseAlpha.A = 0.1f;

		NewGameIntroRenderer = CreateWidget<UImage>(GetWorld(), "NewGameIntroRenderer");
		NewGameIntroRenderer->AddToViewPort(5);
		NewGameIntroRenderer->SetSprite("IntroEndings.png", 4);
		NewGameIntroRenderer->SetScale(FVector(1280.0f, 720.0f, 100.0f));

		DayBackgroundRenderer = CreateWidget<UImage>(GetWorld(), "DayBackgroundRenderer");
		DayBackgroundRenderer->AddToViewPort(5);
		DayBackgroundRenderer->SetSprite("DayBackground.png", 0);
		DayBackgroundRenderer->SetScale(FVector(1280.0f, 720.0f, 100.0f));
		DayBackgroundRenderer->SetMulColor({ 1.0f, 1.0f, 1.0f, 0.0f });

		DailyRenderer = CreateWidget<UImage>(GetWorld(), "DailyRenderer");
		DailyRenderer->AddToViewPort(5);
		DailyRenderer->SetSprite("Day.png", 0);
		DailyRenderer->SetAutoSize(1.0f, true);
		DailyRenderer->SetActive(false);
		DailyRenderer->SetMulColor({ 1.0f, 1.0f, 1.0f, 1.0f });

		DailyScanLine = CreateWidget<UImage>(GetWorld(), "DailyScanLine");
		DailyScanLine->AddToViewPort(5);
		DailyScanLine->CreateAnimation("ScanLineAni", "ScanLine", 0.05f, true, 0, 6);
		DailyScanLine->ChangeAnimation("ScanLineAni");
		DailyScanLine->SetFrameCallback("ScanLineAni", 6, [=] {DailyScanLine->SetActive(false); });
		DailyScanLine->SetAutoSize(1.0f, true);
		DailyScanLine->SetActive(false);
	}

	DelayCallBack(3.0f, [this]() { NewGameIntroRenderer->SetActive(false), DailyRenderer->SetActive(true), DailyScanLine->SetActive(true),TitleMusic.Off(), StaticLong.Off(), MenuSwitchSound.On(); });
	DelayCallBack(6.0f, [this]() { DailyRenderer->SetActive(false), DayBackgroundRenderer->SetActive(false); });

}

void AGameDay::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (1.0f > DecreaseAlpha.A && 0.0f <= DecreaseAlpha.A)
	{
		DecreaseAlpha.A += _DeltaTime / 3;
		DayBackgroundRenderer->SetMulColor({ 1.0f, 1.0f, 1.0f, DecreaseAlpha.A });
	}

	if (false == NewGameIntroRenderer->IsActive() && 0.0f <= DecreaseAlpha.A)
	{
		DecreaseAlpha.A -= _DeltaTime;
		DayBackgroundRenderer->SetMulColor({ 1.0f, 1.0f, 1.0f, 1.0f });
		DailyRenderer->SetMulColor({ 1.0f, 1.0f, 1.0f, DecreaseAlpha.A });
	}

	

}
