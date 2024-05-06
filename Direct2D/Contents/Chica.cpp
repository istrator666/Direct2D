#include "PreCompile.h"
#include "Chica.h"
#include "PlayGameMode.h"

#include "DiningArea.h"
#include "EastHall.h"
#include "EHallCorner.h"
#include "Kitchen.h"
#include "Restrooms.h"
#include "TheOffice.h"

#include "RightButton.h"

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
	// CAM 1A = CAM 1B. (���Ͽʹ� �޸� �Ĵ��� �ǳʶ� �� ����) 
	// CAM 1B = CAM 7, CAM 6. 
	// CAM 7 = CAM 6, CAM 4A. 
	// CAM 6 = CAM 7, CAM 4A. 
	// CAM 4A = CAM 4B, CAM 1B. 
	// CAM 4B = CAM 4A, ����. 
	// ���� = �繫��, CAM 4A.
	// ġī�� CAM 6~���� �Դٰ� CAM 7�̳� 1B�� ���ư� ���� �� �ִ�. ��� ������ ������ CAM 4A�� ���ư���.
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
			IsBack = false;
			if (10 >= MoveDice)
			{
				AAnimatronics::PGameMode->GetDiningAreaCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetRestroomsCam()->SetAnimatronics(PGameMode->GetChica());
				ChicaCurPos = static_cast<int>(EChicaPos::Restrooms);
			}
			else
			{
				AAnimatronics::PGameMode->GetDiningAreaCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetKitchenCam()->SetAnimatronics(PGameMode->GetChica());
				ChicaCurPos = static_cast<int>(EChicaPos::Kitchen);
			}
			break;
		}
		case static_cast<int>(EChicaPos::EastHall):
		{
			if (16 >= MoveDice)
			{
				AAnimatronics::PGameMode->GetEastHallCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetEHallCornerCam()->SetAnimatronics(PGameMode->GetChica());
				ChicaCurPos = static_cast<int>(EChicaPos::EHallCorner);
			}
			else if (16 <= MoveDice && true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::DiningArea))
			{
				IsBack = true;
				AAnimatronics::PGameMode->GetEastHallCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetDiningAreaCam()->SetAnimatronics(PGameMode->GetChica());
				ChicaCurPos = static_cast<int>(EChicaPos::DiningArea);
			}
			break;
		}
		case static_cast<int>(EChicaPos::EHallCorner):
		{
			if (10 >= MoveDice)
			{
				AAnimatronics::PGameMode->GetEHallCornerCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetRButton()->SetLightAnimation(true, "RightChicaOn");
				AAnimatronics::PGameMode->GetRButton()->SetIsChica(true);
				ChicaCurPos = static_cast<int>(EChicaPos::RightOffice);
			}
			else
			{
				AAnimatronics::PGameMode->GetEHallCornerCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetEastHallCam()->SetAnimatronics(PGameMode->GetChica());
				ChicaCurPos = static_cast<int>(EChicaPos::EastHall);
			}
			break;
		}
		case static_cast<int>(EChicaPos::Kitchen):
		{
			if (10 >= MoveDice)
			{
				AAnimatronics::PGameMode->GetKitchenCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetRestroomsCam()->SetAnimatronics(PGameMode->GetChica());
				ChicaCurPos = static_cast<int>(EChicaPos::Restrooms);
			}
			else
			{
				AAnimatronics::PGameMode->GetKitchenCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetEastHallCam()->SetAnimatronics(PGameMode->GetChica());
				ChicaCurPos = static_cast<int>(EChicaPos::EastHall);
			}
			break;
		}
		case static_cast<int>(EChicaPos::Restrooms):
		{
			if (10 >= MoveDice)
			{
				AAnimatronics::PGameMode->GetRestroomsCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetKitchenCam()->SetAnimatronics(PGameMode->GetChica());
				ChicaCurPos = static_cast<int>(EChicaPos::Kitchen);
			}
			else
			{
				AAnimatronics::PGameMode->GetRestroomsCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetEastHallCam()->SetAnimatronics(PGameMode->GetChica());
				ChicaCurPos = static_cast<int>(EChicaPos::EastHall);
			}
			break;
		}
		case static_cast<int>(EChicaPos::RightOffice):
		{
			if (10 >= MoveDice && false == AAnimatronics::PGameMode->GetRButton()->GetIsCloseDoor())
			{
				AAnimatronics::PGameMode->GetTheOffice()->SetJumpScareAnimation("JumpScareChica");
			}
			else if (10 <= MoveDice 
				&& true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::EastHall)
				&& true == AAnimatronics::PGameMode->GetRButton()->GetIsCloseDoor())
			{
				AAnimatronics::PGameMode->GetRButton()->SetLightAnimation(true, "RightLightON");
				AAnimatronics::PGameMode->GetRButton()->SetIsChica(false);
				AAnimatronics::PGameMode->GetEastHallCam()->SetAnimatronics(PGameMode->GetChica());
				ChicaCurPos = static_cast<int>(EChicaPos::EastHall);
			}
			break;
		}
		}
	}
}
