#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class AStageCCTV : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AStageCCTV();
	~AStageCCTV();

	// delete Function
	AStageCCTV(const AStageCCTV& _Other) = delete;
	AStageCCTV(AStageCCTV&& _Other) noexcept = delete;
	AStageCCTV& operator=(const AStageCCTV& _Other) = delete;
	AStageCCTV& operator=(AStageCCTV&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* CCTVRenderer = nullptr;

};

