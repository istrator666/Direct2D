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
	// �÷��̾ CCTV CAM�� ���� ������ �ൿ��ȸ�� ���� ���� (����)
	// �÷��̾ Cam�� ������ ���� 0.83 ~ 16.67 �� �ð��� �ο��ǰ� �� ������ ���� �ܰ�� ����
	// 1�ܰ� Ŀư�� ������ ����
	// 2�ܰ� Ŀư�� ���� �Ĵٺ��� ����
	// 3�ܰ� Ŀư ������ ���� �Ĵٺ��� ����
	// 3�ܰ迡�� �ൿ��ȸ�� ������ Ż���ؼ� �÷��̾ �ִ� ������ ����

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
