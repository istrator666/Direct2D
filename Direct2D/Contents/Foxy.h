#pragma once
#include "ContentsEnum.h"

#include "Animatronics.h"
#include <EngineBase/EngineRandom.h>

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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void FoxyMove();

	UEngineRandom MoveChance;
	int FoxyCurPos = static_cast<int>(EFoxyPos::PirateCove);
	int FoxyLevel = 0;
	float FoxyMTCheck = 5.0f;
	float MoveTime = 5.0f;
};

