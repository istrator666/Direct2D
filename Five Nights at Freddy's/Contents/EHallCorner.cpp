#include "PreCompile.h"
#include "EHallCorner.h"

#include "PlayGameMode.h"
#include "Chica.h"
#include "Freddy.h"

AEHallCorner::AEHallCorner()
{
}

AEHallCorner::~AEHallCorner()
{
}

void AEHallCorner::BeginPlay()
{
	Super::BeginPlay();
	PGameMode = dynamic_cast<APlayGameMode*>(GetWorld()->GetGameMode().get());
}

void AEHallCorner::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	FCamTimeCheck(_DeltaTime);
	EHallCornerMonsterCheck();
}

void AEHallCorner::SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics)
{
	Super::SetAnimatronics(_Animatronics);

	if (nullptr == Animatronics || nullptr == _Animatronics)
	{
		Animatronics = _Animatronics;
	}
}


void AEHallCorner::EHallCornerMonsterCheck()
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

			if (static_cast<int>(EChicaPos::EHallCorner) == Chica->GetChicaCurPos() && 0 <= CamTimeCheck)
			{
				CurEHallCornerCam = static_cast<int>(EEHallCorner::EastHallB_Chica0);
			}
			else if (static_cast<int>(EChicaPos::EHallCorner) == Chica->GetChicaCurPos() && 0 >= CamTimeCheck)
			{
				CurEHallCornerCam = static_cast<int>(EEHallCorner::EastHallB_Chica1);
			}
		}

		if (nullptr != NewFreddy)
		{
			Freddy = NewFreddy;

			if (static_cast<int>(EFreddyPos::EHallCorner) == Freddy->GetFreddyCurPos())
			{
				CurEHallCornerCam = static_cast<int>(EEHallCorner::EastHallB_Freddy);
			}
		}
	}
	else
	{
		CurEHallCornerCam = static_cast<int>(EEHallCorner::EastHallB_Default);
	}
}

void AEHallCorner::FCamTimeCheck(float _DeltaTime)
{
	if ("EHallCorner" == PGameMode->GetCurCam() && nullptr != Animatronics)
	{
		CamTimeCheck -= _DeltaTime;
	}
	else
	{
		CamTimeCheck = 5.0f;
	}
}

bool AEHallCorner::GetIsAnimatronics()
{
	if (nullptr == Animatronics)
	{
		return false;
	}

	return true;
}