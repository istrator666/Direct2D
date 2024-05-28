#include "PreCompile.h"
#include "PirateCove.h"
#include "PlayGameMode.h"
#include "Foxy.h"

APirateCove::APirateCove()
{
}

APirateCove::~APirateCove()
{
}

void APirateCove::BeginPlay()
{
	Super::BeginPlay();
	PGameMode = dynamic_cast<APlayGameMode*>(GetWorld()->GetGameMode().get());
}

void APirateCove::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	PirateCoveMonsterCheck();
}

void APirateCove::SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics)
{
	Super::SetAnimatronics(_Animatronics);

	if (nullptr == Animatronics || nullptr == _Animatronics)
	{
		Animatronics = _Animatronics;
	}
}


void APirateCove::PirateCoveMonsterCheck()
{
	if (nullptr != Animatronics)
	{
		Foxy = nullptr;

		AFoxy* NewFoxy = dynamic_cast<AFoxy*>(Animatronics.get());
		if (nullptr != NewFoxy)
		{
			Foxy = NewFoxy;

			if (static_cast<int>(EFoxyPos::PirateCoveLv1) == Foxy->GetFoxyCurPos())
			{
				CurPirateCoveCam = static_cast<int>(EPirateCove::PirateCove_Lv1);
			}
			else if (static_cast<int>(EFoxyPos::PirateCoveLv2) == Foxy->GetFoxyCurPos())
			{
				CurPirateCoveCam = static_cast<int>(EPirateCove::PirateCove_Lv2);
			}
			else if (static_cast<int>(EFoxyPos::PirateCoveLv3) == Foxy->GetFoxyCurPos())
			{
				CurPirateCoveCam = static_cast<int>(EPirateCove::PirateCove_Lv3);
			}
			else if (static_cast<int>(EFoxyPos::PirateCoveLv4) == Foxy->GetFoxyCurPos())
			{
				CurPirateCoveCam = static_cast<int>(EPirateCove::PirateCove_Lv4);
			}
			else if (static_cast<int>(EFoxyPos::WestHall) == Foxy->GetFoxyCurPos())
			{
				CurPirateCoveCam = static_cast<int>(EPirateCove::PirateCove_Lv4_Anomaly);
			}
		}
	}
}

bool APirateCove::GetIsAnimatronics()
{
	if (nullptr == Animatronics)
	{
		return false;
	}

	return true;
}

