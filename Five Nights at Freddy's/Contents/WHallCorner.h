#pragma once
#include "Rooms.h"
#include "ContentsEnum.h"

class AWHallCorner : public ARooms
{
	GENERATED_BODY(ARooms)

public:
	// constrcuter destructer
	AWHallCorner();
	~AWHallCorner();

	// delete Function
	AWHallCorner(const AWHallCorner& _Other) = delete;
	AWHallCorner(AWHallCorner&& _Other) noexcept = delete;
	AWHallCorner& operator=(const AWHallCorner& _Other) = delete;
	AWHallCorner& operator=(AWHallCorner&& _Other) noexcept = delete;

	int GetCurWHallCornerCam()
	{
		return WHallCornerCam;
	}

	bool GetIsAnimatronics();

	void SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void WHallCornerMonsterCheck();

	std::shared_ptr<AAnimatronics> Animatronics = nullptr;
	int WHallCornerCam = static_cast<int>(EWHallCorner::WestHallB_Default);
};

