#include "PreCompile.h"
#include "Chica.h"
#include "PlayGameMode.h"

#include "DiningArea.h"
#include "EastHall.h"
#include "EHallCorner.h"
#include "Kitchen.h"
#include "Restrooms.h"
#include "TheOffice.h"
#include "LeftButton.h"

#include <EngineBase/EngineRandom.h>

AChica::AChica()
{
}

AChica::~AChica()
{
}

void AChica::BeginPlay()
{
	Super::BeginPlay();
}

void AChica::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	ChicaMTCheck -= _DeltaTime;
	if (0 > ChicaMTCheck)
	{
		ChicaMTCheck = MoveTime;
		ChicaMove();
	}
}

void AChica::ChicaMove()
{
	// CAM 1A = CAM 1B. (보니와는 달리 식당을 건너뛸 수 없다) 
	// CAM 1B = CAM 7, CAM 6. 
	// CAM 7 = CAM 6, CAM 4A. 
	// CAM 6 = CAM 7, CAM 4A. 
	// CAM 4A = CAM 4B, CAM 1B. 
	// CAM 4B = CAM 4A, 문앞. 
	// 문앞 = 사무실, CAM 4A.
	// 치카는 CAM 6~까지 왔다가 CAM 7이나 1B로 돌아가 버릴 수 있다. 대신 공격을 막을시 CAM 4A로 돌아간다.
	int MoveDice = MoveChance.RandomInt(1, 20);

	if (ChicaLevel >= MoveChance.RandomInt(1, 20))
	{
		switch (ChicaCurPos)
		{
		case static_cast<int>(EChicaPos::ShowStage):
		{
			if (16 >= MoveDice && true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::DiningArea))
			{
				AAnimatronics::PGameMode->GetDiningAreaCam()->SetAnimatronics(PGameMode->GetChica());
				ChicaCurPos = static_cast<int>(EChicaPos::DiningArea);
			}
			break;
		}
		case static_cast<int>(EChicaPos::DiningArea):
		{
			if (10 >= MoveDice)
			{
				ChicaCurPos = static_cast<int>(EChicaPos::Restrooms);
			}
			else
			{
				ChicaCurPos = static_cast<int>(EChicaPos::Kitchen);
			}
			break;
		}
		case static_cast<int>(EChicaPos::Restrooms):
		{
			if (10 >= MoveDice)
			{
				ChicaCurPos = static_cast<int>(EChicaPos::Kitchen);
			}
			else
			{
				ChicaCurPos = static_cast<int>(EChicaPos::EastHall);
			}
			break;
		}

		case static_cast<int>(EChicaPos::Kitchen):
		{
			if (10 >= MoveDice)
			{
				ChicaCurPos = static_cast<int>(EChicaPos::Restrooms);
			}
			else
			{
				ChicaCurPos = static_cast<int>(EChicaPos::EastHall);
			}
			break;
		}
		case static_cast<int>(EChicaPos::EastHall):
		{
			if (16 >= MoveDice)
			{
				ChicaCurPos = static_cast<int>(EChicaPos::EHallCorner);
			}
			else if (16 <= MoveDice && true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::DiningArea))
			{
				AAnimatronics::PGameMode->GetDiningAreaCam()->SetAnimatronics(PGameMode->GetChica());
				ChicaCurPos = static_cast<int>(EChicaPos::DiningArea);
			}
			break;
		}
		case static_cast<int>(EChicaPos::EHallCorner):
		{
			if (10 >= MoveDice)
			{
				ChicaCurPos = static_cast<int>(EChicaPos::RightOffice);
			}
			else
			{
				ChicaCurPos = static_cast<int>(EChicaPos::EastHall);
			}
			break;
		}
		case static_cast<int>(EChicaPos::RightOffice):
		{
			if (10 >= MoveDice)
			{
				
			}
			else
			{
				ChicaCurPos = static_cast<int>(EChicaPos::EastHall);
			}
			break;
		}
		}
	}
}
