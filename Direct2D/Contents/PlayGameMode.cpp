#include "PreCompile.h"
#include "PlayGameMode.h"

#include "FisheyeEffect.h"
#include "ContentsDefine.h"

#include "TheOffice.h"
#include "GameDay.h"
#include "StageUI.h"
#include "StageCCTV.h"
#include "LeftButton.h"
#include "RightButton.h"
#include "MouseCursor.h"

#include "TimeUI.h"
#include "BatteryUI.h"
#include "CCTVUI.h"

#include <EngineCore/Camera.h>
#include <EngineCore/Image.h>

APlayGameMode::APlayGameMode() 
{
}

APlayGameMode::~APlayGameMode() 
{
}

void APlayGameMode::BeginPlay() 
{
	Super::BeginPlay();

	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	SetActor();
	SetUI();

	GetWorld()->GetMainCamera()->GetCameraTarget()->AddEffect<UFisheyeEffect>();
}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	
	CameraMove();
}

void APlayGameMode::SetActor()
{
	// Stage Actor
	TheOffice = GetWorld()->SpawnActor<ATheOffice>("Lobby");
	//GameDay = GetWorld()->SpawnActor<AGameDay>("GameDay");
	StageCCTV = GetWorld()->SpawnActor<AStageCCTV>("StageCCTV");
	LeftButton = GetWorld()->SpawnActor<ALeftButton>("LeftButton");
	RightButton = GetWorld()->SpawnActor<ARightButton>("RightButton");
	MouseCursor = GetWorld()->SpawnActor<AMouseCursor>("MouseCursor");

	// UI Actor
	TimeUI = GetWorld()->SpawnActor<ATimeUI>("TimeUI");
	BatteryUI = GetWorld()->SpawnActor<ABatteryUI>("BatteryUI");
	CCTVUI = GetWorld()->SpawnActor<ACCTVUI>("CCTVUI");
}

void APlayGameMode::SetUI()
{
	// 카메라 움직일 투명벽
	{
		FastLeftMoveArea = CreateWidget<UImage>(GetWorld(), "FastLeftMoveArea");
		FastLeftMoveArea->AddToViewPort(1);
		FastLeftMoveArea->SetSprite("Transparency.png");
		FastLeftMoveArea->SetScale(FVector(250, 720));
		FastLeftMoveArea->SetPosition({ -520, 0 });

		SlowLeftMoveArea = CreateWidget<UImage>(GetWorld(), "SlowLeftMoveArea");
		SlowLeftMoveArea->AddToViewPort(1);
		SlowLeftMoveArea->SetSprite("Transparency.png");
		SlowLeftMoveArea->SetScale(FVector(250, 720));
		SlowLeftMoveArea->SetPosition({ -300, 0 });

		FastRightMoveArea = CreateWidget<UImage>(GetWorld(), "FastRightMoveArea");
		FastRightMoveArea->AddToViewPort(1);
		FastRightMoveArea->SetSprite("Transparency.png");
		FastRightMoveArea->SetScale(FVector(250, 720));
		FastRightMoveArea->SetPosition({ 520, 0 });

		SlowRightMoveArea = CreateWidget<UImage>(GetWorld(), "SlowRightMoveArea");
		SlowRightMoveArea->AddToViewPort(1);
		SlowRightMoveArea->SetSprite("Transparency.png");
		SlowRightMoveArea->SetScale(FVector(250, 720));
		SlowRightMoveArea->SetPosition({ 300, 0 });
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

	// MuteCall
	{

	}

	// 이미지 호버
	{
		FastLeftMoveArea->SetHover([=]()
			{
				if (-160.0f <= Camera->GetActorLocation().X)
				{
					Camera->AddActorLocation(FVector(-0.2f, 0.0f, 0.0f));
				}
			});

		SlowLeftMoveArea->SetHover([=]()
			{
				if (-160.0f <= Camera->GetActorLocation().X)
				{
					Camera->AddActorLocation(FVector(-0.1f, 0.0f, 0.0f));
				}
			});

		FastRightMoveArea->SetHover([=]()
			{
				if (160.0f >= Camera->GetActorLocation().X)
				{
					Camera->AddActorLocation(FVector(0.2f, 0.0f, 0.0f));
				}
			});

		SlowRightMoveArea->SetHover([=]()
			{
				if (160.0f >= Camera->GetActorLocation().X)
				{
					Camera->AddActorLocation(FVector(0.1f, 0.0f, 0.0f));
				}
			});
	}
}

void APlayGameMode::CameraMove()
{
	if (false == CCTVUI->GetIsCCTV())
	{
		FastLeftMoveArea->SetActive(true);
		SlowLeftMoveArea->SetActive(true);
		FastRightMoveArea->SetActive(true);
		SlowRightMoveArea->SetActive(true);
	}
	else if (true == CCTVUI->GetIsCCTV())
	{
		FastLeftMoveArea->SetActive(false);
		SlowLeftMoveArea->SetActive(false);
		FastRightMoveArea->SetActive(false);
		SlowRightMoveArea->SetActive(false);
	}
}
