#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

class APlayGameMode;
class ALeftButton;
class ARightButton;
class ABatteryUI;

class AMouseCursor : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AMouseCursor();
	~AMouseCursor();

	// delete Function
	AMouseCursor(const AMouseCursor& _Other) = delete;
	AMouseCursor(AMouseCursor&& _Other) noexcept = delete;
	AMouseCursor& operator=(const AMouseCursor& _Other) = delete;
	AMouseCursor& operator=(AMouseCursor&& _Other) noexcept = delete;

	int GetUpDownCheck()
	{
		return PowerMeterUpDownCheck;
	}

	void SetUpdownCheck(int _PowerMeterUpDownCheck)
	{
		PowerMeterUpDownCheck += _PowerMeterUpDownCheck;
	}

	void SetLightSound(bool _Active)
	{
		if (true == _Active)
		{
			LightSound.On();
		}
		else if (false == _Active)
		{
			LightSound.Off();
		}
	}

	void GetLightCheck();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UCollision* ColMouse = nullptr;
	APlayGameMode* PGameMode = nullptr;
	std::shared_ptr<ALeftButton> LButton = nullptr;
	std::shared_ptr<ARightButton> RButton = nullptr;

	UEngineSoundPlayer DoorSound;
	UEngineSoundPlayer LightSound;
	UEngineSoundPlayer WindowScareSound;

	void SetMousePos();
	void ColLefButton();
	void ColRightButton();

	int PowerMeterUpDownCheck = 0;
};
