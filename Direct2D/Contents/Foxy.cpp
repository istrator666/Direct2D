#include "PreCompile.h"
#include "Foxy.h"

#include "PlayGameMode.h"
#include "PirateCove.h"
#include "CCTVUI.h"
#include "LeftButton.h"
#include "WestHall.h"
#include "TheOffice.h"
#include "StageCCTV.h"

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
}

void AFoxy::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

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
			FoxyMove(_DeltaTime);
		}
		else if (true == FoxyResetTime)
		{
			FoxyResetTime = false;
			FoxyMTCheck = 3.0f;
			//FoxyMTCheck = MoveChance.RandomFloat(0.83f, 16.67f);
		}
	}
}

void AFoxy::FoxyMove(float _DeltaTime)
{
	// 플레이어가 CCTV CAM을 보고 있으면 행동기회를 얻지 못함 (동결)
	// 플레이어가 Cam을 내리는 순간 0.83 ~ 16.67 의 시간이 부여되고 다 지나면 다음 단계로 진행
	// 1단계 커튼에 가려진 상태
	// 2단계 커튼을 열고 쳐다보는 상태
	// 3단계 커튼 밖으로 나와 쳐다보는 상태
	// 3단계에서 행동기회를 가지면 탈출해서 플레이어가 있는 곳으로 돌진

	int MoveDice = MoveChance.RandomInt(1, 20);

	if (FoxyLevel >= MoveChance.RandomInt(1, 20))
	{
		switch (FoxyCurPos)
		{
		case static_cast<int>(EFoxyPos::PirateCoveLv1):
			if (12 >= MoveDice)
			{
				FoxyCurPos = static_cast<int>(EFoxyPos::PriateCoveLv2);
			}
			break;
		case static_cast<int>(EFoxyPos::PriateCoveLv2):
			if (12 >= MoveDice)
			{
				FoxyCurPos = static_cast<int>(EFoxyPos::PriateCoveLv3);
			}
			break;
		case static_cast<int>(EFoxyPos::PriateCoveLv3):
			if (12 >= MoveDice)
			{
				FoxyCurPos = static_cast<int>(EFoxyPos::PriateCoveLv4);
			}
			break;
		case static_cast<int>(EFoxyPos::PriateCoveLv4):
			if (true != AAnimatronics::PGameMode->GetIsMapAnimatronics(ECamMap::WestHall))
			{
				AAnimatronics::PGameMode->GetPirateCoveCam()->SetAnimatronics(nullptr);
				AAnimatronics::PGameMode->GetWestHallCam()->SetAnimatronics(PGameMode->GetFoxy());
				FoxyCurPos = static_cast<int>(EFoxyPos::WestHall);
			}
			break;
		case static_cast<int>(EFoxyPos::WestHall):
			limitTime -= _DeltaTime;

			if ("WestHall" == PGameMode->GetCurCam())
			{
				FoxyCurPos = static_cast<int>(EFoxyPos::LeftOffice);
				AAnimatronics::PGameMode->GetStageCCTV()->SetRunningFoxy(true);
			}
			else if (0 > limitTime)
			{
				AAnimatronics::PGameMode->GetWestHallCam()->SetAnimatronics(nullptr);
				FoxyCurPos = static_cast<int>(EFoxyPos::LeftOffice);
			}
			break;
		case static_cast<int>(EFoxyPos::LeftOffice):
			if (12 >= MoveDice && false == AAnimatronics::PGameMode->GetLButton()->GetIsCloseDoor())
			{
				AAnimatronics::PGameMode->GetTheOffice()->SetJumpScareAnimation("JumpScareFoxy");
			}
			else if (12 <= MoveDice && true == AAnimatronics::PGameMode->GetLButton()->GetIsCloseDoor())
			{
				AAnimatronics::PGameMode->GetStageCCTV()->SetRunningFoxy(false);
				AAnimatronics::PGameMode->GetPirateCoveCam()->SetAnimatronics(PGameMode->GetFoxy());
			}
			limitTime = 25.0f;
			break;
		default:
			break;
		}
	}
}
