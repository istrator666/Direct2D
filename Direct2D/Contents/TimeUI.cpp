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
		UImage* AMRenderer = CreateWidget<UImage>(GetWorld(), "AMRenderer");
		AMRenderer->AddToViewPort(1);
		AMRenderer->SetSprite("AM.png");
		AMRenderer->SetAutoSize(1.0f, true);
		AMRenderer->SetPosition({ 575, 315 });

		UImage* TimeRenderer01 = CreateWidget<UImage>(GetWorld(), "TimeRenderer01");
		TimeRenderer01->AddToViewPort(1);
		TimeRenderer01->SetSprite("Number01.png");
		TimeRenderer01->SetAutoSize(1.3f, true);
		TimeRenderer01->SetPosition({ 500, 315 });

		UImage* TimeRenderer02 = CreateWidget<UImage>(GetWorld(), "TimeRenderer02");
		TimeRenderer02->AddToViewPort(1);
		TimeRenderer02->SetSprite("Number02.png");
		TimeRenderer02->SetAutoSize(1.3f, true);
		TimeRenderer02->SetPosition({ 525, 315 });

		UImage* NightRenderer = CreateWidget<UImage>(GetWorld(), "NightRenderer");
		NightRenderer->AddToViewPort(1);
		NightRenderer->SetSprite("Night.png");
		NightRenderer->SetAutoSize(1.0f, true);
		NightRenderer->SetPosition({ 535, 280 });

		UImage* DayRenderer = CreateWidget<UImage>(GetWorld(), "DayRenderer");
		DayRenderer->AddToViewPort(1);
		DayRenderer->SetSprite("Number01.png");
		DayRenderer->SetAutoSize(0.8f, true);
		DayRenderer->SetPosition({ 585, 280 });

	}
}

void ATimeUI::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
