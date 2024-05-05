#pragma once
#include <EngineCore/GameMode.h>
#include "ContentsEnum.h"

// 설명 :
class UImage;
class UCamera;
class ATheOffice;
class AGameDay;
class AStageCCTV;
class ALeftButton;
class ARightButton;
class AMouseCursor;

class ABonnie;
class AChica;
class AFoxy;
class AFreddy;

class AShowStage;
class ADiningArea;
class APirateCove;
class AWestHall;
class AWHallCorner;
class ASupplyCloset;
class AEastHall;
class AEHallCorner;
class ABackStage;
class AKitchen;
class ARestrooms;

class ATimeUI;
class ABatteryUI;
class ACCTVUI;

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

	std::string_view GetCurCam()
	{
		return Map;
	}

	std::shared_ptr<ADiningArea> GetDiningAreaCam()
	{
		return DiningAreaCam;
	}
	
	std::shared_ptr<ABackStage> GetBackStageCam()
	{
		return BackStageCam;
	}

	std::shared_ptr<AWestHall> GetWestHallCam()
	{
		return WestHallCam;
	}

	std::shared_ptr<AWHallCorner> GetWHallCornerCam()
	{
		return WHallCornerCam;
	}

	std::shared_ptr<ASupplyCloset> GetSupplyClosetCam()
	{
		return SupplyClosetCam;
	}

	std::shared_ptr<ATheOffice> GetTheOffice()
	{
		return TheOffice;
	}

	std::shared_ptr<ABonnie> GetBonnie()
	{
		return Bonnie;
	}

	std::shared_ptr<AChica> GetChica()
	{
		return Chica;
	}

	bool GetIsMapAnimatronics(ECamMap _RoomName);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	// Stage Actor
	std::shared_ptr<UCamera> Camera = nullptr;
	std::shared_ptr<ATheOffice> TheOffice = nullptr;
	std::shared_ptr<AGameDay> GameDay = nullptr;
	std::shared_ptr<AStageCCTV> StageCCTV = nullptr;
	std::shared_ptr<ALeftButton> LeftButton = nullptr;
	std::shared_ptr<ARightButton> RightButton = nullptr;
	std::shared_ptr<AMouseCursor> MouseCursor = nullptr;

	//Cam
	std::string_view Map;
	std::shared_ptr<AShowStage> ShowStageCam = nullptr;
	std::shared_ptr<ADiningArea> DiningAreaCam = nullptr;
	std::shared_ptr<APirateCove> PirateCoveCam = nullptr;
	std::shared_ptr<AWestHall> WestHallCam = nullptr;
	std::shared_ptr<AWHallCorner> WHallCornerCam = nullptr;
	std::shared_ptr<ASupplyCloset> SupplyClosetCam = nullptr;
	std::shared_ptr<AEastHall> EastHallCam = nullptr;
	std::shared_ptr<AEHallCorner> EHallCornerCam = nullptr;
	std::shared_ptr<ABackStage> BackStageCam = nullptr;
	std::shared_ptr<AKitchen> KitchenCam = nullptr;
	std::shared_ptr<ARestrooms> RestroomsCam = nullptr;

	// 몬스터
	std::shared_ptr<ABonnie> Bonnie = nullptr;
	std::shared_ptr<AChica> Chica = nullptr;
	std::shared_ptr<AFoxy> Foxy = nullptr;
	std::shared_ptr<AFreddy> Freddy = nullptr;

	// UI Actor
	std::shared_ptr<ATimeUI> TimeUI = nullptr;
	std::shared_ptr<ABatteryUI> BatteryUI = nullptr;
	std::shared_ptr<ACCTVUI> CCTVUI = nullptr;

	void SetActor();
	void SetUI();
	void ChangeCCTV(float _DeltaTime);
	void ChangeCCTVMap();
	void CamCameraReset();
	
	UImage* MuteCall = nullptr;
	
	//UDefaultSceneComponent* MoveAreaRoot = nullptr;
	UImage* FastLeftMoveArea = nullptr;
	UImage* SlowLeftMoveArea = nullptr;
	UImage* FastRightMoveArea = nullptr;
	UImage* SlowRightMoveArea = nullptr;

	FVector PrevCameraPos;
	bool IsCameraPosSave = false;
	bool MoveChange = false;
	float CameraPauseCheckTime = 2.0f;

};

