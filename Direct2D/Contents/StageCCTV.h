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

	void SetStageCCTVRenderer(std::string_view _SelectMap, int _Index);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UDefaultSceneComponent* CCTVRoot = nullptr;
	USpriteRenderer* StageCCTVRenderer = nullptr;
	USpriteRenderer* StaticRenderer = nullptr;

};

