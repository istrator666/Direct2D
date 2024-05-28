#pragma once
#include "Rooms.h"
#include "ContentsEnum.h"

class ADiningArea : public ARooms
{
	GENERATED_BODY(ARooms)

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

	bool GetIsAnimatronics();

	void SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void DiningAreaMonsterCheck();

	std::shared_ptr<AAnimatronics> Animatronics = nullptr;
	int CurDiningAreaCam = static_cast<int>(EDiningArea::DiningArea_Default);
};

