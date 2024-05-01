#pragma once
#include "ContentsEnum.h"

#include "EngineCore/Actor.h"
#include <EngineBase/EngineRandom.h>


class ABonnie : public AActor
{
	GENERATED_BODY(AActor)

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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void BonnieMove();

	UEngineRandom MoveChance;
	int BonnieCurPos = static_cast<int>(EBonniePos::ShowStage);
	int BonnieLevel = 0;
	float BonnieMTCheck = 5.0f;
};

