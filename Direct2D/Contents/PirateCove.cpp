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

}

bool APirateCove::GetIsAnimatronics()
{
	if (nullptr == Animatronics)
	{
		return false;
	}

	return true;
}

