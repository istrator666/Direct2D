#pragma once
#include "Rooms.h"
#include "ContentsEnum.h"

class APlayGameMode;
class AChica;
class AFreddy;
class AEastHall : public ARooms
{
	GENERATED_BODY(ARooms)

public:
	// constrcuter destructer
	AEastHall();
	~AEastHall();

	// delete Function
	AEastHall(const AEastHall& _Other) = delete;
	AEastHall(AEastHall&& _Other) noexcept = delete;
	AEastHall& operator=(const AEastHall& _Other) = delete;
	AEastHall& operator=(AEastHall&& _Other) noexcept = delete;

	int GetCurEastHallCam()
	{
		return EastHallCam;
	}

	bool GetIsAnimatronics();

	void SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void EastHallMonsterCheck(float _DeltaTime);

	APlayGameMode* PGameMode = nullptr;
	AChica* Chica = nullptr;
	AFreddy* Freddy = nullptr;

	float CamTimeCheck = 3.0f;
	std::shared_ptr<AAnimatronics> Animatronics = nullptr;
	int EastHallCam = static_cast<int>(EWestHall::WestHallA_Default);
};

