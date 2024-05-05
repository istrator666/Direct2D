#pragma once
#include "Rooms.h"
#include "ContentsEnum.h"

class AEHallCorner : public ARooms
{
	GENERATED_BODY(ARooms)
public:
	// constrcuter destructer
	AEHallCorner();
	~AEHallCorner();

	// delete Function
	AEHallCorner(const AEHallCorner& _Other) = delete;
	AEHallCorner(AEHallCorner&& _Other) noexcept = delete;
	AEHallCorner& operator=(const AEHallCorner& _Other) = delete;
	AEHallCorner& operator=(AEHallCorner&& _Other) noexcept = delete;

	int GetEHallCornerCam()
	{
		return CurEHallCornerCam;
	}

	bool GetIsAnimatronics();

	void SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void EHallCornerMonsterCheck();

	std::shared_ptr<AAnimatronics> Animatronics = nullptr;
	int CurEHallCornerCam = static_cast<int>(EEHallCorner::EastHallB_Default);

};

