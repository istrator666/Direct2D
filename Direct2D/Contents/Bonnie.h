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

	bool GetIsBonnie();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	bool Bonnie1A = true;
	bool Bonnie1B = false;
	bool Bonnie2A = false;
	bool Bonnie2B = false;
	bool Bonnie3 = false;

};

