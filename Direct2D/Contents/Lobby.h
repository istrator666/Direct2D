#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// Ό³Έν :
class ALobby : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ALobby();
	~ALobby();

	// delete Function
	ALobby(const ALobby& _Other) = delete;
	ALobby(ALobby&& _Other) noexcept = delete;
	ALobby& operator=(const ALobby& _Other) = delete;
	ALobby& operator=(ALobby&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* TheOfficeRenderer = nullptr;
	USpriteRenderer* FanRenderer = nullptr;

	void DebugMessageFunction();
};

