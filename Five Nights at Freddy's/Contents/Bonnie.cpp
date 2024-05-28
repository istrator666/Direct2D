#include "PreCompile.h"
#include "Bonnie.h"
#include "PlayGameMode.h"
#include "StageCCTV.h"

#include "DiningArea.h"
#include "BackStage.h"
#include "WestHall.h"
#include "WHallCorner.h"
#include "SupplyCloset.h"
#include "TheOffice.h"

#include "LeftButton.h"

#include <EngineBase/EngineRandom.h>

ABonnie::ABonnie()
{
}

ABonnie::~ABonnie()
{
}

void ABonnie::BeginPlay()
{
	Super::BeginPlay();
	InputOn();

	MoveSound = UEngineSound::SoundPlay("BonnieChicaMove.wav");
	MoveSound.SetVolume(0.5f);
	MoveSound.Off();

	JumpScareSound = UEngineSound::SoundPlay("JumpScare.wav");
	JumpScareSound.SetVolume(0.3f);
	JumpScareSound.Off();
}

void ABonnie::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	BonnieMTCheck -= _DeltaTime;
	if (0 > BonnieMTCheck)
	{
		BonnieMTCheck = MoveTime;
		BonnieMove();
	}

	if (IsDown('1') && false == IsBonnieDebug)
	{
		IsBonnieDebug = true;
		BonnieLevel = 15;
	}
	else if (IsDown('1') && true == IsBonnieDebug)
	{
		IsBonnieDebug = false;
		BonnieLevel = 0;
	}
}

