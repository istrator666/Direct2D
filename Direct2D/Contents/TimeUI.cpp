#include "PreCompile.h"
#include "TimeUI.h"

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

		UImage* TimeRenderer01 = CreateWidget<UImage>(GetWorld(), "TimeRenderer01");
		TimeRenderer01->SetupAttachment(TimeUIRoot);
		TimeRenderer01->AddToViewPort(1);
		TimeRenderer01->SetSprite("Number", 1);
		TimeRenderer01->SetAutoSize(1.3f, true);
		TimeRenderer01->SetPosition({ 500, 315 });

		UImage* TimeRenderer02 = CreateWidget<UImage>(GetWorld(), "TimeRenderer02");
		TimeRenderer02->SetupAttachment(TimeUIRoot);
		TimeRenderer02->AddToViewPort(1);
		TimeRenderer02->SetSprite("Number", 2);
		TimeRenderer02->SetAutoSize(1.3f, true);
		TimeRenderer02->SetPosition({ 525, 315 });

		UImage* NightRenderer = CreateWidget<UImage>(GetWorld(), "NightRenderer");
		NightRenderer->SetupAttachment(TimeUIRoot);
		NightRenderer->AddToViewPort(1);
		NightRenderer->SetSprite("Night.png");
		NightRenderer->SetAutoSize(1.0f, true);
		NightRenderer->SetPosition({ 535, 280 });

		UImage* DayRenderer = CreateWidget<UImage>(GetWorld(), "DayRenderer");
		DayRenderer->SetupAttachment(TimeUIRoot);
		DayRenderer->AddToViewPort(1);
		DayRenderer->SetSprite("Number", 1);
		DayRenderer->SetAutoSize(0.8f, true);
		DayRenderer->SetPosition({ 585, 280 });

		//TimeUIRoot->SetActive(false);
	}
}

void ATimeUI::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
