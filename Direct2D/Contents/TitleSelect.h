#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

class ATitleGameMode;
class ATitleMenu;

class ATitleSelect : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ATitleSelect();
	~ATitleSelect();

	// delete Function
	ATitleSelect(const ATitleSelect& _Other) = delete;
	ATitleSelect(ATitleSelect&& _Other) noexcept = delete;
	ATitleSelect& operator=(const ATitleSelect& _Other) = delete;
	ATitleSelect& operator=(ATitleSelect&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void SetMousePos();
	void ColSelectMenu();

	UCollision* ColMouse = nullptr;
	ATitleGameMode* TGameMode = nullptr;
	std::shared_ptr<ATitleMenu> TitleMenu = nullptr;

	bool IsMenuSwitchSound = false;

	UEngineSoundPlayer TitleMusic;
	UEngineSoundPlayer StaticLong;
	UEngineSoundPlayer MenuSwitchSound;

};

