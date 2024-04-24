#pragma once
#include "EngineCore/Actor.h"

class UImage;

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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

