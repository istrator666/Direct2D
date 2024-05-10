#include "PreCompile.h"
#include "Bonnie.h"
#include "PlayGameMode.h"

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
}

void ABonnie::BonnieMove()
{
	// Bonnie 이동 방식
	// CAM 1A = CAM 1B, CAM 5. 
	// CAM 1B = CAM 5, CAM 2A.
	// CAM 5 = CAM 1B, CAM 2A.
	// CAM 3 = CAM 2A, 문앞.
	// CAM 2A = CAM 3, CAM 2B.
	// CAM 2B = CAM 3, 문앞.
	// 문앞 = 경비실, CAM 1B
	// 보니는 CAM 3 이내로 들어오면 CAM 5쪽으로는 돌아가지 않는다. 대신 공격을 막을시 CAM 1B로 멀리 돌아간다.

	int MoveDice = MoveChance.RandomInt(1, 20);
	
	if (BonnieLevel >= MoveChance.RandomInt(1, 20))
	{
		switch (BonnieCurPos)
		{
		case static_cast<int>(EBonniePos::ShowStage):
		{
			if (16 >= MoveDice && true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::DiningArea))
			{
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
			if (12 >= MoveDice && false == AAnimatronics::PGameMode->GetLButton()->GetIsCloseDoor())
			{
				AAnimatronics::PGameMode->SetCameraMoveActive(false);
				AAnimatronics::PGameMode->GetTheOffice()->SetJumpScareAnimation("JumpScareBonnie");
			}
			else if(12 <= MoveDice 
				&& true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::DiningArea) 
				&& true == AAnimatronics::PGameMode->GetLButton()->GetIsCloseDoor())
			{
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
