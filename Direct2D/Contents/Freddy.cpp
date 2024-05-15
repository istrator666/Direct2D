#include "PreCompile.h"
#include "Freddy.h"
#include "Bonnie.h"
#include "Chica.h"

#include "PlayGameMode.h"

#include "DiningArea.h"
#include "EastHall.h"
#include "EHallCorner.h"
#include "Kitchen.h"
#include "Restrooms.h"
#include "TheOffice.h"

#include "RightButton.h"

AFreddy::AFreddy()
{
}

AFreddy::~AFreddy()
{
}

void AFreddy::BeginPlay()
{
	Super::BeginPlay();
	InputOn();
	PGameMode = dynamic_cast<APlayGameMode*>(GetWorld()->GetGameMode().get());
	IsCCTVCam = PGameMode->GetCCTVUI();

	StateInit();
}

void AFreddy::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FreddyState.Update(_DeltaTime);

	if (IsDown('4') && false == IsFreddyDebug)
	{
		IsFreddyDebug = true;
		FreddyState.ChangeState("DiningArea");
		FreddyLevel = 15;
	}
	else if (IsDown('4') && true == IsFreddyDebug)
	{
		IsFreddyDebug = false;
		FreddyLevel = 0;
	}
}

void AFreddy::StateInit()
{
	// 프레디는 보니와 치카가 쇼 스테이지에 없을때 움직일 수 있다.
	// 프레디는 한 번 움직이면 뒤로가지 않는다. 공격 실패시에만 뒤로 갔다가 다시 공격한다.
	// Cam1A -> Cam1B -> Cam7 -> Cam6 -> Cam4A -> Cam4B -> RighrOffice -> Attack
	// 실패하면 Cam1B로 가서 다시 순서대로 진행

	// State 생성
	FreddyState.CreateState("ShowStage");
	FreddyState.CreateState("DiningArea");
	FreddyState.CreateState("EastHall");
	FreddyState.CreateState("EHallCorner");
	FreddyState.CreateState("Kitchen");
	FreddyState.CreateState("Restrooms");
	FreddyState.CreateState("RightOffice");

	// 함수 세팅
	FreddyState.SetStartFunction("ShowStage", std::bind(&AFreddy::ShowStageStart, this));
	FreddyState.SetUpdateFunction("ShowStage", std::bind(&AFreddy::ShowStageUpdate, this, std::placeholders::_1));

	FreddyState.SetStartFunction("DiningArea", std::bind(&AFreddy::DiningAreaStart, this));
	FreddyState.SetUpdateFunction("DiningArea", std::bind(&AFreddy::DiningAreaUpdate, this, std::placeholders::_1));

	FreddyState.SetStartFunction("EastHall", std::bind(&AFreddy::EastHallStart, this));
	FreddyState.SetUpdateFunction("EastHall", std::bind(&AFreddy::EastHallUpdate, this, std::placeholders::_1));

	FreddyState.SetStartFunction("EHallCorner", std::bind(&AFreddy::EHallCornerStart, this));
	FreddyState.SetUpdateFunction("EHallCorner", std::bind(&AFreddy::EHallCornerUpdate, this, std::placeholders::_1));

	FreddyState.SetStartFunction("Kitchen", std::bind(&AFreddy::KitchenStart, this));
	FreddyState.SetUpdateFunction("Kitchen", std::bind(&AFreddy::KitchenUpdate, this, std::placeholders::_1));

	FreddyState.SetStartFunction("Restrooms", std::bind(&AFreddy::RestroomsStart, this));
	FreddyState.SetUpdateFunction("Restrooms", std::bind(&AFreddy::RestroomsUpdate, this, std::placeholders::_1));

	FreddyState.SetStartFunction("RightOffice", std::bind(&AFreddy::RightOfficeStart, this));
	FreddyState.SetUpdateFunction("RightOffice", std::bind(&AFreddy::RightOfficeUpdate, this, std::placeholders::_1));

	FreddyState.ChangeState("ShowStage");
}

void AFreddy::ShowStageStart()
{
	FreddyCurPos = static_cast<int>(EFreddyPos::ShowStage);
}

void AFreddy::ShowStageUpdate(float _DeltaTime)
{
	int MoveDice = MoveChance.RandomInt(1, 20);
	FreddyMTCheck -= _DeltaTime;

	if (FreddyLevel >= MoveChance.RandomInt(1, 20) && 0 > FreddyMTCheck)
	{
		FreddyMTCheck = MoveTime;

		if (16 >= MoveDice
			&& true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::DiningArea)
			&& static_cast<int>(EBonniePos::ShowStage) != AAnimatronics::PGameMode->GetBonnie()->GetBonnieCurPos()
			&& static_cast<int>(EChicaPos::ShowStage) != AAnimatronics::PGameMode->GetChica()->GetChicaCurPos())
		{
			AAnimatronics::PGameMode->GetDiningAreaCam()->SetAnimatronics(PGameMode->GetFreddy());
			FreddyCurPos = static_cast<int>(EFreddyPos::DiningArea);
			FreddyState.ChangeState("DiningArea");
		}
	}
}

void AFreddy::DiningAreaStart()
{
	if (true == IsFreddyDebug)
	{
		AAnimatronics::PGameMode->GetDiningAreaCam()->SetAnimatronics(PGameMode->GetFreddy());
		FreddyCurPos = static_cast<int>(EFreddyPos::DiningArea);
	}
}

