#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>

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

	void SetTitleSelectPos(float _PosY)
	{
		TitleSelectRenderer->SetPosition(FVector(-500.0f, _PosY, 100.0f));
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* TitleBackgroundRenderer = nullptr;
	USpriteRenderer* NoiseRenderer = nullptr;
	USpriteRenderer* ScanLineRenderer = nullptr;
	USpriteRenderer* CameraEffectsRenderer = nullptr;
	USpriteRenderer* TitleNameRenderer = nullptr;
	USpriteRenderer* TitleSelectRenderer = nullptr;

	UCollision* ColStart = nullptr;
	UCollision* ColContinue = nullptr;

	UEngineRandom Random;

	float AccumulatedTime = 0.0f;
	float TitleBackTime = 0.0f;
	float ScanTime = 0.0f;
	float SpeedY = -5.0f;
	float DownLineSpeedY = 300.0f;

};

