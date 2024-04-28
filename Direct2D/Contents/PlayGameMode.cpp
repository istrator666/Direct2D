#include "PreCompile.h"
#include "PlayGameMode.h"

#include "FisheyeEffect.h"

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
#include <EngineCore/DefaultSceneComponent.h>

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
	
	
	ChangeCCTV(_DeltaTime);
	ChangeCCTVMap();
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
	//MoveAreaRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

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

void APlayGameMode::ChangeCCTV(float _DeltaTime)
{
	if (true == CCTVUI->GetIsCCTV() && CCTVUI->GetIsChangeCCTV())
	{
		// 플레이어 이동 영역
		FastLeftMoveArea->SetActive(false);
		SlowLeftMoveArea->SetActive(false);
		FastRightMoveArea->SetActive(false);
		SlowRightMoveArea->SetActive(false);

		// CCTV Render
		StageCCTV->SetRendererActive(true);
		LeftButton->SetLeftColActvie(false);
		RightButton->SetRightColActive(false);

		if (false == IsCameraPosSave)
		{
			PrevCameraPos = Camera->GetActorLocation();
			Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
			IsCameraPosSave = true;
		}

		if (160 > static_cast<int>(Camera->GetActorLocation().X) && false == MoveChange)
		{
			Camera->AddActorLocation(FVector(0.1f, 0.0f, 0.0f));
		}
		else if (160 == static_cast<int>(Camera->GetActorLocation().X) && false == MoveChange)
		{
			CameraPauseCheckTime -= _DeltaTime;
			if (0 >= CameraPauseCheckTime)
			{
				MoveChange = true;
				CameraPauseCheckTime = 2.0f;
			}
		}
		
		if (-160 < static_cast<int>(Camera->GetActorLocation().X) && true == MoveChange)
		{
			Camera->AddActorLocation(FVector(-0.1f, 0.0f, 0.0f));
		}
		else if (-160 == static_cast<int>(Camera->GetActorLocation().X) && true == MoveChange)
		{
			CameraPauseCheckTime -= _DeltaTime;
			if (0 >= CameraPauseCheckTime)
			{
				MoveChange = false;
				CameraPauseCheckTime = 2.0f;
			}
		}
	}
	else if (false == CCTVUI->GetIsCCTV())
	{
		FastLeftMoveArea->SetActive(true);
		SlowLeftMoveArea->SetActive(true);
		FastRightMoveArea->SetActive(true);
		SlowRightMoveArea->SetActive(true);

		StageCCTV->SetRendererActive(false);
		LeftButton->SetLeftColActvie(true);
		RightButton->SetRightColActive(true);

		if (true == IsCameraPosSave)
		{
			Camera->SetActorLocation(PrevCameraPos);
			IsCameraPosSave = false;
		}
	}
}

void APlayGameMode::ChangeCCTVMap()
{
	std::string_view Map = CCTVUI->GetSelectMap();
	StageCCTV->SetStageCCTVRenderer(Map);
}
