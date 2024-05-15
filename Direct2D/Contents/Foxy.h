#pragma once
#include "ContentsEnum.h"

#include "Animatronics.h"
#include <EngineBase/EngineRandom.h>
#include <EngineCore/StateManager.h>

class APlayGameMode;
class ACCTVUI;
class AFoxy : public AAnimatronics
{
	GENERATED_BODY(AAnimatronics)

public:
	// constrcuter destructer
	AFoxy();
	~AFoxy();

	// delete Function
	AFoxy(const AFoxy& _Other) = delete;
	AFoxy(AFoxy&& _Other) noexcept = delete;
	AFoxy& operator=(const AFoxy& _Other) = delete;
	AFoxy& operator=(AFoxy&& _Other) noexcept = delete;

	int GetFoxyCurPos()
	{
		return FoxyCurPos;

	}
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void StateInit();

private:
	UEngineRandom MoveChance;
	APlayGameMode* PGameMode = nullptr;
	std::shared_ptr<ACCTVUI> IsCCTVCam = nullptr;

	int FoxyCurPos = static_cast<int>(EFoxyPos::PirateCoveLv1);
	int FoxyLevel = 0;
	//float FoxyMTCheck = 1.0f;
	float FoxyMTCheck = MoveChance.RandomFloat(0.83f, 16.67f);
	float limitTime = 25.0f;
	bool FoxyResetTime = false;
	bool IsFoxyDebug = false;

	UEngineSoundPlayer MoveSound;
	UEngineSoundPlayer JumpScareSound;

	UStateManager FoxyState;

	void PirateCoveLv1Start();
	void PirateCoveLv1Update(float _DeltaTime);

	void PirateCoveLv2Start();
	void PirateCoveLv2Update(float _DeltaTime);

	void PirateCoveLv3Start();
	void PirateCoveLv3Update(float _DeltaTime);

	void PirateCoveLv4Start();
	void PirateCoveLv4Update(float _DeltaTime);

	void FoxyWestHallStart();
	void FoxyWestHallUpdate(float _DeltaTime);

	void FoxyLeftOfficeStart();
	void FoxyLeftOfficeUpdate(float _DeltaTime);
};

