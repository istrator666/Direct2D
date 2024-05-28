#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class USpriteRenderer;
class AGameOver : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AGameOver();
	~AGameOver();

	// delete Function
	AGameOver(const AGameOver& _Other) = delete;
	AGameOver(AGameOver&& _Other) noexcept = delete;
	AGameOver& operator=(const AGameOver& _Other) = delete;
	AGameOver& operator=(AGameOver&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* GameOverStaticRenderer = nullptr;
	USpriteRenderer* GameOverScanLineRenderer = nullptr;
};

