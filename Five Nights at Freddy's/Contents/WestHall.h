#pragma once
#include "Rooms.h"
#include "ContentsEnum.h"

class AWestHall : public ARooms
{
	GENERATED_BODY(ARooms)

public:
	// constrcuter destructer
	AWestHall();
	~AWestHall();

	// delete Function
	AWestHall(const AWestHall& _Other) = delete;
	AWestHall(AWestHall&& _Other) noexcept = delete;
	AWestHall& operator=(const AWestHall& _Other) = delete;
	AWestHall& operator=(AWestHall&& _Other) noexcept = delete;

	int GetCurWestHallCam()
	{
		return WestHallCam;
	}

	bool GetIsAnimatronics();

	void SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void WestHallMonsterCheck();

	std::shared_ptr<AAnimatronics> Animatronics = nullptr;
	int WestHallCam = static_cast<int>(EWestHall::WestHallA_Default);
};

