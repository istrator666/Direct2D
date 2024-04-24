#include "PreCompile.h"
#include "CCTVUI.h"

#include "ContentsDefine.h"

#include "EngineCore/Image.h"

ACCTVUI::ACCTVUI()
{
}

ACCTVUI::~ACCTVUI()
{
}

void ACCTVUI::BeginPlay()
{
	Super::BeginPlay();

	// CCTV or 로비화면 전환 Bar
	{
		ChangeBarRenderer = CreateWidget<UImage>(GetWorld(), "ChangeBarRenderer");
		ChangeBarRenderer->AddToViewPort(1);
		ChangeBarRenderer->SetSprite("ChangeBar.png");
		ChangeBarRenderer->SetAutoSize(1.0f, true);
		ChangeBarRenderer->SetPosition({ -75, -310 });

		ChangeCCTVAnimation = CreateWidget<UImage>(GetWorld(), "ChangeCCTVAnimation");
		ChangeCCTVAnimation->AddToViewPort(1);
		ChangeCCTVAnimation->CreateAnimation("CCTVON", "Camera.png", 0.1f, false, 1, 10);
		ChangeCCTVAnimation->CreateAnimation("CCTVOFF", "Camera.png", 0.1f, false, 10, 0);
		ChangeCCTVAnimation->ChangeAnimation("CCTVON");
		ChangeCCTVAnimation->SetAutoSize(1.0f, true);
		ChangeCCTVAnimation->SetActive(false);

		ChangeBarActiveArea = CreateWidget<UImage>(GetWorld(), "ChangeBarActiveArea");
		ChangeBarActiveArea->AddToViewPort(1);
		ChangeBarActiveArea->SetSprite("Transparency.png");
		ChangeBarActiveArea->SetAutoSize(1.0f, true);
		ChangeBarActiveArea->SetPosition({ 0, -150 });
		ChangeBarActiveArea->SetActive(true);


		// 호버
		ChangeBarRenderer->SetHover([=]()
			{
				ChangeBarRenderer->SetActive(false);
				ChangeCCTVAnimation->SetActive(true);

				if (false == IsCCTV)
				{
					ChangeCCTVAnimation->ChangeAnimation("CCTVON");
					IsCCTV = true;
				}
				else if (true == IsCCTV)
				{
					ChangeCCTVAnimation->ChangeAnimation("CCTVOFF");
					IsCCTV = false;
				}
			});

		ChangeBarActiveArea->SetHover([=]()
			{
				if (false == ChangeBarRenderer->IsActive())
				{
					ChangeBarRenderer->SetActive(true);
				}
			});
	}

	// CCTV 전환 후 추가 UI 이미지
	{
		UImage* CCTVBorder = CreateWidget<UImage>(GetWorld(), "CCTVBorder");
		CCTVBorder->AddToViewPort(1);
		CCTVBorder->SetSprite("CCTVBorder.png");
		CCTVBorder->SetAutoSize(1.0f, true);
		CCTVBorder->SetPosition({ 0, 0 });
		CCTVBorder->SetActive(true);

		RecordingMark = CreateWidget<UImage>(GetWorld(), "RecordingMark");
		RecordingMark->AddToViewPort(1);
		RecordingMark->CreateAnimation("Recording", "Recording", 1.0f, true, 1, 0);
		RecordingMark->ChangeAnimation("Recording");
		RecordingMark->SetAutoSize(1.0f, true);
		RecordingMark->SetPosition({ -550, 280 });
		RecordingMark->SetActive(true);

		CurMapName = CreateWidget<UImage>(GetWorld(), "CurMapName");
		CurMapName->AddToViewPort(1);
		CurMapName->SetSprite("MapName", ShowStage);
		CurMapName->SetAutoSize(1.0f, true);
		CurMapName->SetPosition({ 300, 70 });
		CurMapName->SetActive(true);

		CCTVMap = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		CCTVMap->AddToViewPort(1);
		CCTVMap->CreateAnimation("CCTVMap", "CCTVMap", 1.0f, true, 0, 1);
		CCTVMap->ChangeAnimation("CCTVMap");
		CCTVMap->SetAutoSize(1.0f, true);
		CCTVMap->SetPosition({ 400, -150 });
		CCTVMap->SetActive(true);

		CamImage Cam1A;
		Cam1A.CamName = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam1A.CamName->AddToViewPort(2);
		Cam1A.CamName->SetSprite("cam1A.png");
		Cam1A.CamName->SetAutoSize(1.0f, true);
		Cam1A.CamName->SetPosition({ 325, 10 });

		Cam1A.CamScreenBox = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam1A.CamScreenBox->AddToViewPort(1);
		Cam1A.CamScreenBox->CreateAnimation("NonSelect", "CCTV", 0.5f, true, 11, 11);
		Cam1A.CamScreenBox->CreateAnimation("Select", "CCTV", 0.5f, true, 11, 12);
		Cam1A.CamScreenBox->ChangeAnimation("Select");
		Cam1A.CamScreenBox->SetAutoSize(1.0f, true);
		Cam1A.CamScreenBox->SetPosition({ 330, 10 });

		CamImage Cam1B;
		Cam1B.CamName = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam1B.CamName->AddToViewPort(2);
		Cam1B.CamName->SetSprite("cam1B.png");
		Cam1B.CamName->SetAutoSize(1.0f, true);
		Cam1B.CamName->SetPosition({ 310, -45 });

		Cam1B.CamScreenBox = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam1B.CamScreenBox->AddToViewPort(1);
		Cam1B.CamScreenBox->CreateAnimation("NonSelect", "CCTV", 0.5f, true, 11, 11);
		Cam1B.CamScreenBox->CreateAnimation("Select", "CCTV", 0.5f, true, 11, 12);
		Cam1B.CamScreenBox->ChangeAnimation("NonSelect");
		Cam1B.CamScreenBox->SetAutoSize(1.0f, true);
		Cam1B.CamScreenBox->SetPosition({ 315, -45 });

		CamImage Cam1C;
		Cam1C.CamName = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam1C.CamName->AddToViewPort(2);
		Cam1C.CamName->SetSprite("cam1C.png");
		Cam1C.CamName->SetAutoSize(1.0f, true);
		Cam1C.CamName->SetPosition({ 280, -125 });

		Cam1C.CamScreenBox = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam1C.CamScreenBox->AddToViewPort(1);
		Cam1C.CamScreenBox->CreateAnimation("NonSelect", "CCTV", 0.5f, true, 11, 11);
		Cam1C.CamScreenBox->CreateAnimation("Select", "CCTV", 0.5f, true, 11, 12);
		Cam1C.CamScreenBox->ChangeAnimation("NonSelect");
		Cam1C.CamScreenBox->SetAutoSize(1.0f, true);
		Cam1C.CamScreenBox->SetPosition({ 285, -125 });

		CamImage Cam2A;
		Cam2A.CamName = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam2A.CamName->AddToViewPort(2);
		Cam2A.CamName->SetSprite("cam2A.png");
		Cam2A.CamName->SetAutoSize(1.0f, true);
		Cam2A.CamName->SetPosition({ 330, -240 });

		Cam2A.CamScreenBox = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam2A.CamScreenBox->AddToViewPort(1);
		Cam2A.CamScreenBox->CreateAnimation("NonSelect", "CCTV", 0.5f, true, 11, 11);
		Cam2A.CamScreenBox->CreateAnimation("Select", "CCTV", 0.5f, true, 11, 12);
		Cam2A.CamScreenBox->ChangeAnimation("NonSelect");
		Cam2A.CamScreenBox->SetAutoSize(1.0f, true);
		Cam2A.CamScreenBox->SetPosition({ 335, -240 });

		CamImage Cam2B;
		Cam2B.CamName = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam2B.CamName->AddToViewPort(2);
		Cam2B.CamName->SetSprite("cam2B.png");
		Cam2B.CamName->SetAutoSize(1.0f, true);
		Cam2B.CamName->SetPosition({ 330, -280 });

		Cam2B.CamScreenBox = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam2B.CamScreenBox->AddToViewPort(1);
		Cam2B.CamScreenBox->CreateAnimation("NonSelect", "CCTV", 0.5f, true, 11, 11);
		Cam2B.CamScreenBox->CreateAnimation("Select", "CCTV", 0.5f, true, 11, 12);
		Cam2B.CamScreenBox->ChangeAnimation("NonSelect");
		Cam2B.CamScreenBox->SetAutoSize(1.0f, true);
		Cam2B.CamScreenBox->SetPosition({ 335, -280 });
	}
}

void ACCTVUI::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	CCTVActive();
}

void ACCTVUI::CCTVActive()
{
	if (ChangeCCTVAnimation->IsCurAnimationEnd())
	{
		ChangeCCTVAnimation->SetActive(false);
	}
}