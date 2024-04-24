#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// ���� :
class ATheOffice : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ATheOffice();
	~ATheOffice();

	// delete Function
	ATheOffice(const ATheOffice& _Other) = delete;
	ATheOffice(ATheOffice&& _Other) noexcept = delete;
	ATheOffice& operator=(const ATheOffice& _Other) = delete;
	ATheOffice& operator=(ATheOffice&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* TheOfficeRenderer = nullptr;
	USpriteRenderer* FanRenderer = nullptr;

	void DebugMessageFunction();
};
