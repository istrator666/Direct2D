#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class ATitleNoise : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ATitleNoise();
	~ATitleNoise();

	// delete Function
	ATitleNoise(const ATitleNoise& _Other) = delete;
	ATitleNoise(ATitleNoise&& _Other) noexcept = delete;
	ATitleNoise& operator=(const ATitleNoise& _Other) = delete;
	ATitleNoise& operator=(ATitleNoise&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* NoiseRenderer = nullptr;
};

