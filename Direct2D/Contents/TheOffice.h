#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// Ό³Έν :
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

	void SetTheOfficeRender(int _Index)
	{
		TheOfficeRenderer->SetSprite("The Office", _Index);
	}

	void SetJumpScareAnimation(std::string_view _JumpScareName)
	{
		JumpScareRenderer->ChangeAnimation(_JumpScareName);
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* TheOfficeRenderer = nullptr;
	USpriteRenderer* FanRenderer = nullptr;
	USpriteRenderer* JumpScareRenderer = nullptr;

	UEngineSoundPlayer TheOfficeSound;

	void DebugMessageFunction();
};

