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
	InputOn();
	PGameMode = dynamic_cast<APlayGameMode*>(GetWorld()->GetGameMode().get());

	// 우측 상단 시간 및 날짜 랜더
	{
		TimeUIRoot = CreateWidget<UImage>(GetWorld(), "TimeUIRoot");
		TimeUIRoot->AddToViewPort(1);

		WinChimeSound = UEngineSound::SoundPlay("WinChime.wav");
		WinChimeSound.SetVolume(0.5f);
		WinChimeSound.Off();

		WinChildrenSound = UEngineSound::SoundPlay("WinChildren.wav");
		WinChildrenSound.SetVolume(0.5f);
		WinChildrenSound.Off();

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

		MuteCallRenderer = CreateWidget<UImage>(GetWorld(), "DayRenderer");
		MuteCallRenderer->SetupAttachment(TimeUIRoot);
		MuteCallRenderer->AddToViewPort(1);
		MuteCallRenderer->SetSprite("UIMuteCall.png");
		MuteCallRenderer->SetAutoSize(1.0f, true);
		MuteCallRenderer->SetPosition({ -550, 320 });
		MuteCallRenderer->SetActive(false);

		NextDayBackRenderer = CreateWidget<UImage>(GetWorld(), "DayRenderer");
		NextDayBackRenderer->AddToViewPort(10);
		NextDayBackRenderer->SetSprite("DayBackground.png");
		NextDayBackRenderer->SetScale(FVector(1600.0f, 740.0f, -100.0f));
		NextDayBackRenderer->SetActive(false);

		NextDayTimeRenderer = CreateWidget<UImage>(GetWorld(), "DayRenderer");
		NextDayTimeRenderer->AddToViewPort(11);
		NextDayTimeRenderer->SetSprite("Miscellaneous", 1);
		NextDayTimeRenderer->SetAutoSize(1.0f, true);
		NextDayTimeRenderer->SetPosition({ -75, 0 });
		NextDayTimeRenderer->SetActive(false);

		NextDayAMRenderer = CreateWidget<UImage>(GetWorld(), "DayRenderer");
		NextDayAMRenderer->AddToViewPort(11);
		NextDayAMRenderer->SetSprite("Miscellaneous", 3);
		NextDayAMRenderer->SetAutoSize(1.0f, true);
		NextDayAMRenderer->SetPosition({ 50, 0 });
		NextDayAMRenderer->SetActive(false);

		EndingRenderer = CreateWidget<UImage>(GetWorld(), "DayRenderer");
		EndingRenderer->AddToViewPort(11);
		EndingRenderer->SetSprite("IntroEndings.png", 7);
		EndingRenderer->SetScale(FVector(1600.0f, 740.0f, -100.0f));
		EndingRenderer->SetActive(false);

		{
			MuteCallRenderer->SetHover([=]() 
				{
					if (IsDown(VK_LBUTTON))
					{
						// 안내 음성 on, off
					}
				});
		}
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

	if (1.0f >= UVMove.Y && true ==  NextDayTimeRenderer->IsActive())
	{
		UVMove.Y += _DeltaTime;
		DelayCallBack(0.5f, [this]() {NextDayTimeRenderer->SetSprite("Miscellaneous", 2); });
	}
	NextDayTimeRenderer->SetVertexUVPlus(UVMove);

	if (IsDown('6'))
	{
		DayTimeCheck = 3.0f;
		ResetTime = DayTimeCheck;
	}
}

void ATimeUI::TimeChange(float _DeltaTime)
{
	DayTimeCheck -= _DeltaTime;
	if (0 > DayTimeCheck)
	{
		DayTimeCheck = ResetTime;
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
			//if (6 >= DayRenderChage)
			//{
			//	++DayRenderChage;
			//	TimeRenderer01->SetActive(true);
			//	TimeRenderer02->SetSprite("Number", 2);
			//	TimeRenderChange = 0;
			//	DayRenderer->SetSprite("Number", DayRenderChage);
			//}

			if (6 >= DayRenderChage)
			{
				NextDayBackRenderer->SetActive(true);
				NextDayTimeRenderer->SetActive(true);
				NextDayAMRenderer->SetActive(true);
				WinChimeSound.On();
				WinChimeSound.Replay();
				++TimeRenderChange;
				DelayCallBack(3.0f, [this]() { NextDayBackRenderer->SetActive(false)
					, NextDayTimeRenderer->SetActive(false)
					, NextDayAMRenderer->SetActive(false)
					, PGameMode->SetIsGameOver(true)
					, EndingRenderer->SetActive(true)
					, WinChildrenSound.On()
					, WinChildrenSound.Replay(); });
			}
			break;
		case 6:
			break;
		default:
			break;
		}
	}
}
