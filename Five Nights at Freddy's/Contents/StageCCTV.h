#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class UDefaultSceneComponent;
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

	void SetRendererActive(bool _Active);

	USpriteRenderer* GetRunningFoxy()
	{
		return RunningFoxy;
	}

	void AnimatronicsMove()
	{
		AnimatronicsMoveRenderer->SetActive(true);
		AnimatronicsMoveScanRenderer->AnimationReset();
		AnimatronicsMoveScanRenderer->ChangeAnimation("ScanLineAni");
		AnimatronicsMoveScanRenderer->SetActive(true);
		DelayCallBack(1.0f, [this]() { AnimatronicsMoveRenderer->SetActive(false), AnimatronicsMoveScanRenderer->SetActive(false); });
	}

	void SetStageCCTVRenderer(std::string_view _SelectMap, int _Index);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UDefaultSceneComponent* CCTVRoot = nullptr;
	USpriteRenderer* StageCCTVRenderer = nullptr;
	USpriteRenderer* AnimatronicsMoveRenderer = nullptr;
	USpriteRenderer * AnimatronicsMoveScanRenderer = nullptr;
	USpriteRenderer* KitchenBackRenderer = nullptr;
	USpriteRenderer* RunningFoxy = nullptr;
	USpriteRenderer* StaticRenderer = nullptr;

};

