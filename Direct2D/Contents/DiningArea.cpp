#include "PreCompile.h"
#include "DiningArea.h"
#include "PlayGameMode.h"
#include "Bonnie.h"
#include "Chica.h"
#include "Freddy.h"

ADiningArea::ADiningArea()
{
}

ADiningArea::~ADiningArea()
{
}

void ADiningArea::BeginPlay()
{
	Super::BeginPlay();
	PGMode = dynamic_cast<APlayGameMode*>(GetWorld()->GetGameMode().get());
	Bonnie = PGMode->GetBonnie();
	Chica = PGMode->GetChica();
	Freddy = PGMode->GetFreddy();
}

void ADiningArea::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	DiningAreaMonsterCheck();
}

void ADiningArea::DiningAreaMonsterCheck()
{
	if (static_cast<int>(EBonniePos::DiningArea) == Bonnie->GetBonnieCurPos() && false == Bonnie->GetBonnieIsBack())
	{
		CurDiningAreaCam = static_cast<int>(EDiningArea::DiningArea_Bonnie0);
	}
	else if (static_cast<int>(EBonniePos::DiningArea) == Bonnie->GetBonnieCurPos() && true == Bonnie->GetBonnieIsBack())
	{
		CurDiningAreaCam = static_cast<int>(EDiningArea::DiningArea_Bonnie1);
	}
}
