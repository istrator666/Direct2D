#include "PreCompile.h"
#include "Bonnie.h"

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
	
	if (BonnieLevel >= MoveChance.RandomInt(1, 20))
	{
		switch (BonnieCurPos)
		{
		case static_cast<int>(EBonniePos::ShowStage):
		{
			if (16 >= MoveChance.RandomInt(1, 20))
			{
				BonnieCurPos = static_cast<int>(EBonniePos::DiningArea);
			}
			else
			{
				IsBack = false;
				BonnieCurPos = static_cast<int>(EBonniePos::BackStage);
			}
			break;
		}
		case static_cast<int>(EBonniePos::DiningArea):
		{
			if (16 >= MoveChance.RandomInt(1, 20))
			{
				BonnieCurPos = static_cast<int>(EBonniePos::WestHall);
			}
			else
			{
				BonnieCurPos = static_cast<int>(EBonniePos::BackStage);
			}
			break;
		}
		case static_cast<int>(EBonniePos::WestHall):
		{
			if (16 >= MoveChance.RandomInt(1, 20))
			{
				BonnieCurPos = static_cast<int>(EBonniePos::WHallCorner);
			}
			else
			{
				BonnieCurPos = static_cast<int>(EBonniePos::SupplyCloset);
			}
			break;
		}

		case static_cast<int>(EBonniePos::WHallCorner):
		{
			if (16 >= MoveChance.RandomInt(1, 20))
			{
				BonnieCurPos = static_cast<int>(EBonniePos::Office);
			}
			else
			{
				BonnieCurPos = static_cast<int>(EBonniePos::SupplyCloset);
			}
			break;
		}
		case static_cast<int>(EBonniePos::SupplyCloset):
		{
			if (16 >= MoveChance.RandomInt(1, 20))
			{
				BonnieCurPos = static_cast<int>(EBonniePos::Office);
			}
			else
			{
				BonnieCurPos = static_cast<int>(EBonniePos::WestHall);
			}
			break;
		}
		case static_cast<int>(EBonniePos::BackStage):
		{
			if (10 >= MoveChance.RandomInt(1, 20))
			{
				IsBack = true;
				BonnieCurPos = static_cast<int>(EBonniePos::DiningArea);
			}
			else
			{
				BonnieCurPos = static_cast<int>(EBonniePos::WestHall);
			}
			break;
		}
		case static_cast<int>(EBonniePos::Office):
		{
			if (10 >= MoveChance.RandomInt(1, 20))
			{
				BonnieCurPos = static_cast<int>(EBonniePos::In);
			}
			else
			{
				IsBack = true;
				BonnieCurPos = static_cast<int>(EBonniePos::DiningArea);
			}
			break;
		}
		}
	}
}
