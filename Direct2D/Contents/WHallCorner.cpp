#include "PreCompile.h"
#include "WHallCorner.h"
#include "Bonnie.h"

AWHallCorner::AWHallCorner()
{
}

AWHallCorner::~AWHallCorner()
{
}

void AWHallCorner::BeginPlay()
{
	Super::BeginPlay();
}

void AWHallCorner::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	WHallCornerMonsterCheck();
}

void AWHallCorner::SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics)
{
	Super::SetAnimatronics(_Animatronics);

	if (nullptr == Animatronics)
	{
		Animatronics = _Animatronics;
	}
}

void AWHallCorner::WHallCornerMonsterCheck()
{
	if (nullptr != Animatronics)
	{
		ABonnie* Bonnie = nullptr;

		ABonnie* NewBonnie = dynamic_cast<ABonnie*>(Animatronics.get());
		if (nullptr != NewBonnie)
		{
			Bonnie = NewBonnie;

			if (static_cast<int>(EBonniePos::WHallCorner) == Bonnie->GetBonnieCurPos())
			{
				WHallCornerCam = static_cast<int>(EWHallCorner::WestHallB_Bonnie0);
			}
		}
		else
		{
			WHallCornerCam = static_cast<int>(EWHallCorner::WestHallB_Default);
		}
	}
}

bool AWHallCorner::GetIsAnimatronics()
{
	if (nullptr == Animatronics)
	{
		return false;
	}

	return true;
}