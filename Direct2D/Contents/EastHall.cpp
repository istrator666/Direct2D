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
	EastHallMonsterCheck();
}

void AEastHall::SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics)
{
	Super::SetAnimatronics(_Animatronics);

	if (nullptr == Animatronics || nullptr == _Animatronics)
	{
		Animatronics = _Animatronics;
	}
}

void AEastHall::EastHallMonsterCheck()
{
}

bool AEastHall::GetIsAnimatronics()
{
	if (nullptr == Animatronics)
	{
		return false;
	}

	return true;
}