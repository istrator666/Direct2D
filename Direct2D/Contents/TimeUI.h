#pragma once

#include <EngineCore/Actor.h>

class UImage;
class APlayGameMode;
class ATimeUI : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ATimeUI();
	~ATimeUI();

	// delete Function
	ATimeUI(const ATimeUI& _Other) = delete;
	ATimeUI(ATimeUI&& _Other) noexcept = delete;
	ATimeUI& operator=(const ATimeUI& _Other) = delete;
	ATimeUI& operator=(ATimeUI&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void TimeChange(float _DeltaTime);

	APlayGameMode* PGameMode = nullptr;
	UImage* TimeUIRoot = nullptr;
	UImage* TimeRenderer01 = nullptr;
	UImage* TimeRenderer02 = nullptr;
	UImage* DayRenderer = nullptr;
	UImage* MuteCallRenderer = nullptr;

	UImage* NextDayBackRenderer = nullptr;
	UImage* NextDayTimeRenderer = nullptr;
	UImage* NextDayAMRenderer = nullptr;

	UImage* EndingRenderer = nullptr;

	int TimeRenderChange = 0;
	int DayRenderChage = 1;
	float DayTimeCheck = 30.0f;

	float4 UVMove;

};

