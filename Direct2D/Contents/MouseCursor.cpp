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
					LButton->SetButtonImage(LeftDoorON);
					LButton->SetDoorAnimation("LeftDoorClose");
				}
				else if (false == IsLDoor && true == IsLLight)
				{
					IsLDoor = true;
					LButton->SetButtonImage(LeftButtonAllOn);
					LButton->SetDoorAnimation("LeftDoorClose");
				}
				else if (true == IsLDoor && true == IsLLight)
				{
					IsLDoor = false;
					LButton->SetButtonImage(LeftLightON);
					LButton->SetDoorAnimation("LeftDoorOpen");
				}
				else
				{
					IsLDoor = false;
					LButton->SetButtonImage(LeftButtonAllOFF);
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
					LButton->SetButtonImage(LeftLightON);
					LButton->SetLightAnimation(true);
				}
				else if (true == IsLDoor && false == IsLLight)
				{
					IsLLight = true;
					LButton->SetButtonImage(LeftButtonAllOn);
					LButton->SetLightAnimation(true);
				}
				else if (true == IsLDoor && true == IsLLight)
				{
					IsLLight = false;
					LButton->SetButtonImage(LeftDoorON);
					LButton->SetLightAnimation(false);
				}
				else
				{
					IsLLight = false;
					LButton->SetButtonImage(LeftButtonAllOFF);
					LButton->SetLightAnimation(false);
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
					RButton->SetButtonImage(RightDoorON);
					RButton->SetDoorAnimation("RightDoorClose");
				}
				else if (false == IsRDoor && true == IsRLight)
				{
					IsRDoor = true;
					RButton->SetButtonImage(RightButtonAllOn);
					RButton->SetDoorAnimation("RightDoorClose");
				}
				else if (true == IsRDoor && true == IsRLight)
				{
					IsRDoor = false;
					RButton->SetButtonImage(RightLightON);
					RButton->SetDoorAnimation("RightDoorOpen");
				}
				else
				{
					IsRDoor = false;
					RButton->SetButtonImage(RightButtonAllOFF);
					RButton->SetDoorAnimation("RightDoorOpen");
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
					RButton->SetButtonImage(RightLightON);
					RButton->SetLightAnimation(true);
				}
				else if (true == IsRDoor && false == IsRLight)
				{
					IsRLight = true;
					RButton->SetButtonImage(RightButtonAllOn);
					RButton->SetLightAnimation(true);
				}
				else if (true == IsRDoor && true == IsRLight)
				{
					IsRLight = false;
					RButton->SetButtonImage(RightDoorON);
					RButton->SetLightAnimation(false);
				}
				else
				{
					IsRLight = false;
					RButton->SetButtonImage(RightButtonAllOFF);
					RButton->SetLightAnimation(false);
				}
			}
		}
	);
}
