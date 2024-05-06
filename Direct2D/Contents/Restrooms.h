#pragma once
#include "Rooms.h"
#include "ContentsEnum.h"

class APlayGameMode;
class AChica;
class AFreddy;
class ARestrooms : public ARooms
{
	GENERATED_BODY(ARooms)

public:
	// constrcuter destructer
	ARestrooms();
	~ARestrooms();

	// delete Function
	ARestrooms(const ARestrooms& _Other) = delete;
	ARestrooms(ARestrooms&& _Other) noexcept = delete;
	ARestrooms& operator=(const ARestrooms& _Other) = delete;
	ARestrooms& operator=(ARestrooms&& _Other) noexcept = delete;

	int GetCurRestroomsCam()
	{
		return CurRestroomsCam;
	}

	bool GetIsAnimatronics();

	void SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void RestroomsMonsterCheck();
	void FCamTimeCheck(float _DeltaTime);

	APlayGameMode* PGameMode = nullptr;
	AChica* Chica = nullptr;
	AFreddy* Freddy = nullptr;

	float CamTimeCheck = 5.0f;
	std::shared_ptr<AAnimatronics> Animatronics = nullptr;
	int CurRestroomsCam = static_cast<int>(ERestRooms::RestRooms_Default);

};