void ABonnie::BonnieMove()
{
	// Bonnie �̵� ���
	// CAM 1A = CAM 1B, CAM 5. 
	// CAM 1B = CAM 5, CAM 2A.
	// CAM 5 = CAM 1B, CAM 2A.
	// CAM 3 = CAM 2A, ����.
	// CAM 2A = CAM 3, CAM 2B.
	// CAM 2B = CAM 3, ����.
	// ���� = ����, CAM 1B
	// ���ϴ� CAM 3 �̳��� ������ CAM 5�����δ� ���ư��� �ʴ´�. ��� ������ ������ CAM 1B�� �ָ� ���ư���.

	int MoveDice = MoveChance.RandomInt(1, 20);
	
	if (BonnieLevel >= MoveChance.RandomInt(1, 20))
	{
		switch (BonnieCurPos)
		{
		case static_cast<int>(EBonniePos::ShowStage):
		{
			if (16 >= MoveDice && true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::DiningArea))
			{
				// ķ == �̵� �� ����
				//AAnimatronics::PGameMode->GetStageCCTV()->AnimatronicsMove();
				AAnimatronics::PGameMode->GetDiningAreaCam()->SetAnimatronics(PGameMode->GetBonnie());
				BonnieCurPos = static_cast<int>(EBonniePos::DiningArea);
			}
			else if (16 <= MoveDice && true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::BackStage))
			{
				IsBack = false;
				AAnimatronics::PGameMode->GetBackStageCam()->SetAnimatronics(PGameMode->GetBonnie());
				BonnieCurPos = static_cast<int>(EBonniePos::BackStage);
			}
			break;
		}
		case static_cast<int>(EBonniePos::DiningArea):
		{
			MoveSound.Off();
			if (16 >= MoveDice && true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::WestHall))
			{
				AAnimatronics::PGameMode->GetDiningAreaCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetWestHallCam()->SetAnimatronics(PGameMode->GetBonnie());
				BonnieCurPos = static_cast<int>(EBonniePos::WestHall);
			}
			else if (16 <= MoveDice && true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::BackStage))
			{
				AAnimatronics::PGameMode->GetDiningAreaCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetBackStageCam()->SetAnimatronics(PGameMode->GetBonnie());
				BonnieCurPos = static_cast<int>(EBonniePos::BackStage);
			}
			break;
		}
		case static_cast<int>(EBonniePos::WestHall):
		{
			if (16 >= MoveDice  && true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::WHallCorner))
			{
				AAnimatronics::PGameMode->GetWestHallCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetWHallCornerCam()->SetAnimatronics(PGameMode->GetBonnie());
				BonnieCurPos = static_cast<int>(EBonniePos::WHallCorner);
			}
			else if (16 <= MoveDice && true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::SupplyCloset))
			{
				AAnimatronics::PGameMode->GetWestHallCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetSupplyClosetCam()->SetAnimatronics(PGameMode->GetBonnie());
				BonnieCurPos = static_cast<int>(EBonniePos::SupplyCloset);
			}
			break;
		}

		case static_cast<int>(EBonniePos::WHallCorner):
		{
			if (16 >= MoveDice)
			{
				AAnimatronics::PGameMode->GetWHallCornerCam()->SetAnimatronics(nullptr);
				if (false == PGameMode->GetLButton()->GetIsLight())
				{
					AAnimatronics::PGameMode->GetLButton()->SetLightAnimation(false, "LeftBonnieON");
				}
				else
				{
					AAnimatronics::PGameMode->GetLButton()->SetLightAnimation(true, "LeftBonnieON");
				}
				AAnimatronics::PGameMode->GetLButton()->SetIsBonnie(true);
				BonnieCurPos = static_cast<int>(EBonniePos::LeftOffice);
				MoveSound.On();
				MoveSound.Replay();
			}
			else if (16 <= MoveDice && true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::SupplyCloset))
			{
				AAnimatronics::PGameMode->GetWHallCornerCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetSupplyClosetCam()->SetAnimatronics(PGameMode->GetBonnie());
				BonnieCurPos = static_cast<int>(EBonniePos::SupplyCloset);
			}
			break;
		}
		case static_cast<int>(EBonniePos::SupplyCloset):
		{
			if (16 >= MoveDice)
			{
				AAnimatronics::PGameMode->GetSupplyClosetCam()->SetAnimatronics(nullptr);
				if (false == PGameMode->GetLButton()->GetIsLight())
				{
					AAnimatronics::PGameMode->GetLButton()->SetLightAnimation(false, "LeftBonnieON");
				}
				else
				{
					AAnimatronics::PGameMode->GetLButton()->SetLightAnimation(true, "LeftBonnieON");
				}
				AAnimatronics::PGameMode->GetLButton()->SetIsBonnie(true);
				BonnieCurPos = static_cast<int>(EBonniePos::LeftOffice);
				MoveSound.On();
				MoveSound.Replay();
			}
			else if (16 <= MoveDice && true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::WestHall))
			{
				AAnimatronics::PGameMode->GetSupplyClosetCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetWestHallCam()->SetAnimatronics(PGameMode->GetBonnie());
				BonnieCurPos = static_cast<int>(EBonniePos::WestHall);
			}
			break;
		}
		case static_cast<int>(EBonniePos::BackStage):
		{
			if (10 >= MoveDice && true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::DiningArea))
			{
				IsBack = true;
				AAnimatronics::PGameMode->GetBackStageCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetDiningAreaCam()->SetAnimatronics(PGameMode->GetBonnie());
				BonnieCurPos = static_cast<int>(EBonniePos::DiningArea);
			}
			else if (10 <= MoveDice && true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::WestHall))
			{
				AAnimatronics::PGameMode->GetBackStageCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetWestHallCam()->SetAnimatronics(PGameMode->GetBonnie());
				BonnieCurPos = static_cast<int>(EBonniePos::WestHall);
			}
			break;
		}
		case static_cast<int>(EBonniePos::LeftOffice):
		{
			MoveSound.Off();
			if (12 >= MoveDice && false == AAnimatronics::PGameMode->GetLButton()->GetIsCloseDoor())
			{
				JumpScareSound.On();
				JumpScareSound.Replay();
				AAnimatronics::PGameMode->SetCameraMoveActive(false);
				AAnimatronics::PGameMode->GetTheOffice()->SetJumpScareAnimation("JumpScareBonnie");
				DelayCallBack(3.0f, [this]() { GEngine->ChangeLevel("GameOverLevel"); });
			}
			else if(12 <= MoveDice 
				&& true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::DiningArea) 
				&& true == AAnimatronics::PGameMode->GetLButton()->GetIsCloseDoor())
			{
				MoveSound.On();
				MoveSound.Replay();
				IsBack = true;
				AAnimatronics::PGameMode->GetLButton()->SetLightAnimation(true, "LeftLightON");
				AAnimatronics::PGameMode->GetLButton()->SetIsBonnie(false);
				AAnimatronics::PGameMode->GetDiningAreaCam()->SetAnimatronics(PGameMode->GetBonnie());
				BonnieCurPos = static_cast<int>(EBonniePos::DiningArea);
			}
			break;
		}
		}
	}
}