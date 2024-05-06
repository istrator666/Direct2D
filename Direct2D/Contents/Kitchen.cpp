#include "PreCompile.h"
#include "Kitchen.h"

#include "PlayGameMode.h"
#include "Chica.h"
#include "Freddy.h"

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
	if (nullptr != Animatronics)
	{
		Chica = nullptr;
		Freddy = nullptr;

		AChica* NewChica = dynamic_cast<AChica*>(Animatronics.get());
		AFreddy* NewFreddy = dynamic_cast<AFreddy*>(Animatronics.get());
		if (nullptr != NewChica)
		{
			Chica = NewChica;

			if (static_cast<int>(EChicaPos::Kitchen) == Chica->GetChicaCurPos())
			{
				CurKitchenCam = static_cast<int>(EKitchen::CameraDisabled);
			}
		}
	}
	else
	{
		CurKitchenCam = static_cast<int>(EKitchen::CameraDisabled);
	}
}

bool AKitchen::GetIsAnimatronics()
{
	if (nullptr == Animatronics)
	{
		return false;
	}

	return true;
}