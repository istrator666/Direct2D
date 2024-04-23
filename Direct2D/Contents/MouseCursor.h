#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

class APlayGameMode;
class ALeftButton;
class ARightButton;

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
	APlayGameMode* PGameMode = nullptr;
	std::shared_ptr<ALeftButton> LButton = nullptr;
	std::shared_ptr<ARightButton> RButton = nullptr;

	void SetMousePos();
	void ColLefButton();
	void ColRightButton();

	bool IsLDoor = false;
	bool IsLLight = false;
	bool IsRDoor = false;
	bool IsRLight = false;

};

