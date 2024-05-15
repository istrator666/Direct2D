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

private:
	void BonnieMove();

	UStateManager State;
	UEngineRandom MoveChance;
	int BonnieCurPos = static_cast<int>(EBonniePos::ShowStage);
	int BonnieLevel = 0;
	float BonnieMTCheck = 3.0f;
	float MoveTime = 3.0f;
	bool IsBack = false;
	bool IsBonnieDebug = false;
};

