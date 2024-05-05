#include "PreCompile.h"
#include "EHallCorner.h"
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
}

void AEHallCorner::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
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

}

bool AEHallCorner::GetIsAnimatronics()
{
	if (nullptr == Animatronics)
	{
		return false;
	}

	return true;
}