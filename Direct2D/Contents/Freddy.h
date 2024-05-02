#pragma once
#include "ContentsEnum.h"

#include "Animatronics.h"
#include <EngineBase/EngineRandom.h>

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

private:
	void FreddyMove();

	UEngineRandom MoveChance;
	int FreddyCurPos = static_cast<int>(EFreddyPos::ShowStage);
	int FreddyLevel = 0;
	float FreddyMTCheck = 3.0f;
	float MoveTime = 3.0f;
};

