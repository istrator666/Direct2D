#include "PreCompile.h"
#include "SupplyCloset.h"
#include "Bonnie.h"
#include "Chica.h"
#include "Freddy.h"

ASupplyCloset::ASupplyCloset()
{
}

ASupplyCloset::~ASupplyCloset()
{
}

void ASupplyCloset::BeginPlay()
{
	Super::BeginPlay();
}

void ASupplyCloset::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ASupplyCloset::SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics)
{
	Super::SetAnimatronics(_Animatronics);

	if (nullptr == Animatronics)
	{
		Animatronics = _Animatronics;
	}
}

void ASupplyCloset::DiningAreaMonsterCheck()
{
	if (nullptr != Animatronics)
	{
		ABonnie* Bonnie = nullptr;

		ABonnie* NewBonnie = dynamic_cast<ABonnie*>(Animatronics.get());
		if (nullptr != NewBonnie)
		{
			Bonnie = NewBonnie;

			if (static_cast<int>(EBonniePos::SupplyCloset) == Bonnie->GetBonnieCurPos())
			{
				SupplyClosetCam = static_cast<int>(ESupplyCloset::SuppltCloset_Bonnie);
			}
		}
	}
}

bool ASupplyCloset::GetIsAnimatronics()
{
	if (nullptr == Animatronics)
	{
		return false;
	}

	return true;
}
