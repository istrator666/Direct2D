#include "PreCompile.h"
#include "Kitchen.h"
#include "Chica.h"

AKitchen::AKitchen()
{
}

AKitchen::~AKitchen()
{
}

void AKitchen::BeginPlay()
{
	Super::BeginPlay();
}

void AKitchen::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	KitchenMonsterCheck();
}

void AKitchen::SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics)
{
	Super::SetAnimatronics(_Animatronics);

	if (nullptr == Animatronics || nullptr == _Animatronics)
	{
		Animatronics = _Animatronics;
	}
}

void AKitchen::KitchenMonsterCheck()
{

}

bool AKitchen::GetIsAnimatronics()
{
	if (nullptr == Animatronics)
	{
		return false;
	}

	return true;
}