#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class ARightButton : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ARightButton();
	~ARightButton();

	// delete Function
	ARightButton(const ARightButton& _Other) = delete;
	ARightButton(ARightButton&& _Other) noexcept = delete;
	ARightButton& operator=(const ARightButton& _Other) = delete;
	ARightButton& operator=(ARightButton&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* RightButtonRenerer = nullptr;

};

