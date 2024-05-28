#pragma once
#include "EngineCore/Actor.h"

class APlayGameMode;
class AAnimatronics : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AAnimatronics();
	~AAnimatronics();

	// delete Function
	AAnimatronics(const AAnimatronics& _Other) = delete;
	AAnimatronics(AAnimatronics&& _Other) noexcept = delete;
	AAnimatronics& operator=(const AAnimatronics& _Other) = delete;
	AAnimatronics& operator=(AAnimatronics&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	APlayGameMode* PGameMode = nullptr;
private:
	

};

