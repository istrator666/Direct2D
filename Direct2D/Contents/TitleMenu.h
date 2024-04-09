#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineRenderTarget.h>

// Ό³Έν :
class ATitleMenu : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ATitleMenu();
	~ATitleMenu();

	// delete Function
	ATitleMenu(const ATitleMenu& _Other) = delete;
	ATitleMenu(ATitleMenu&& _Other) noexcept = delete;
	ATitleMenu& operator=(const ATitleMenu& _Other) = delete;
	ATitleMenu& operator=(ATitleMenu&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* TitleRenderer = nullptr;
};

