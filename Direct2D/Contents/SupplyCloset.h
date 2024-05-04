#pragma once
#include "EngineCore/Actor.h"
#include "Rooms.h"
#include "ContentsEnum.h"

class ASupplyCloset : public ARooms
{
	GENERATED_BODY(ARooms)

public:
	// constrcuter destructer
	ASupplyCloset();
	~ASupplyCloset();

	// delete Function
	ASupplyCloset(const ASupplyCloset& _Other) = delete;
	ASupplyCloset(ASupplyCloset&& _Other) noexcept = delete;
	ASupplyCloset& operator=(const ASupplyCloset& _Other) = delete;
	ASupplyCloset& operator=(ASupplyCloset&& _Other) noexcept = delete;

	int GetCurSupplyClosetCam()
	{
		return SupplyClosetCam;
	}

	bool GetIsAnimatronics();

	void SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void SupplyClosetMonsterCheck();

	std::shared_ptr<AAnimatronics> Animatronics = nullptr;
	int SupplyClosetCam = static_cast<int>(ESupplyCloset::SupplyCloset_Default);
};

