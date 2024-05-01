#include "PreCompile.h"
#include "ShowStage.h"
#include "PlayGameMode.h"
#include "Bonnie.h"
#include "Chica.h"
#include "Freddy.h"

AShowStage::AShowStage()
{

}

AShowStage::~AShowStage()
{
}

void AShowStage::ShowStageMonsterCheck()
{
	if (static_cast<int>(EBonniePos::ShowStage) == Bonnie->GetBonnieCurPos()
		&& static_cast<int>(EChicaPos::ShowStage) == Chica->GetChicaCurPos()
		&& static_cast<int>(EFreddyPos::ShowStage) == Freddy->GetFreddyCurPos())
	{
		CurShowStageCam = static_cast<int>(EShowStage::ShowStage_Default);
	}
	else if (static_cast<int>(EBonniePos::ShowStage) != Bonnie->GetBonnieCurPos()
		&& static_cast<int>(EChicaPos::ShowStage) == Chica->GetChicaCurPos()
		&& static_cast<int>(EFreddyPos::ShowStage) == Freddy->GetFreddyCurPos())
	{
		CurShowStageCam = static_cast<int>(EShowStage::ShowStage_BonnieGone);
	}
	else if (static_cast<int>(EChicaPos::ShowStage) != Chica->GetChicaCurPos()
		&& static_cast<int>(EBonniePos::ShowStage) == Bonnie->GetBonnieCurPos()
		&& static_cast<int>(EFreddyPos::ShowStage) == Freddy->GetFreddyCurPos())
	{
		CurShowStageCam = static_cast<int>(EShowStage::ShowStage_ChicaGone);
	}
	else if (static_cast<int>(EBonniePos::ShowStage) != Bonnie->GetBonnieCurPos()
		&& static_cast<int>(EChicaPos::ShowStage) != Chica->GetChicaCurPos()
		&& static_cast<int>(EFreddyPos::ShowStage) == Freddy->GetFreddyCurPos())
	{
		CurShowStageCam = static_cast<int>(EShowStage::ShowStage_BCGone);
	}
	else if (static_cast<int>(EBonniePos::ShowStage) != Bonnie->GetBonnieCurPos()
		&& static_cast<int>(EChicaPos::ShowStage) != Chica->GetChicaCurPos()
		&& static_cast<int>(EFreddyPos::ShowStage) != Freddy->GetFreddyCurPos())
	{
		CurShowStageCam = static_cast<int>(EShowStage::ShowStage_AllGone);
	}
	
}

void AShowStage::BeginPlay()
{
	Super::BeginPlay();

	PGMode = dynamic_cast<APlayGameMode*>(GetWorld()->GetGameMode().get());
	Bonnie = PGMode->GetBonnie();
	Chica = PGMode->GetChica();
	Freddy = PGMode->GetFreddy();
}

void AShowStage::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ShowStageMonsterCheck();
}