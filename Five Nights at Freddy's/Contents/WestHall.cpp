#include "PreCompile.h"

#include "WestHall.h"
#include "Bonnie.h"

AWestHall::AWestHall()
{
}

AWestHall::~AWestHall()
{
}

void AWestHall::BeginPlay()
{
	Super::BeginPlay();
}

void AWestHall::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	WestHallMonsterCheck();
}

void AWestHall::SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics)
{
	Super::SetAnimatronics(_Animatronics);

	if (nullptr == Animatronics || nullptr == _Animatronics)
	{
		Animatronics = _Animatronics;
	}
}

void AWestHall::WestHallMonsterCheck()
{
	if (nullptr != Animatronics)
	{
		ABonnie* Bonnie = nullptr;

		ABonnie* NewBonnie = dynamic_cast<ABonnie*>(Animatronics.get());
		if (nullptr != NewBonnie)
		{
			Bonnie = NewBonnie;

			if (static_cast<int>(EBonniePos::WestHall) == Bonnie->GetBonnieCurPos())
			{
				WestHallCam = static_cast<int>(EWestHall::WestHallA_Bonnie);
			}
		}
	}
	else
	{
		WestHallCam = static_cast<int>(EWestHall::WestHallA_Default);
	}
}

bool AWestHall::GetIsAnimatronics()
{
	if (nullptr == Animatronics)
	{
		return false;
	}

	return true;
}