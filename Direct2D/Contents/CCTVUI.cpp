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

	InputOn();
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

		// Cam 이미지
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

		Cam3.CamName = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam3.CamName->AddToViewPort(2);
		Cam3.CamName->SetSprite("Cam3.png");
		Cam3.CamName->SetAutoSize(1.0f, true);
		Cam3.CamName->SetPosition({ 245, -225 });

		Cam3.CamScreenBox = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam3.CamScreenBox->AddToViewPort(1);
		Cam3.CamScreenBox->CreateAnimation("NonSelect", "CCTV", 0.5f, true, 11, 11);
		Cam3.CamScreenBox->CreateAnimation("Select", "CCTV", 0.5f, true, 11, 12);
		Cam3.CamScreenBox->ChangeAnimation("NonSelect");
		Cam3.CamScreenBox->SetAutoSize(1.0f, true);
		Cam3.CamScreenBox->SetPosition({ 250, -225 });

		Cam4A.CamName = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam4A.CamName->AddToViewPort(2);
		Cam4A.CamName->SetSprite("Cam4A.png");
		Cam4A.CamName->SetAutoSize(1.0f, true);
		Cam4A.CamName->SetPosition({ 435, -240 });

		Cam4A.CamScreenBox = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam4A.CamScreenBox->AddToViewPort(1);
		Cam4A.CamScreenBox->CreateAnimation("NonSelect", "CCTV", 0.5f, true, 11, 11);
		Cam4A.CamScreenBox->CreateAnimation("Select", "CCTV", 0.5f, true, 11, 12);
		Cam4A.CamScreenBox->ChangeAnimation("NonSelect");
		Cam4A.CamScreenBox->SetAutoSize(1.0f, true);
		Cam4A.CamScreenBox->SetPosition({ 440, -240 });

		Cam4B.CamName = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam4B.CamName->AddToViewPort(2);
		Cam4B.CamName->SetSprite("Cam4B.png");
		Cam4B.CamName->SetAutoSize(1.0f, true);
		Cam4B.CamName->SetPosition({ 435, -280 });

		Cam4B.CamScreenBox = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam4B.CamScreenBox->AddToViewPort(1);
		Cam4B.CamScreenBox->CreateAnimation("NonSelect", "CCTV", 0.5f, true, 11, 11);
		Cam4B.CamScreenBox->CreateAnimation("Select", "CCTV", 0.5f, true, 11, 12);
		Cam4B.CamScreenBox->ChangeAnimation("NonSelect");
		Cam4B.CamScreenBox->SetAutoSize(1.0f, true);
		Cam4B.CamScreenBox->SetPosition({ 440, -280 });

		Cam5.CamName = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam5.CamName->AddToViewPort(2);
		Cam5.CamName->SetSprite("Cam5.png");
		Cam5.CamName->SetAutoSize(1.0f, true);
		Cam5.CamName->SetPosition({ 205, -73 });

		Cam5.CamScreenBox = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam5.CamScreenBox->AddToViewPort(1);
		Cam5.CamScreenBox->CreateAnimation("NonSelect", "CCTV", 0.5f, true, 11, 11);
		Cam5.CamScreenBox->CreateAnimation("Select", "CCTV", 0.5f, true, 11, 12);
		Cam5.CamScreenBox->ChangeAnimation("NonSelect");
		Cam5.CamScreenBox->SetAutoSize(1.0f, true);
		Cam5.CamScreenBox->SetPosition({ 210, -73 });

		Cam6.CamName = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam6.CamName->AddToViewPort(2);
		Cam6.CamName->SetSprite("Cam6.png");
		Cam6.CamName->SetAutoSize(1.0f, true);
		Cam6.CamName->SetPosition({ 535, -210 });

		Cam6.CamScreenBox = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam6.CamScreenBox->AddToViewPort(1);
		Cam6.CamScreenBox->CreateAnimation("NonSelect", "CCTV", 0.5f, true, 11, 11);
		Cam6.CamScreenBox->CreateAnimation("Select", "CCTV", 0.5f, true, 11, 12);
		Cam6.CamScreenBox->ChangeAnimation("NonSelect");
		Cam6.CamScreenBox->SetAutoSize(1.0f, true);
		Cam6.CamScreenBox->SetPosition({ 540, -210 });

		Cam7.CamName = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam7.CamName->AddToViewPort(2);
		Cam7.CamName->SetSprite("Cam7.png");
		Cam7.CamName->SetAutoSize(1.0f, true);
		Cam7.CamName->SetPosition({ 543, -75 });

		Cam7.CamScreenBox = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		Cam7.CamScreenBox->AddToViewPort(1);
		Cam7.CamScreenBox->CreateAnimation("NonSelect", "CCTV", 0.5f, true, 11, 11);
		Cam7.CamScreenBox->CreateAnimation("Select", "CCTV", 0.5f, true, 11, 12);
		Cam7.CamScreenBox->ChangeAnimation("NonSelect");
		Cam7.CamScreenBox->SetAutoSize(1.0f, true);
		Cam7.CamScreenBox->SetPosition({ 548, -75 });

		SelectScreenBox = Cam1A.CamScreenBox;

		Cam1A.CamScreenBox->SetHover([=]()
			{
				if (IsDown(VK_LBUTTON))
				{
					SwapSelectCam(Cam1A.CamScreenBox);
					CurMapName->SetSprite("MapName", ShowStage);
				}
			});

		Cam1B.CamScreenBox->SetHover([=]() 
			{
				if (IsDown(VK_LBUTTON))
				{
					SwapSelectCam(Cam1B.CamScreenBox);
					CurMapName->SetSprite("MapName", DiningArea);
				}
			});

		Cam1C.CamScreenBox->SetHover([=]()
			{
				if (IsDown(VK_LBUTTON))
				{
					SwapSelectCam(Cam1C.CamScreenBox);
					CurMapName->SetSprite("MapName", PirateCove);
				}
			});

		Cam2A.CamScreenBox->SetHover([=]()
			{
				if (IsDown(VK_LBUTTON))
				{
					SwapSelectCam(Cam2A.CamScreenBox);
					CurMapName->SetSprite("MapName", WestHall);
				}
			});

		Cam2B.CamScreenBox->SetHover([=]()
			{
				if (IsDown(VK_LBUTTON))
				{
					SwapSelectCam(Cam2B.CamScreenBox);
					CurMapName->SetSprite("MapName", WHallCorner);
				}
			});

		Cam3.CamScreenBox->SetHover([=]()
			{
				if (IsDown(VK_LBUTTON))
				{
					SwapSelectCam(Cam3.CamScreenBox);
					CurMapName->SetSprite("MapName", SupplyCloset);
				}
			});

		Cam4A.CamScreenBox->SetHover([=]()
			{
				if (IsDown(VK_LBUTTON))
				{
					SwapSelectCam(Cam4A.CamScreenBox);
					CurMapName->SetSprite("MapName", EastHall);
				}
			});

		Cam4B.CamScreenBox->SetHover([=]()
			{
				if (IsDown(VK_LBUTTON))
				{
					SwapSelectCam(Cam4B.CamScreenBox);
					CurMapName->SetSprite("MapName", EHallCorner);
				}
			});

		Cam5.CamScreenBox->SetHover([=]()
			{
				if (IsDown(VK_LBUTTON))
				{
					SwapSelectCam(Cam5.CamScreenBox);
					CurMapName->SetSprite("MapName", BackStage);
				}
			});

		Cam6.CamScreenBox->SetHover([=]()
			{
				if (IsDown(VK_LBUTTON))
				{
					SwapSelectCam(Cam6.CamScreenBox);
					CurMapName->SetSprite("MapName", Kitchen);
				}
			});

		Cam7.CamScreenBox->SetHover([=]()
			{
				if (IsDown(VK_LBUTTON))
				{
					SwapSelectCam(Cam7.CamScreenBox);
					CurMapName->SetSprite("MapName", Restrooms);
				}
			});

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

bool ACCTVUI::GetIsChangeCCTV()
{
	if (ChangeCCTVAnimation->IsCurAnimationEnd())
	{
		return true;
	}

	return false;
}

void ACCTVUI::SetCCTVUIRendererActvie()
{

}

void ACCTVUI::SwapSelectCam(UImage* _ChangeScreenBox)
{
	SelectScreenBox->ChangeAnimation("NonSelect");
	_ChangeScreenBox->ChangeAnimation("Select");
	SelectScreenBox = _ChangeScreenBox;
}