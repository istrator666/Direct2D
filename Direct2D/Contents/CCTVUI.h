#pragma once
#include "EngineCore/Actor.h"

class UImage;
struct CamImage
{
	UImage* CamScreenBox = nullptr;
	UImage* CamName = nullptr;
};


class ACCTVUI : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ACCTVUI();
	~ACCTVUI();

	// delete Function
	ACCTVUI(const ACCTVUI& _Other) = delete;
	ACCTVUI(ACCTVUI&& _Other) noexcept = delete;
	ACCTVUI& operator=(const ACCTVUI& _Other) = delete;
	ACCTVUI& operator=(ACCTVUI&& _Other) noexcept = delete;

	bool GetIsCCTV()
	{
		return IsCCTV;
	}

	bool GetIsChangeCCTV();

	void SetCCTVUIRendererActvie(bool _Active);

	std::string_view GetSelectMap()
	{
		return SelectMap;
	}

	void SetCamCameraReset(bool _CamCameraReset)
	{
		CamCameraReset = _CamCameraReset;
	}

	bool GetCamCameraReset()
	{
		return CamCameraReset;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void CCTVActive();
	void SwapSelectCam(UImage* _ChangeScreenBox);

	bool IsCCTV = false;
	bool CamCameraReset = false;
	UImage* ChangeCCTVAnimation = nullptr;
	UImage* ChangeBarRenderer = nullptr;
	UImage* ChangeBarActiveArea = nullptr;

	UImage* CCTVRoot = nullptr;
	UImage* RecordingMark = nullptr;
	UImage* CurMapName = nullptr;
	UImage* CCTVMap = nullptr;

	CamImage Cam1A;
	CamImage Cam1B;
	CamImage Cam1C;
	CamImage Cam2A;
	CamImage Cam2B;
	CamImage Cam3;
	CamImage Cam4A;
	CamImage Cam4B;
	CamImage Cam5;
	CamImage Cam6;
	CamImage Cam7;

	UImage* SelectScreenBox;
	std::string_view SelectMap = "ShowStage";
};

