#include "PreCompile.h"
#include "BatteryUI.h"

#include "EngineCore/Image.h"

ABatteryUI::ABatteryUI()
{
}

ABatteryUI::~ABatteryUI()
{
}

void ABatteryUI::BeginPlay()
{
	Super::BeginPlay();

	// 배터리 잔량 랜더
	{

		UImage* PowerleftRenderer = CreateWidget<UImage>(GetWorld(), "PoewleftRenderer");
		PowerleftRenderer->AddToViewPort(1);
		PowerleftRenderer->SetSprite("Powerleft.png");
		PowerleftRenderer->SetAutoSize(1.0f, true);
		PowerleftRenderer->SetPosition({ -530, -275 });

		UImage* PowerleftCheckRenderer01 = CreateWidget<UImage>(GetWorld(), "PoewleftCheckRenderer01");
		PowerleftCheckRenderer01->AddToViewPort(1);
		PowerleftCheckRenderer01->SetSprite("Number09.png");
		PowerleftCheckRenderer01->SetAutoSize(1.0f, true);
		PowerleftCheckRenderer01->SetPosition({ -440, -270 });

		UImage* PowerleftCheckRenderer02 = CreateWidget<UImage>(GetWorld(), "PoewleftCheckRenderer02");
		PowerleftCheckRenderer02->AddToViewPort(1);
		PowerleftCheckRenderer02->SetSprite("Number09.png");
		PowerleftCheckRenderer02->SetAutoSize(1.0f, true);
		PowerleftCheckRenderer02->SetPosition({ -420, -270 });

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
}

void ABatteryUI::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
