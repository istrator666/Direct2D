#pragma once
#include <EngineCore/Actor.h>

class UImage;

class AGameDay : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AGameDay();
	~AGameDay();

	// delete Function
	AGameDay(const AGameDay& _Other) = delete;
	AGameDay(AGameDay&& _Other) noexcept = delete;
	AGameDay& operator=(const AGameDay& _Other) = delete;
	AGameDay& operator=(AGameDay&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImage* NewGameIntroRenderer = nullptr;
	UImage* DayBackgroundRenderer = nullptr;
	UImage* DailyRenderer = nullptr;
	UImage* DailyScanLine = nullptr;

	UEngineSoundPlayer TitleMusic;
	UEngineSoundPlayer StaticLong;
	UEngineSoundPlayer MenuSwitchSound;

	float4 DecreaseAlpha;


};

