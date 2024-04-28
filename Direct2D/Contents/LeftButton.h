#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class ALeftButton : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ALeftButton();
	~ALeftButton();

	// delete Function
	ALeftButton(const ALeftButton& _Other) = delete;
	ALeftButton(ALeftButton&& _Other) noexcept = delete;
	ALeftButton& operator=(const ALeftButton& _Other) = delete;
	ALeftButton& operator=(ALeftButton&& _Other) noexcept = delete;

	void SetButtonImage(int _index)
	{
		LeftButtonRenderer->SetSprite("Buttons.png", _index);
	}

	void SetDoorAnimation(std::string_view _AnimationName)
	{
		LeftDoorAnimation->SetActive(true);
		LeftDoorAnimation->ChangeAnimation(_AnimationName);
	}

	void SetLightAnimation(bool _Active)
	{
		LeftLightAnimation->SetActive(_Active);
	}

	void SetLeftColActvie(bool _Active)
	{
		ColLeftDoor->SetActive(_Active);
		ColLeftLight->SetActive(_Active);
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* LeftButtonRenderer = nullptr;
	USpriteRenderer* LeftDoorAnimation = nullptr;
	USpriteRenderer* LeftLightAnimation = nullptr;
	UCollision* ColLeftDoor = nullptr;
	UCollision* ColLeftLight = nullptr;

};

