#pragma once
#include "Rooms.h"
#include "ContentsEnum.h"

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

	std::shared_ptr<AAnimatronics> Animatronics = nullptr;
	int CurRestroomsCam = static_cast<int>(ERestRooms::RestRooms_Default);

};

