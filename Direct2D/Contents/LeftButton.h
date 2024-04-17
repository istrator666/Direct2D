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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* LeftButtonRenerer = nullptr;
	UCollision* ColLeftDoor = nullptr;
	UCollision* ColLeftLight = nullptr;

};

