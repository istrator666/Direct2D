#include "PreCompile.h"
#include "BackStage.h"
#include "PlayGameMode.h"
#include "Bonnie.h"

ABackStage::ABackStage()
{
}

ABackStage::~ABackStage()
{
}

void ABackStage::BeginPlay()
{
	Super::BeginPlay();
	PGameMode = dynamic_cast<APlayGameMode*>(GetWorld()->GetGameMode().get());
}

void ABackStage::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	//FCamTimeCheck(_DeltaTime);
	BackStageMonsterCheck();
}

void ABackStage::SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics)
{
	Super::SetAnimatronics(_Animatronics);

	if (nullptr == Animatronics || nullptr == _Animatronics)
	{
		Animatronics = _Animatronics;
	}
}

void ABackStage::BackStageMonsterCheck()
{
	if (nullptr != Animatronics)
	{
		Bonnie = nullptr;

		ABonnie* NewBonnie = dynamic_cast<ABonnie*>(Animatronics.get());
		if (nullptr != NewBonnie)
		{
			Bonnie = NewBonnie;

			if (static_cast<int>(EBonniePos::BackStage) == Bonnie->GetBonnieCurPos())
			{
				CurBackStageCam = static_cast<int>(EBackstage::BackStage_Bonnie0);
			}
			//else if (static_cast<int>(EBonniePos::BackStage) == Bonnie->GetBonnieCurPos() && 0 > CamTimeCheck)
			//{
			//	CurBackStageCam = static_cast<int>(EBackstage::BackStage_Bonnie1);
			//}
		}
	}
	else
	{
		CurBackStageCam = static_cast<int>(EBackstage::BackStage_Default);
	}
}

void ABackStage::FCamTimeCheck(float _DeltaTime)
{
	if ("BackStage" == PGameMode->GetCurCam())
	{
		CamTimeCheck -= _DeltaTime;
	}
	else
	{
		CamTimeCheck = 5.0f;
	}
}

bool ABackStage::GetIsAnimatronics()
{
	if (nullptr == Animatronics)
	{
		return false;
	}

	return true;
}