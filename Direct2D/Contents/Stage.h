#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// Ό³Έν :
class AStage : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AStage();
	~AStage();

	// delete Function
	AStage(const AStage& _Other) = delete;
	AStage(AStage&& _Other) noexcept = delete;
	AStage& operator=(const AStage& _Other) = delete;
	AStage& operator=(AStage&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* TheOfficeRenderer = nullptr;
	USpriteRenderer* FanRenderer = nullptr;

	URenderer* TestRenderer = nullptr;

	void DebugMessageFunction();
};

