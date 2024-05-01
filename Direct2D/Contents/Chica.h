#pragma once
#include "ContentsEnum.h"

#include "EngineCore/Actor.h"
#include <EngineBase/EngineRandom.h>

class AChica : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AChica();
	~AChica();

	// delete Function
	AChica(const AChica& _Other) = delete;
	AChica(AChica&& _Other) noexcept = delete;
	AChica& operator=(const AChica& _Other) = delete;
	AChica& operator=(AChica&& _Other) noexcept = delete;

	int GetChicaCurPos()
	{
		return ChicaCurPos;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void ChicaMove();

	UEngineRandom MoveChance;
	int ChicaCurPos = static_cast<int>(EChicaPos::ShowStage);
	int ChicaLevel = 0;
	float ChicaMTCheck = 5.0f;
	float MoveTime = 5.0f;
};

