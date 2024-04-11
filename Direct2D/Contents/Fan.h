#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class AFan : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AFan();
	~AFan();

	// delete Function
	AFan(const AFan& _Other) = delete;
	AFan(AFan&& _Other) noexcept = delete;
	AFan& operator=(const AFan& _Other) = delete;
	AFan& operator=(AFan&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* FanRenderer = nullptr;

};

