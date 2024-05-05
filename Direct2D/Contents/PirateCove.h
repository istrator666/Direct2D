#pragma once
#include "Rooms.h"
#include "ContentsEnum.h"

class APlayGameMode;
class AFoxy;
class APirateCove : public ARooms
{
	GENERATED_BODY(ARooms)

public:
	// constrcuter destructer
	APirateCove();
	~APirateCove();

	// delete Function
	APirateCove(const APirateCove& _Other) = delete;
	APirateCove(APirateCove&& _Other) noexcept = delete;
	APirateCove& operator=(const APirateCove& _Other) = delete;
	APirateCove& operator=(APirateCove&& _Other) noexcept = delete;

	int GetCurPirateCoveCam()
	{
		return CurPirateCoveCam;
	}

	bool GetIsAnimatronics();

	void SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void PirateCoveMonsterCheck();

	APlayGameMode* PGameMode = nullptr;

	float CamTimeCheck = 5.0f;
	std::shared_ptr<AAnimatronics> Animatronics = nullptr;
	int CurPirateCoveCam = static_cast<int>(EPirateCove::PirateCove_Lv1);

};

