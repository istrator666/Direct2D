#include "PreCompile.h"
#include "Restrooms.h"

#include "PlayGameMode.h"
#include "Chica.h"
#include "Freddy.h"

ARestrooms::ARestrooms()
{
}

ARestrooms::~ARestrooms()
{
}

void ARestrooms::BeginPlay()
{
	Super::BeginPlay();
	PGameMode = dynamic_cast<APlayGameMode*>(GetWorld()->GetGameMode().get());
}

void ARestrooms::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	FCamTimeCheck(_DeltaTime);
	RestroomsMonsterCheck();
}

void ARestrooms::SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics)
{
	Super::SetAnimatronics(_Animatronics);

	if (nullptr == Animatronics || nullptr == _Animatronics)
	{
		Animatronics = _Animatronics;
	}
}

void ARestrooms::RestroomsMonsterCheck()
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

			if (static_cast<int>(EChicaPos::Restrooms) == Chica->GetChicaCurPos() && 0 <= CamTimeCheck)
			{
				CurRestroomsCam = static_cast<int>(ERestRooms::RestRooms_Chica0);
			}
			else if (static_cast<int>(EChicaPos::EHallCorner) == Chica->GetChicaCurPos() && 0 >= CamTimeCheck)
			{
				CurRestroomsCam = static_cast<int>(ERestRooms::RestRooms_Chica1);
			}
		}

		if (nullptr != NewFreddy)
		{
			Freddy = NewFreddy;

			if (static_cast<int>(EFreddyPos::Restrooms) == Freddy->GetFreddyCurPos())
			{
				CurRestroomsCam = static_cast<int>(ERestRooms::RestRooms_Freddy);
			}
		}
	}
	else
	{
		CurRestroomsCam = static_cast<int>(ERestRooms::RestRooms_Default);
	}
}

void ARestrooms::FCamTimeCheck(float _DeltaTime)
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

bool ARestrooms::GetIsAnimatronics()
{
	if (nullptr == Animatronics)
	{
		return false;
	}

	return true;
}