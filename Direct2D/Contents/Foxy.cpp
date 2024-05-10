#include "PreCompile.h"
#include "Foxy.h"

#include "PlayGameMode.h"
#include "PirateCove.h"
#include "CCTVUI.h"
#include "LeftButton.h"
#include "WestHall.h"
#include "TheOffice.h"
#include "StageCCTV.h"
#include <EngineCore/SpriteRenderer.h>

AFoxy::AFoxy()
{
}

AFoxy::~AFoxy()
{
}

void AFoxy::BeginPlay()
{
	Super::BeginPlay();
	PGameMode = dynamic_cast<APlayGameMode*>(GetWorld()->GetGameMode().get());
	IsCCTVCam = PGameMode->GetCCTVUI();

	StateInit();
}

void AFoxy::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	PirateCoveState.Update(_DeltaTime);

}

void AFoxy::StateInit()
{
	// 플레이어가 CCTV CAM을 보고 있으면 행동기회를 얻지 못함 (동결)
	// 플레이어가 Cam을 내리는 순간 0.83 ~ 16.67 의 시간이 부여되고 다 지나면 다음 단계로 진행
	// 1단계 커튼에 가려진 상태
	// 2단계 커튼을 열고 쳐다보는 상태
	// 3단계 커튼 밖으로 나와 쳐다보는 상태
	// 3단계에서 행동기회를 가지면 탈출해서 플레이어가 있는 곳으로 돌진
	
	// State 생성
	PirateCoveState.CreateState("PirateCoveLv1");
	PirateCoveState.CreateState("PirateCoveLv2");
	PirateCoveState.CreateState("PirateCoveLv3");
	PirateCoveState.CreateState("PirateCoveLv4");
	PirateCoveState.CreateState("FoxyWestHall");
	PirateCoveState.CreateState("FoxyLeftOffice");

	// 함수 세팅
	PirateCoveState.SetStartFunction("PirateCoveLv1", std::bind(&AFoxy::PirateCoveLv1Start, this));
	PirateCoveState.SetUpdateFunction("PirateCoveLv1", std::bind(&AFoxy::PirateCoveLv1Update, this, std::placeholders::_1));

	PirateCoveState.SetStartFunction("PirateCoveLv2", std::bind(&AFoxy::PirateCoveLv2Start, this));
	PirateCoveState.SetUpdateFunction("PirateCoveLv2", std::bind(&AFoxy::PirateCoveLv2Update, this, std::placeholders::_1));

	PirateCoveState.SetStartFunction("PirateCoveLv3", std::bind(&AFoxy::PirateCoveLv3Start, this));
	PirateCoveState.SetUpdateFunction("PirateCoveLv3", std::bind(&AFoxy::PirateCoveLv3Update, this, std::placeholders::_1));

	PirateCoveState.SetStartFunction("PirateCoveLv4", std::bind(&AFoxy::PirateCoveLv4Start, this));
	PirateCoveState.SetUpdateFunction("PirateCoveLv4", std::bind(&AFoxy::PirateCoveLv4Update, this, std::placeholders::_1));

	PirateCoveState.SetStartFunction("FoxyWestHall", std::bind(&AFoxy::FoxyWestHallStart, this));
	PirateCoveState.SetUpdateFunction("FoxyWestHall", std::bind(&AFoxy::FoxyWestHallUpdate, this, std::placeholders::_1));

	PirateCoveState.SetStartFunction("FoxyLeftOffice", std::bind(&AFoxy::FoxyLeftOfficeStart, this));
	PirateCoveState.SetUpdateFunction("FoxyLeftOffice", std::bind(&AFoxy::FoxyLeftOfficeUpdate, this, std::placeholders::_1));

	PirateCoveState.ChangeState("PirateCoveLv1");
}

void AFoxy::PirateCoveLv1Start()
{
	FoxyCurPos = static_cast<int>(EFoxyPos::PirateCoveLv1);
}

