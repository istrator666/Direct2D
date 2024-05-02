#pragma once
#include "EngineCore/Actor.h"
#include "Rooms.h"
#include "ContentsEnum.h"

class ADiningArea : public Rooms
{
	GENERATED_BODY(Rooms)

public:
	// constrcuter destructer
	ADiningArea();
	~ADiningArea();

	// delete Function
	ADiningArea(const ADiningArea& _Other) = delete;
	ADiningArea(ADiningArea&& _Other) noexcept = delete;
	ADiningArea& operator=(const ADiningArea& _Other) = delete;
	ADiningArea& operator=(ADiningArea&& _Other) noexcept = delete;

	int GetCurDiningAreaCam()
	{
		return CurDiningAreaCam;
	}

	bool GetIsAnimatronics()
	{
		if (nullptr == Animatronics)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void DiningAreaMonsterCheck();

	std::shared_ptr<AAnimatronics> Animatronics = nullptr;
	int CurDiningAreaCam = static_cast<int>(EDiningArea::DiningArea_Default);
};

