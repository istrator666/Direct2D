#pragma once
#include "EngineCore/Actor.h"

class Bonnie : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	Bonnie();
	~Bonnie();

	// delete Function
	Bonnie(const Bonnie& _Other) = delete;
	Bonnie(Bonnie&& _Other) noexcept = delete;
	Bonnie& operator=(const Bonnie& _Other) = delete;
	Bonnie& operator=(Bonnie&& _Other) noexcept = delete;

	void SetIsBonnie(bool _IsBonnie)
	{
		IsBonnie = _IsBonnie;
	}

	bool GetIsBonnie()
	{
		return IsBonnie;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	bool IsBonnie = false;

};