void AFreddy::DiningAreaUpdate(float _DeltaTime)
{
	int MoveDice = MoveChance.RandomInt(1, 20);
	FreddyMTCheck -= _DeltaTime;

	if (FreddyLevel >= MoveChance.RandomInt(1, 20) && 0 > FreddyMTCheck)
	{
		FreddyMTCheck = MoveTime;

		if (16 >= MoveDice
			&& true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::Restrooms))
		{
			AAnimatronics::PGameMode->GetDiningAreaCam()->SetAnimatronics(nullptr);
			AAnimatronics::PGameMode->GetRestroomsCam()->SetAnimatronics(PGameMode->GetFreddy());
			FreddyCurPos = static_cast<int>(EFreddyPos::Restrooms);
			FreddyState.ChangeState("Restrooms");
		}
	}
}

void AFreddy::EastHallStart()
{
}

void AFreddy::EastHallUpdate(float _DeltaTime)
{
	int MoveDice = MoveChance.RandomInt(1, 20);
	FreddyMTCheck -= _DeltaTime;

	if (FreddyLevel >= MoveChance.RandomInt(1, 20) && 0 > FreddyMTCheck)
	{
		FreddyMTCheck = MoveTime;

		if (16 >= MoveDice
			&& true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::EHallCorner))
		{
			AAnimatronics::PGameMode->GetEastHallCam()->SetAnimatronics(nullptr);
			AAnimatronics::PGameMode->GetEHallCornerCam()->SetAnimatronics(PGameMode->GetFreddy());
			FreddyCurPos = static_cast<int>(EFreddyPos::EHallCorner);
			FreddyState.ChangeState("EHallCorner");
		}
	}
}

void AFreddy::EHallCornerStart()
{
}

void AFreddy::EHallCornerUpdate(float _DeltaTime)
{
	int MoveDice = MoveChance.RandomInt(1, 20);
	FreddyMTCheck -= _DeltaTime;

	if (FreddyLevel >= MoveChance.RandomInt(1, 20) && 0 > FreddyMTCheck)
	{
		FreddyMTCheck = MoveTime;

		if (16 >= MoveDice)
		{
			AAnimatronics::PGameMode->GetEHallCornerCam()->SetAnimatronics(nullptr);
			AAnimatronics::PGameMode->GetRButton()->SetIsFreddy(true);
			FreddyCurPos = static_cast<int>(EFreddyPos::RightOffice);
			FreddyState.ChangeState("RightOffice");
		}
	}
}

void AFreddy::KitchenStart()
{
}

void AFreddy::KitchenUpdate(float _DeltaTime)
{
	int MoveDice = MoveChance.RandomInt(1, 20);
	FreddyMTCheck -= _DeltaTime;

	if (FreddyLevel >= MoveChance.RandomInt(1, 20) && 0 > FreddyMTCheck)
	{
		FreddyMTCheck = MoveTime;

		if (16 >= MoveDice
			&& true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::EastHall))
		{
			AAnimatronics::PGameMode->GetKitchenCam()->SetAnimatronics(nullptr);
			AAnimatronics::PGameMode->GetEastHallCam()->SetAnimatronics(PGameMode->GetFreddy());
			FreddyCurPos = static_cast<int>(EFreddyPos::EastHall);
			FreddyState.ChangeState("EastHall");
		}
	}
}

void AFreddy::RestroomsStart()
{
}

void AFreddy::RestroomsUpdate(float _DeltaTime)
{
	int MoveDice = MoveChance.RandomInt(1, 20);
	FreddyMTCheck -= _DeltaTime;

	if (FreddyLevel >= MoveChance.RandomInt(1, 20) && 0 > FreddyMTCheck)
	{
		FreddyMTCheck = MoveTime;

		if (16 >= MoveDice
			&& true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::Kitchen))
		{
			AAnimatronics::PGameMode->GetRestroomsCam()->SetAnimatronics(nullptr);
			AAnimatronics::PGameMode->GetKitchenCam()->SetAnimatronics(PGameMode->GetFreddy());
			FreddyCurPos = static_cast<int>(EFreddyPos::Kitchen);
			FreddyState.ChangeState("Kitchen");
		}
	}
}

void AFreddy::RightOfficeStart()
{
}

void AFreddy::RightOfficeUpdate(float _DeltaTime)
{
	int MoveDice = MoveChance.RandomInt(1, 20);
	FreddyMTCheck -= _DeltaTime;

	if (FreddyLevel >= MoveChance.RandomInt(1, 20) && 0 > FreddyMTCheck)
	{
		FreddyMTCheck = MoveTime;

		if (16 >= MoveDice && false == AAnimatronics::PGameMode->GetRButton()->GetIsCloseDoor())
		{
			AAnimatronics::PGameMode->SetCameraMoveActive(false);
			AAnimatronics::PGameMode->GetTheOffice()->SetJumpScareAnimation("JumpScareFreddy");
			DelayCallBack(2.5f, [this]() { GEngine->ChangeLevel("GameOverLevel"); });
		}
		else if (14 <= MoveDice
			&& true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::DiningArea)
			&& true == AAnimatronics::PGameMode->GetRButton()->GetIsCloseDoor())
		{
			AAnimatronics::PGameMode->GetRButton()->SetIsFreddy(false);
			AAnimatronics::PGameMode->GetDiningAreaCam()->SetAnimatronics(PGameMode->GetFreddy());
			FreddyCurPos = static_cast<int>(EChicaPos::DiningArea);
			FreddyState.ChangeState("DiningArea");
		}
	}
}