void AFoxy::PirateCoveLv1Update(float _DeltaTime)
{
	int MoveDice = MoveChance.RandomInt(1, 20);

	if (nullptr != IsCCTVCam)
	{
		if (false == IsCCTVCam->GetIsCCTV() && 0 <= FoxyMTCheck)
		{
			FoxyMTCheck -= _DeltaTime;
		}
		else if (true == IsCCTVCam->GetIsCCTV())
		{
			return;
		}
		else if (0 > FoxyMTCheck && false == FoxyResetTime)
		{
			FoxyResetTime = true;
			if (FoxyLevel >= MoveChance.RandomInt(1, 20))
			{
				if (12 >= MoveDice)
				{
					FoxyCurPos = static_cast<int>(EFoxyPos::PirateCoveLv2);
					PirateCoveState.ChangeState("PirateCoveLv2");
				}
			}
		}
		else if (true == FoxyResetTime)
		{
			FoxyResetTime = false;
			//FoxyMTCheck = 1.0f;
			FoxyMTCheck = MoveChance.RandomFloat(0.83f, 16.67f);
		}
	}
}
void AFoxy::PirateCoveLv2Start()
{
}
void AFoxy::PirateCoveLv2Update(float _DeltaTime)
{
	int MoveDice = MoveChance.RandomInt(1, 20);

	if (nullptr != IsCCTVCam)
	{
		if (false == IsCCTVCam->GetIsCCTV() && 0 <= FoxyMTCheck)
		{
			FoxyMTCheck -= _DeltaTime;
		}
		else if (true == IsCCTVCam->GetIsCCTV())
		{
			return;
		}
		else if (0 > FoxyMTCheck && false == FoxyResetTime)
		{
			FoxyResetTime = true;
			if (FoxyLevel >= MoveChance.RandomInt(1, 20))
			{
				if (12 >= MoveDice)
				{
					FoxyCurPos = static_cast<int>(EFoxyPos::PirateCoveLv3);
					PirateCoveState.ChangeState("PirateCoveLv3");
				}
			}
		}
		else if (true == FoxyResetTime)
		{
			FoxyResetTime = false;
			//FoxyMTCheck = 1.0f;
			FoxyMTCheck = MoveChance.RandomFloat(0.83f, 16.67f);
		}
	}
}
void AFoxy::PirateCoveLv3Start()
{
}
void AFoxy::PirateCoveLv3Update(float _DeltaTime)
{
	int MoveDice = MoveChance.RandomInt(1, 20);

	if (nullptr != IsCCTVCam)
	{
		if (false == IsCCTVCam->GetIsCCTV() && 0 <= FoxyMTCheck)
		{
			FoxyMTCheck -= _DeltaTime;
		}
		else if (true == IsCCTVCam->GetIsCCTV())
		{
			return;
		}
		else if (0 > FoxyMTCheck && false == FoxyResetTime)
		{
			FoxyResetTime = true;
			if (FoxyLevel >= MoveChance.RandomInt(1, 20))
			{
				if (12 >= MoveDice)
				{
					FoxyCurPos = static_cast<int>(EFoxyPos::PirateCoveLv4);
					PirateCoveState.ChangeState("PirateCoveLv4");
				}
			}
		}
		else if (true == FoxyResetTime)
		{
			FoxyResetTime = false;
			//FoxyMTCheck = 1.0f;
			FoxyMTCheck = MoveChance.RandomFloat(0.83f, 16.67f);
		}
	}
}
void AFoxy::PirateCoveLv4Start()
{
}
void AFoxy::PirateCoveLv4Update(float _DeltaTime)
{
	int MoveDice = MoveChance.RandomInt(1, 20);

	if (nullptr != IsCCTVCam)
	{
		if (true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::WestHall))
		{
			AAnimatronics::PGameMode->GetPirateCoveCam()->SetAnimatronics(nullptr);
			AAnimatronics::PGameMode->GetWestHallCam()->SetAnimatronics(PGameMode->GetFoxy());
			FoxyCurPos = static_cast<int>(EFoxyPos::WestHall);
			PirateCoveState.ChangeState("FoxyWestHall");
		}
	}
}

void AFoxy::FoxyWestHallStart()
{
}

void AFoxy::FoxyWestHallUpdate(float _DeltaTime)
{
	limitTime -= _DeltaTime;

	if ("WestHall" == PGameMode->GetCurCam())
	{
		AAnimatronics::PGameMode->GetStageCCTV()->GetRunningFoxy()->SetActive(true);
		AAnimatronics::PGameMode->GetStageCCTV()->GetRunningFoxy()->ChangeAnimation("RunningFoxy");

		DelayCallBack(2.0f, [this]() { AAnimatronics::PGameMode->GetStageCCTV()->GetRunningFoxy()->AnimationReset()
			, AAnimatronics::PGameMode->GetStageCCTV()->GetRunningFoxy()->SetActive(false)
			, FoxyCurPos = static_cast<int>(EFoxyPos::LeftOffice)
			, PirateCoveState.ChangeState("FoxyLeftOffice"); });
	}
	else if (0 > limitTime)
	{
		AAnimatronics::PGameMode->GetWestHallCam()->SetAnimatronics(nullptr);
		FoxyCurPos = static_cast<int>(EFoxyPos::LeftOffice);
		PirateCoveState.ChangeState("FoxyLeftOffice");
	}
}

void AFoxy::FoxyLeftOfficeStart()
{
}

void AFoxy::FoxyLeftOfficeUpdate(float _DeltaTime)
{
	if (false == AAnimatronics::PGameMode->GetLButton()->GetIsCloseDoor())
	{
		AAnimatronics::PGameMode->SetCameraMoveActive(false);
		AAnimatronics::PGameMode->GetTheOffice()->SetJumpScareAnimation("JumpScareFoxy");
		DelayCallBack(3.0f, [this]() { GEngine->ChangeLevel("GameOverLevel"); });
	}
	else if (true == AAnimatronics::PGameMode->GetLButton()->GetIsCloseDoor())
	{
		AAnimatronics::PGameMode->GetStageCCTV()->GetRunningFoxy()->AnimationReset();
		AAnimatronics::PGameMode->GetStageCCTV()->GetRunningFoxy()->SetActive(false);
		AAnimatronics::PGameMode->GetPirateCoveCam()->SetAnimatronics(PGameMode->GetFoxy());
		PirateCoveState.ChangeState("PirateCoveLv1");
	}

	limitTime = 25.0f;
}

