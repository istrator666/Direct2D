#pragma once
#include "ContentsEnum.h"

#include "Animatronics.h"
#include <EngineBase/EngineRandom.h>
#include <EngineCore/StateManager.h>

class ABonnie : public AAnimatronics
{
	GENERATED_BODY(AAnimatronics)

public:
	// constrcuter destructer
	ABonnie();
	~ABonnie();

	// delete Function
	ABonnie(const ABonnie& _Other) = delete;
	ABonnie(ABonnie&& _Other) noexcept = delete;
	ABonnie& operator=(const ABonnie& _Other) = delete;
	ABonnie& operator=(ABonnie&& _Other) noexcept = delete;

	int GetBonnieCurPos()
	{
		return BonnieCurPos;
	}

	bool GetBonnieIsBack()
	{
		return IsBack;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	//FSM
	void Cam1AStart();
	void Cam1AUpdate(float _DeltaTime);

	void Cam1BStart();
	void Cam1BUpdate(float _DeltaTime);

	void Cam2AStart();
	void Cam2AUpdate(float _DeltaTime);

	void Cam2BStart();
	void Cam2BUpdate(float _DeltaTime);

	void Cam3Start();
	void Cam3Update(float _DeltaTime);

	void Cam5Start();
	void Cam5Update(float _DeltaTime);

	void OfficeLeftStart();
	void OfficeLeftUpdate(float _DeltaTime);


private:
	void BonnieMove();

	UStateManager State;
	UEngineRandom MoveChance;
	int BonnieCurPos = static_cast<int>(EBonniePos::ShowStage);
	int BonnieLevel = 0;
	float BonnieMTCheck = 3.0f;
	float MoveTime = 3.0f;
	bool IsBack = false;
};

