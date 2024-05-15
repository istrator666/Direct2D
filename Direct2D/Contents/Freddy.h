#pragma once
#include "ContentsEnum.h"

#include "Animatronics.h"
#include <EngineBase/EngineRandom.h>
#include <EngineCore/StateManager.h>

class APlayGameMode;
class ACCTVUI;
class AFreddy : public AAnimatronics
{
	GENERATED_BODY(AAnimatronics)

public:
	// constrcuter destructer
	AFreddy();
	~AFreddy();

	// delete Function
	AFreddy(const AFreddy& _Other) = delete;
	AFreddy(AFreddy&& _Other) noexcept = delete;
	AFreddy& operator=(const AFreddy& _Other) = delete;
	AFreddy& operator=(AFreddy&& _Other) noexcept = delete;

	int GetFreddyCurPos()
	{
		return FreddyCurPos;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void StateInit();

private:
	UEngineRandom MoveChance;
	APlayGameMode* PGameMode = nullptr;
	std::shared_ptr<ACCTVUI> IsCCTVCam = nullptr;
	int FreddyCurPos = static_cast<int>(EFreddyPos::ShowStage);
	int FreddyLevel = 0;
	float FreddyMTCheck = 3.0f;
	float MoveTime = 3.0f;
	bool IsFreddyDebug = false;

	UStateManager FreddyState;

	void ShowStageStart();
	void ShowStageUpdate(float _DeltaTime);

	void DiningAreaStart();
	void DiningAreaUpdate(float _DeltaTime);

	void EastHallStart();
	void EastHallUpdate(float _DeltaTime);

	void EHallCornerStart();
	void EHallCornerUpdate(float _DeltaTime);

	void KitchenStart();
	void KitchenUpdate(float _DeltaTime);

	void RestroomsStart();
	void RestroomsUpdate(float _DeltaTime);

	void RightOfficeStart();
	void RightOfficeUpdate(float _DeltaTime);

};

