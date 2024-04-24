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

	void SetButtonImage(int _index)
	{
		RightButtonRenderer->SetSprite("Buttons.png", _index);
	}

	void SetDoorAnimation(std::string_view _AnimationName)
	{
		RightDoorAnimation->SetActive(true);
		RightDoorAnimation->ChangeAnimation(_AnimationName);
	}

	void SetLightAnimation(bool _Active)
	{
		RightLightAnimation->SetActive(_Active);
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* RightButtonRenderer = nullptr;
	USpriteRenderer* RightDoorAnimation = nullptr;
	USpriteRenderer* RightLightAnimation = nullptr;
	UCollision* ColRightDoor = nullptr;
	UCollision* ColRightLight = nullptr;
};

