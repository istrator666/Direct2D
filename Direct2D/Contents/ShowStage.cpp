#include "PreCompile.h"
#include "ShowStage.h"
#include "PlayGameMode.h"
#include "Bonnie.h"

AShowStage::AShowStage()
{

}

AShowStage::~AShowStage()
{
}

void AShowStage::ShowStageMonsterCheck()
{
	if (static_cast<int>(EBonniePos::ShowStage) == Bonnie->GetBonnieCurPos())
	{
		CurShowStageCam = static_cast<int>(EShowStage::ShowStage_Default);
	}
	else if (static_cast<int>(EBonniePos::ShowStage) != Bonnie->GetBonnieCurPos())
	{
		CurShowStageCam = static_cast<int>(EShowStage::ShowStage_BonnieGone);
	}
	
}

void AShowStage::BeginPlay()
{
	Super::BeginPlay();

	PGMode = dynamic_cast<APlayGameMode*>(GetWorld()->GetGameMode().get());
	Bonnie = PGMode->GetBonnie();
}

void AShowStage::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ShowStageMonsterCheck();
}