#pragma once
#include "EngineCore/Actor.h"

class UImage;
class APlayGameMode;
class ALeftButton;
class ARightButton;

class ABatteryUI : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ABatteryUI();
	~ABatteryUI();

	// delete Function
	ABatteryUI(const ABatteryUI& _Other) = delete;
	ABatteryUI(ABatteryUI&& _Other) noexcept = delete;
	ABatteryUI& operator=(const ABatteryUI& _Other) = delete;
	ABatteryUI& operator=(ABatteryUI&& _Other) noexcept = delete;

	void SetPowerMeterUsage(int _Sum)
	{
		if (0 > PowerMeterUsage)
		{
			return;
		}

		PowerMeterUsage += _Sum;
	}

	void PowerleftDecrease(float _DeltaTime);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void CurPowerMeter();

	float PowerleftDecreaseTime = 2.0f;
	int PowerleftDecrease01 = 9;
	int PowerleftDecrease02 = 9;
	int PowerMeterUsage = 0;

	UImage* PowerleftCheckRenderer01 = nullptr;
	UImage* PowerleftCheckRenderer02 = nullptr;
	UImage* PowerMeterRenderer = nullptr;

	APlayGameMode* PGameMode = nullptr;
	std::shared_ptr<ALeftButton> LButton = nullptr;
	std::shared_ptr<ARightButton> RButton = nullptr;

};

