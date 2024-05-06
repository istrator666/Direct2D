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

	void SetLightAnimation(bool _Active, std::string_view _AniName)
	{
		RightLightAnimation->SetActive(_Active);
		RightLightAnimation->AnimationReset();
		RightLightAnimation->ChangeAnimation(_AniName);
	}

	void SetIsChica(bool _Chica)
	{
		IsChica = _Chica;
	}

	bool GetIsChica()
	{
		return IsChica;
	}

	void SetIsFreddy(bool _Freddy)
	{
		IsFreddy = _Freddy;
	}

	bool GetIsFreddy()
	{
		return IsFreddy;
	}

	void SetIsCloseDoor(bool _IsCloseDoor)
	{
		IsCloseDoor = _IsCloseDoor;
	}

	bool GetIsCloseDoor() const
	{
		return IsCloseDoor;
	}

	void SetRightColActive(bool _Active)
	{
		ColRightDoor->SetActive(_Active);
		ColRightLight->SetActive(_Active);
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

	bool IsChica = false;
	bool IsFreddy = false;
	bool IsCloseDoor = false;
};

