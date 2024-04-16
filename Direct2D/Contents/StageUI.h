#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class AStageUI : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AStageUI();
	~AStageUI();

	// delete Function
	AStageUI(const AStageUI& _Other) = delete;
	AStageUI(AStageUI&& _Other) noexcept = delete;
	AStageUI& operator=(const AStageUI& _Other) = delete;
	AStageUI& operator=(AStageUI&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* AMRenderer = nullptr;
	USpriteRenderer* TimeRenderer01 = nullptr;
	USpriteRenderer* TimeRenderer02 = nullptr;
	USpriteRenderer* NightRenderer = nullptr;
	USpriteRenderer* DayRenderer = nullptr;

	USpriteRenderer* PoewleftRenderer = nullptr;
	USpriteRenderer* PoewleftCheckRenderer01 = nullptr;
	USpriteRenderer* PoewleftCheckRenderer02 = nullptr;
	USpriteRenderer* PersentRenderer = nullptr;

	USpriteRenderer* UsageRenderer = nullptr;
	USpriteRenderer* PowerMeterRenderer = nullptr;

	USpriteRenderer* ChangeBarRenderer = nullptr;

};

