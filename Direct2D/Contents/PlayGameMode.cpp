#include "PreCompile.h"
#include "PlayGameMode.h"
#include "Lobby.h"
#include "GameDay.h"
#include "StageUI.h"
#include "StageCCTV.h"
#include "LeftButton.h"
#include "RightButton.h"
#include "MouseCursor.h"
#include "FisheyeEffect.h"

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
	
	CCTVActive();
	CameraMove();
}

void APlayGameMode::SetActor()
{
	std::shared_ptr<ALobby> Lobby = GetWorld()->SpawnActor<ALobby>("Lobby");
	//std::shared_ptr<AGameDay> GameDay = GetWorld()->SpawnActor<AGameDay>("GameDay");
	//std::shared_ptr<AStageUI> StageUI = GetWorld()->SpawnActor<AStageUI>("StageUI");
	std::shared_ptr<AStageCCTV> StageCCTV = GetWorld()->SpawnActor<AStageCCTV>("StageCCTV");
	std::shared_ptr<ALeftButton> LeftButton = GetWorld()->SpawnActor<ALeftButton>("LeftButton");
	std::shared_ptr<ARightButton> RightButton = GetWorld()->SpawnActor<ARightButton>("RightButton");
	std::shared_ptr<AMouseCursor> MouseCursor = GetWorld()->SpawnActor<AMouseCursor>("MouseCursor");
}

void APlayGameMode::SetUI()
{
	// 우측 상단 시간 및 날짜 랜더
	{
		UImage* AMRenderer = CreateWidget<UImage>(GetWorld(), "AMRenderer");
		AMRenderer->AddToViewPort(1);
		AMRenderer->SetSprite("AM.png");
		AMRenderer->SetAutoSize(1.0f, true);
		AMRenderer->SetPosition({ 600, 325 });

		UImage* TimeRenderer01 = CreateWidget<UImage>(GetWorld(), "TimeRenderer01");
		TimeRenderer01->AddToViewPort(1);
		TimeRenderer01->SetSprite("Number01.png");
		TimeRenderer01->SetAutoSize(1.3f, true);
		TimeRenderer01->SetPosition({ 525, 325 });

		UImage* TimeRenderer02 = CreateWidget<UImage>(GetWorld(), "TimeRenderer02");
		TimeRenderer02->AddToViewPort(1);
		TimeRenderer02->SetSprite("Number02.png");
		TimeRenderer02->SetAutoSize(1.3f, true);
		TimeRenderer02->SetPosition({ 550, 325 });

		UImage* NightRenderer = CreateWidget<UImage>(GetWorld(), "NightRenderer");
		NightRenderer->AddToViewPort(1);
		NightRenderer->SetSprite("Night.png");
		NightRenderer->SetAutoSize(1.0f, true);
		NightRenderer->SetPosition({ 560, 290 });

		UImage* DayRenderer = CreateWidget<UImage>(GetWorld(), "DayRenderer");
		DayRenderer->AddToViewPort(1);
		DayRenderer->SetSprite("Number01.png");
		DayRenderer->SetAutoSize(0.8f, true);
		DayRenderer->SetPosition({ 610, 290 });

	}

	// 배터리 잔량 랜더
	{

		UImage* PoewleftRenderer = CreateWidget<UImage>(GetWorld(), "PoewleftRenderer");
		PoewleftRenderer->AddToViewPort(1);
		PoewleftRenderer->SetSprite("Powerleft.png");
		PoewleftRenderer->SetAutoSize(1.0f, true);
		PoewleftRenderer->SetPosition({ -530, -275 });

		UImage* PoewleftCheckRenderer01 = CreateWidget<UImage>(GetWorld(), "PoewleftCheckRenderer01");
		PoewleftCheckRenderer01->AddToViewPort(1);
		PoewleftCheckRenderer01->SetSprite("Number09.png");
		PoewleftCheckRenderer01->SetAutoSize(1.0f, true);
		PoewleftCheckRenderer01->SetPosition({ -440, -270 });

		UImage* PoewleftCheckRenderer02 = CreateWidget<UImage>(GetWorld(), "PoewleftCheckRenderer02");
		PoewleftCheckRenderer02->AddToViewPort(1);
		PoewleftCheckRenderer02->SetSprite("Number09.png");
		PoewleftCheckRenderer02->SetAutoSize(1.0f, true);
		PoewleftCheckRenderer02->SetPosition({ -420, -270 });

		UImage* PersentRenderer = CreateWidget<UImage>(GetWorld(), "PersentRenderer");
		PersentRenderer->AddToViewPort(1);
		PersentRenderer->SetSprite("Persent.png");
		PersentRenderer->SetAutoSize(1.0f, true);
		PersentRenderer->SetPosition({ -400, -270 });

	}

	// 배터리 사용량 랜더
	{
		UImage* UsageRenderer = CreateWidget<UImage>(GetWorld(), "UsageRenderer");
		UsageRenderer->AddToViewPort(1);
		UsageRenderer->SetSprite("Usage.png");
		UsageRenderer->SetAutoSize(1.0f, true);
		UsageRenderer->SetPosition({ -563, -315 });

		UImage* PowerMeterRenderer = CreateWidget<UImage>(GetWorld(), "PowerMeterRenderer");
		PowerMeterRenderer->AddToViewPort(1);
		PowerMeterRenderer->SetSprite("PowerMeter.png");
		PowerMeterRenderer->SetAutoSize(1.0f, true);
		PowerMeterRenderer->SetPosition({ -468, -315 });
	}

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
	}

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

	// 이미지 호버
	{
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

		FastLeftMoveArea->SetHover([=]()
			{
				if (-110.0f <= Camera->GetActorLocation().X)
				{
					Camera->AddActorLocation(FVector(-0.2f, 0.0f, 0.0f));
				}
			});

		SlowLeftMoveArea->SetHover([=]()
			{
				if (-110.0f <= Camera->GetActorLocation().X)
				{
					Camera->AddActorLocation(FVector(-0.1f, 0.0f, 0.0f));
				}
			});

		FastRightMoveArea->SetHover([=]()
			{
				if (110.0f >= Camera->GetActorLocation().X)
				{
					Camera->AddActorLocation(FVector(0.2f, 0.0f, 0.0f));
				}
			});

		SlowRightMoveArea->SetHover([=]()
			{
				if (110.0f >= Camera->GetActorLocation().X)
				{
					Camera->AddActorLocation(FVector(0.1f, 0.0f, 0.0f));
				}
			});
	}
}

void APlayGameMode::CameraMove()
{
	if (false == IsCCTV)
	{
		FastLeftMoveArea->SetActive(true);
		SlowLeftMoveArea->SetActive(true);
		FastRightMoveArea->SetActive(true);
		SlowRightMoveArea->SetActive(true);
	}
	else if (true == IsCCTV)
	{
		FastLeftMoveArea->SetActive(false);
		SlowLeftMoveArea->SetActive(false);
		FastRightMoveArea->SetActive(false);
		SlowRightMoveArea->SetActive(false);
	}
}

void APlayGameMode::CCTVActive()
{
	if (ChangeCCTVAnimation->IsCurAnimationEnd())
	{
		ChangeCCTVAnimation->SetActive(false);
	}
}
