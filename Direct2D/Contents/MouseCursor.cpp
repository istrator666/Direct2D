#include "PreCompile.h"
#include "MouseCursor.h"
#include "ContentsEnum.h"
#include "ContentsDefine.h"
#include "LeftButton.h"
#include "RightButton.h"
#include "PlayGameMode.h"

#include <EngineCore/Renderer.h>
#include <EngineCore/DefaultSceneComponent.h>


AMouseCursor::AMouseCursor()
{
	ColMouse = CreateDefaultSubObject<UCollision>("Collision");
	ColMouse->SetScale(FVector{ 50,50 });
	ColMouse->SetCollisionGroup(EColType::Mouse);
	ColMouse->SetCollisionType(ECollisionType::Rect);


	SetRoot(ColMouse);
	InputOn();
}

AMouseCursor::~AMouseCursor()
{
}

void AMouseCursor::BeginPlay()
{
	Super::BeginPlay();
	PGameMode = dynamic_cast<APlayGameMode*>(GetWorld()->GetGameMode().get());
	LButton = PGameMode->GetLButton();
	RButton = PGameMode->GetRButton();
}

void AMouseCursor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	SetMousePos();
	ColLefButton();
	ColRightButton();
}

void AMouseCursor::SetMousePos()
{
	FVector CamPos = GetWorld()->GetMainCamera()->GetActorLocation();
	FVector MousePos = GEngine->EngineWindow.GetScreenMousePos();
	FVector WindowScale = GEngine->EngineWindow.GetWindowScale();
	FVector TargetPos = FVector(CamPos.X, CamPos.Y, 0.0f) + FVector(MousePos.X - WindowScale.hX(), -(MousePos.Y - WindowScale.hY()), 0.0f);
	SetActorLocation(TargetPos);
}

void AMouseCursor::ColLefButton()
{
	ColMouse->CollisionStay(EColType::LeftDoor, [=](std::shared_ptr<UCollision>_Collision)
		{
			if (IsDown(VK_LBUTTON))
			{
				if (false == IsLDoor && false == IsLLight)
				{
					IsLDoor = true;
					LButton->SetButtonImage(2);
					LButton->SetDoorAnimation("LeftDoorClose");
				}
				else if (false == IsLDoor && true == IsLLight)
				{
					IsLDoor = true;
					LButton->SetButtonImage(3);
					LButton->SetDoorAnimation("LeftDoorClose");
				}
				else if (true == IsLDoor && true == IsLLight)
				{
					IsLDoor = false;
					LButton->SetButtonImage(1);
					LButton->SetDoorAnimation("LeftDoorOpen");
				}
				else
				{
					IsLDoor = false;
					LButton->SetButtonImage(0);
					LButton->SetDoorAnimation("LeftDoorOpen");
				}
			}
		}
	);

	ColMouse->CollisionStay(EColType::LeftLight, [=](std::shared_ptr<UCollision>_Collision)
		{
			if (IsDown(VK_LBUTTON))
			{
				if (false == IsLDoor && false == IsLLight)
				{
					IsLLight = true;
					LButton->SetButtonImage(1);
					LButton->SetLightAnimation(true);
				}
				else if (true == IsLDoor && false == IsLLight)
				{
					IsLLight = true;
					LButton->SetButtonImage(3);
				}
				else if (true == IsLDoor && true == IsLLight)
				{
					IsLLight = false;
					LButton->SetButtonImage(2);
				}
				else
				{
					IsLLight = false;
					LButton->SetButtonImage(0);
				}
			}
		}
	);
}

void AMouseCursor::ColRightButton()
{
	ColMouse->CollisionStay(EColType::RightDoor, [=](std::shared_ptr<UCollision>_Collision)
		{
			if (IsDown(VK_LBUTTON))
			{
				if (false == IsRDoor && false == IsRLight)
				{
					IsRDoor = true;
					RButton->SetButtonImage(6);
				}
				else if (false == IsRDoor && true == IsRLight)
				{
					IsRDoor = true;
					RButton->SetButtonImage(7);
				}
				else if (true == IsRDoor && true == IsRLight)
				{
					IsRDoor = false;
					RButton->SetButtonImage(5);
				}
				else
				{
					IsRDoor = false;
					RButton->SetButtonImage(4);
				}
			}
		}
	);

	ColMouse->CollisionStay(EColType::RightLight, [=](std::shared_ptr<UCollision>_Collision)
		{
			if (IsDown(VK_LBUTTON))
			{
				if (false == IsRDoor && false == IsRLight)
				{
					IsRLight = true;
					RButton->SetButtonImage(5);
				}
				else if (true == IsRDoor && false == IsRLight)
				{
					IsRLight = true;
					RButton->SetButtonImage(7);
				}
				else if (true == IsRDoor && true == IsRLight)
				{
					IsRLight = false;
					RButton->SetButtonImage(6);
				}
				else
				{
					IsRLight = false;
					RButton->SetButtonImage(4);
				}
			}
		}
	);
}
