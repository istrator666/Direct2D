#pragma once
#include "ContentsEnum.h"

#include "EngineCore/Actor.h"
#include <EngineBase/EngineRandom.h>

class AFoxy : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AFoxy();
	~AFoxy();

	// delete Function
	AFoxy(const AFoxy& _Other) = delete;
	AFoxy(AFoxy&& _Other) noexcept = delete;
	AFoxy& operator=(const AFoxy& _Other) = delete;
	AFoxy& operator=(AFoxy&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void BonnieMove();

	UEngineRandom MoveChance;
	int BonnieCurPos = static_cast<int>(EFoxyPos::PirateCove);
	int BonnieLevel = 0;
	float BonnieMTCheck = 5.0f;
	float MoveTime = 5.0f;
};

