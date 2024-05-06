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
	//// State 생성
	//State.CreateState("Cam1A");
	//State.CreateState("Cam1B");
	//State.CreateState("Cam2A");
	//State.CreateState("Cam2B");
	//State.CreateState("Cam3");
	//State.CreateState("Cam5");
	//State.CreateState("OfficeLeft");

	//// State Start 셋팅
	//State.SetStartFunction("Cam1A", std::bind(&ABonnie::Cam1AStart, this));
	//State.SetStartFunction("Cam1B", std::bind(&ABonnie::Cam1BStart, this));
	//State.SetStartFunction("Cam2A", std::bind(&ABonnie::Cam2AStart, this));
	//State.SetStartFunction("Cam2B", std::bind(&ABonnie::Cam2BStart, this));
	//State.SetStartFunction("Cam3", std::bind(&ABonnie::Cam3Start, this));
	//State.SetStartFunction("Cam5", std::bind(&ABonnie::Cam5Start, this));
	//State.SetStartFunction("OfficeLeft", std::bind(&ABonnie::OfficeLeftStart, this));
	//
	//// State Update 세팅
	//State.SetUpdateFunction("Cam1A", std::bind(&ABonnie::Cam1AUpdate, this, std::placeholders::_1));
	//State.SetUpdateFunction("Cam1B", std::bind(&ABonnie::Cam1BUpdate, this, std::placeholders::_1));
	//State.SetUpdateFunction("Cam2A", std::bind(&ABonnie::Cam2AUpdate, this, std::placeholders::_1));
	//State.SetUpdateFunction("Cam2B", std::bind(&ABonnie::Cam2BUpdate, this, std::placeholders::_1));
	//State.SetUpdateFunction("Cam3", std::bind(&ABonnie::Cam3Update, this, std::placeholders::_1));
	//State.SetUpdateFunction("Cam5", std::bind(&ABonnie::Cam5Update, this, std::placeholders::_1));
	//State.SetUpdateFunction("OfficeLeft", std::bind(&ABonnie::OfficeLeftUpdate, this, std::placeholders::_1));
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
		//State.Update(_DeltaTime);
	}
}

void ABonnie::Cam1AStart()
{
}

void ABonnie::Cam1AUpdate(float _DeltaTime)
{
}

void ABonnie::Cam1BStart()
{
}

void ABonnie::Cam1BUpdate(float _DeltaTime)
{
}

void ABonnie::Cam2AStart()
{
}

void ABonnie::Cam2AUpdate(float _DeltaTime)
{
}

void ABonnie::Cam2BStart()
{
}

void ABonnie::Cam2BUpdate(float _DeltaTime)
{
}

void ABonnie::Cam3Start()
{
}

void ABonnie::Cam3Update(float _DeltaTime)
{
}

void ABonnie::Cam5Start()
{
}

void ABonnie::Cam5Update(float _DeltaTime)
{
}

void ABonnie::OfficeLeftStart()
{
}

void ABonnie::OfficeLeftUpdate(float _DeltaTime)
{
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
				AAnimatronics::PGameMode->GetLButton()->SetLightAnimation(true, "LeftBonnieON");
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
				AAnimatronics::PGameMode->GetLButton()->SetLightAnimation(true, "LeftBonnieON");
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
