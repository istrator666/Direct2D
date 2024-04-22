#pragma once
#include <EngineCore/GameMode.h>


// Ό³Έν :
class UImage;
class APlayGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	// constrcuter destructer
	APlayGameMode();
	~APlayGameMode();

	// delete Function
	APlayGameMode(const APlayGameMode& _Other) = delete;
	APlayGameMode(APlayGameMode&& _Other) noexcept = delete;
	APlayGameMode& operator=(const APlayGameMode& _Other) = delete;
	APlayGameMode& operator=(APlayGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<UCamera> Camera = nullptr;

	void SetActor();
	void SetUI();
	void CameraMove();
	void CCTVActive();

	bool IsCCTV = false;
	UImage* ChangeCCTVAnimation = nullptr;
	UImage* ChangeBarRenderer = nullptr;
	UImage* ChangeBarActiveArea = nullptr;

	UImage* FastLeftMoveArea = nullptr;
	UImage* SlowLeftMoveArea = nullptr;
	UImage* FastRightMoveArea = nullptr;
	UImage* SlowRightMoveArea = nullptr;

};

