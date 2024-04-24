#include "PreCompile.h"
#include "CCTVUI.h"

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