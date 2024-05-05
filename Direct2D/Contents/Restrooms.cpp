#include "PreCompile.h"
#include "Restrooms.h"
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
}

void ARestrooms::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
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

}

bool ARestrooms::GetIsAnimatronics()
{
	if (nullptr == Animatronics)
	{
		return false;
	}

	return true;
}