#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

class AMouseCursor : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AMouseCursor();
	~AMouseCursor();

	// delete Function
	AMouseCursor(const AMouseCursor& _Other) = delete;
	AMouseCursor(AMouseCursor&& _Other) noexcept = delete;
	AMouseCursor& operator=(const AMouseCursor& _Other) = delete;
	AMouseCursor& operator=(AMouseCursor&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UCollision* ColMouse = nullptr;

	void SetMousePos();

};

