#include "PreCompile.h"
#include "ShowStage.h"
#include "Bonnie.h"
#include "Chica.h"
#include "Freddy.h"

AShowStage::AShowStage()
{

}

AShowStage::~AShowStage()
{
}

void AShowStage::BeginPlay()
{
	Super::BeginPlay();
}

void AShowStage::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ShowStageMonsterCheck();
}

void AShowStage::SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics)
{
	Super::SetAnimatronics(_Animatronics);

	Animatronics.push_back(_Animatronics);

}


void AShowStage::ShowStageMonsterCheck()
{
	ABonnie* Bonnie = nullptr;
	AChica* Chica = nullptr;
	AFreddy* Freddy = nullptr;

	for (size_t i = 0; i < Animatronics.size(); i++)
	{
		ABonnie* NewBonnie = dynamic_cast<ABonnie*>(Animatronics[i].get());
		if (nullptr != NewBonnie)
		{
			Bonnie = NewBonnie;
			continue;
		}
		AChica* NewChica = dynamic_cast<AChica*>(Animatronics[i].get());
		if (nullptr != NewChica)
		{
			Chica = NewChica;
			continue;
		}
		AFreddy* NewFreddy = dynamic_cast<AFreddy*>(Animatronics[i].get());
		if (nullptr != NewFreddy)
		{
			Freddy = NewFreddy;
			continue;
		}
	}

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
		Bonnie = nullptr;
	}
	else if (static_cast<int>(EChicaPos::ShowStage) != Chica->GetChicaCurPos()
		&& static_cast<int>(EBonniePos::ShowStage) == Bonnie->GetBonnieCurPos()
		&& static_cast<int>(EFreddyPos::ShowStage) == Freddy->GetFreddyCurPos())
	{
		CurShowStageCam = static_cast<int>(EShowStage::ShowStage_ChicaGone);
		Chica = nullptr;
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
		Freddy = nullptr;
	}
}
