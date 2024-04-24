#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :
class UImage;
class UCamera;
class ATheOffice;
class AGameDay;
class AStageUI;
class AStageCCTV;
class ALeftButton;
class ARightButton;
class AMouseCursor;

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

	std::shared_ptr<ALeftButton> GetLButton()
	{
		return LeftButton;
	}

	std::shared_ptr<ARightButton> GetRButton()
	{
		return RightButton;
	}


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<UCamera> Camera = nullptr;
	std::shared_ptr<ATheOffice> Lobby = nullptr;
	std::shared_ptr<AGameDay> GameDay = nullptr;
	std::shared_ptr<AStageUI> StageUI = nullptr;
	std::shared_ptr<AStageCCTV> StageCCTV = nullptr;
	std::shared_ptr<ALeftButton> LeftButton = nullptr;
	std::shared_ptr<ARightButton> RightButton = nullptr;
	std::shared_ptr<AMouseCursor> MouseCursor = nullptr;

	void SetActor();
	void SetUI();
	void CameraMove();
	void CCTVActive();

	bool IsCCTV = false;
	UImage* ChangeCCTVAnimation = nullptr;
	UImage* ChangeBarRenderer = nullptr;
	UImage* ChangeBarActiveArea = nullptr;
	
	UImage* MuteCall = nullptr;

	UImage* RecordingMark = nullptr;
	UImage* CurMapName = nullptr;
	UImage* CCTVMap = nullptr;

	UImage* FastLeftMoveArea = nullptr;
	UImage* SlowLeftMoveArea = nullptr;
	UImage* FastRightMoveArea = nullptr;
	UImage* SlowRightMoveArea = nullptr;

};

