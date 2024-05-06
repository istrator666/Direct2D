#include "PreCompile.h"
#include "EastHall.h"

#include "Chica.h"
#include "Freddy.h"

AEastHall::AEastHall()
{
}

AEastHall::~AEastHall()
{
}

void AEastHall::BeginPlay()
{
	Super::BeginPlay();
}

void AEastHall::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	EastHallMonsterCheck(_DeltaTime);
}

void AEastHall::SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics)
{
	Super::SetAnimatronics(_Animatronics);

	if (nullptr == Animatronics || nullptr == _Animatronics)
	{
		Animatronics = _Animatronics;
	}
}

void AEastHall::EastHallMonsterCheck(float _DeltaTime)
{
	if (nullptr != Animatronics)
	{
		Chica = nullptr;
		Freddy = nullptr;

		AChica* NewChica = dynamic_cast<AChica*>(Animatronics.get());
		AFreddy* NewFreddy = dynamic_cast<AFreddy*>(Animatronics.get());
		if (nullptr != NewChica)
		{
			Chica = NewChica;

			if (static_cast<int>(EChicaPos::EastHall) == Chica->GetChicaCurPos() && 0 <= CamTimeCheck)
			{
				CamTimeCheck -= _DeltaTime;
				EastHallCam = static_cast<int>(EEastHall::EastHallA_Chica0);
			}
			else if (static_cast<int>(EChicaPos::EastHall) == Chica->GetChicaCurPos() && 0 >= CamTimeCheck)
			{
				EastHallCam = static_cast<int>(EEastHall::EastHallA_Chica1);
			}
		}
	}
	else
	{
		CamTimeCheck = 3.0f;
		EastHallCam = static_cast<int>(EEastHall::EastHallA_Default);
	}
}

bool AEastHall::GetIsAnimatronics()
{
	if (nullptr == Animatronics)
	{
		return false;
	}

	return true;
}