#include "PreCompile.h"
#include "TimeUI.h"
#include "PlayGameMode.h"

#include <EngineCore/Image.h>

ATimeUI::ATimeUI()
{

}

ATimeUI::~ATimeUI()
{
}

void ATimeUI::BeginPlay()
{
	Super::BeginPlay();
	PGameMode = dynamic_cast<APlayGameMode*>(GetWorld()->GetGameMode().get());

	// 우측 상단 시간 및 날짜 랜더
	{
		TimeUIRoot = CreateWidget<UImage>(GetWorld(), "TimeUIRoot");
		TimeUIRoot->AddToViewPort(1);

		UImage* AMRenderer = CreateWidget<UImage>(GetWorld(), "AMRenderer");
		AMRenderer->SetupAttachment(TimeUIRoot);
		AMRenderer->AddToViewPort(1);
		AMRenderer->SetSprite("AM.png");
		AMRenderer->SetAutoSize(1.0f, true);
		AMRenderer->SetPosition({ 575, 315 });
		AMRenderer->SetActive(true);

		TimeRenderer01 = CreateWidget<UImage>(GetWorld(), "TimeRenderer01");
		//TimeRenderer01->SetupAttachment(TimeUIRoot);
		TimeRenderer01->AddToViewPort(1);
		TimeRenderer01->SetSprite("Number", 1);
		TimeRenderer01->SetAutoSize(1.3f, true);
		TimeRenderer01->SetPosition({ 500, 315 });

		TimeRenderer02 = CreateWidget<UImage>(GetWorld(), "TimeRenderer02");
		TimeRenderer02->SetupAttachment(TimeUIRoot);
		TimeRenderer02->SetSprite("Number", 2);
		TimeRenderer02->AddToViewPort(1);
		TimeRenderer02->SetAutoSize(1.3f, true);
		TimeRenderer02->SetPosition({ 525, 315 });

		UImage* NightRenderer = CreateWidget<UImage>(GetWorld(), "NightRenderer");
		NightRenderer->SetupAttachment(TimeUIRoot);
		NightRenderer->AddToViewPort(1);
		NightRenderer->SetSprite("Night.png");
		NightRenderer->SetAutoSize(1.0f, true);
		NightRenderer->SetPosition({ 535, 280 });

		DayRenderer = CreateWidget<UImage>(GetWorld(), "DayRenderer");
		DayRenderer->SetupAttachment(TimeUIRoot);
		DayRenderer->AddToViewPort(1);
		DayRenderer->SetSprite("Number", DayRenderChage);
		DayRenderer->SetAutoSize(0.8f, true);
		DayRenderer->SetPosition({ 585, 280 });

		//TimeUIRoot->SetActive(false);
	}
}

void ATimeUI::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true != PGameMode->GetIsGameOver())
	{
		TimeChange(_DeltaTime);
	}
}

void ATimeUI::TimeChange(float _DeltaTime)
{
	DayTimeCheck -= _DeltaTime;
	if (0 > DayTimeCheck)
	{
		DayTimeCheck = 5.0f;
		switch (TimeRenderChange)
		{
		case 0:
			++TimeRenderChange;
			TimeRenderer01->SetActive(false);
			TimeRenderer02->SetSprite("Number", 1);
			break;
		case 1:
			++TimeRenderChange;
			TimeRenderer02->SetSprite("Number", 2);
			break;
		case 2:
			++TimeRenderChange;
			TimeRenderer02->SetSprite("Number", 3);
			break;
		case 3:
			++TimeRenderChange;
			TimeRenderer02->SetSprite("Number", 4);
			break;
		case 4:
			++TimeRenderChange;
			TimeRenderer02->SetSprite("Number", 5);
			break;
		case 5:
			if (6 >= DayRenderChage)
			{
				++DayRenderChage;
				TimeRenderer01->SetActive(true);
				TimeRenderer02->SetSprite("Number", 2);
				TimeRenderChange = 0;
				DayRenderer->SetSprite("Number", DayRenderChage);
			}
			break;
		default:
			break;
		}
	}
}
