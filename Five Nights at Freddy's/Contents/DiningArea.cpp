#include "PreCompile.h"
#include "DiningArea.h"

#include "Bonnie.h"
#include "Chica.h"
#include "Freddy.h"

ADiningArea::ADiningArea()
{
}

ADiningArea::~ADiningArea()
{
}

void ADiningArea::BeginPlay()
{
	Super::BeginPlay();
}

void ADiningArea::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	DiningAreaMonsterCheck();
}

void ADiningArea::SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics)
{
	Super::SetAnimatronics(_Animatronics);

	if (nullptr == Animatronics || nullptr == _Animatronics)
	{
		Animatronics = _Animatronics;
	}
}

void ADiningArea::DiningAreaMonsterCheck()
{
	if (nullptr != Animatronics)
	{
		ABonnie* Bonnie = nullptr;
		AChica* Chica = nullptr;
		AFreddy* Freddy = nullptr;

		ABonnie* NewBonnie = dynamic_cast<ABonnie*>(Animatronics.get());
		if (nullptr != NewBonnie)
		{
			Bonnie = NewBonnie;

			if (static_cast<int>(EBonniePos::DiningArea) == Bonnie->GetBonnieCurPos() && false == Bonnie->GetBonnieIsBack())
			{
				CurDiningAreaCam = static_cast<int>(EDiningArea::DiningArea_Bonnie0);
			}
			else if (static_cast<int>(EBonniePos::DiningArea) == Bonnie->GetBonnieCurPos() && true == Bonnie->GetBonnieIsBack())
			{
				CurDiningAreaCam = static_cast<int>(EDiningArea::DiningArea_Bonnie1);
			}
		}
		AChica* NewChica = dynamic_cast<AChica*>(Animatronics.get());
		if (nullptr != NewChica)
		{
			Chica = NewChica;

			if (static_cast<int>(EChicaPos::DiningArea) == Chica->GetChicaCurPos() && false == Chica->GetChicaBack())
			{
				CurDiningAreaCam = static_cast<int>(EDiningArea::DiningArea_Chica0);
			}
			else if (static_cast<int>(EChicaPos::DiningArea) == Chica->GetChicaCurPos() && true == Chica->GetChicaBack())
			{
				CurDiningAreaCam = static_cast<int>(EDiningArea::DiningArea_Chica1);
			}
		}

		AFreddy* NewFreddy = dynamic_cast<AFreddy*>(Animatronics.get());
		if (nullptr != NewFreddy)
		{
			Freddy = NewFreddy;

			if (static_cast<int>(EFreddyPos::DiningArea) == Freddy->GetFreddyCurPos())
			{
				CurDiningAreaCam = static_cast<int>(EDiningArea::DiningArea_Freddy);
			}
		}
	}
	else
	{
		CurDiningAreaCam = static_cast<int>(EDiningArea::DiningArea_Default);
	}
}

bool ADiningArea::GetIsAnimatronics()
{
	if (nullptr == Animatronics)
	{
		return false;
	}

	return true;
}