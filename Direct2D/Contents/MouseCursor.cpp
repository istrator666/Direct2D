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
				if (false == LButton->GetIsCloseDoor() && false == LButton->GetIsLight())
				{
					++PowerMeterUpDownCheck;
					LButton->SetIsCloseDoor(true);
					LButton->SetButtonImage(LeftDoorON);
					LButton->SetDoorAnimation("LeftDoorClose");
				}
				else if (false == LButton->GetIsCloseDoor() && true == LButton->GetIsLight())
				{
					++PowerMeterUpDownCheck;
					LButton->SetIsCloseDoor(true);
					LButton->SetButtonImage(LeftButtonAllOn);
					LButton->SetDoorAnimation("LeftDoorClose");
				}
				else if (true == LButton->GetIsCloseDoor() && true == LButton->GetIsLight())
				{
					--PowerMeterUpDownCheck;
					LButton->SetIsCloseDoor(false);
					LButton->SetButtonImage(LeftLightON);
					LButton->SetDoorAnimation("LeftDoorOpen");
				}
				else
				{
					--PowerMeterUpDownCheck;
					LButton->SetIsCloseDoor(false);
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
				if (false == LButton->GetIsCloseDoor() && false == LButton->GetIsLight() && false == LButton->GetIsBonnie())
				{
					++PowerMeterUpDownCheck;
					LButton->SetIsLight(true);
					LButton->SetButtonImage(LeftLightON);
					LButton->SetLightAnimation(true, "LeftLightON");

					if (false == RButton->GetIsCloseDoor() && true == RButton->GetIsLight())
					{
						--PowerMeterUpDownCheck;
						RButton->SetIsLight(false);
						RButton->SetButtonImage(RightButtonAllOFF);
						RButton->SetLightAnimation(false, "RightLightON");
						RButton->SetLightAnimation(false, "RightChicaOn");
					}
					else if (true == RButton->GetIsCloseDoor() && true == RButton->GetIsLight())
					{
						--PowerMeterUpDownCheck;
						RButton->SetIsLight(false);
						RButton->SetButtonImage(RightDoorON);
						RButton->SetLightAnimation(false, "RightLightON");
						RButton->SetLightAnimation(false, "RightChicaOn");
					}
				}
				else if (true == LButton->GetIsCloseDoor() && false == LButton->GetIsLight() && false == LButton->GetIsBonnie())
				{
					++PowerMeterUpDownCheck;
					LButton->SetIsLight(true);
					LButton->SetButtonImage(LeftButtonAllOn);
					LButton->SetLightAnimation(true, "LeftLightON");

					if (false == RButton->GetIsCloseDoor() && true == RButton->GetIsLight())
					{
						--PowerMeterUpDownCheck;
						RButton->SetIsLight(false);
						RButton->SetButtonImage(RightButtonAllOFF);
						RButton->SetLightAnimation(false, "RightLightON");
						RButton->SetLightAnimation(false, "RightChicaOn");
					}
					else if (true == RButton->GetIsCloseDoor() && true == RButton->GetIsLight())
					{
						--PowerMeterUpDownCheck;
						RButton->SetIsLight(false);
						RButton->SetButtonImage(RightDoorON);
						RButton->SetLightAnimation(false, "RightLightON");
						RButton->SetLightAnimation(false, "RightChicaOn");
					}
				}
				else if (true == LButton->GetIsCloseDoor() && true == LButton->GetIsLight() && false == LButton->GetIsBonnie())
				{
					--PowerMeterUpDownCheck;
					LButton->SetIsLight(false);
					LButton->SetButtonImage(LeftDoorON);
					LButton->SetLightAnimation(false, "LeftLightON");
				}
				else if (false == LButton->GetIsCloseDoor() && true == LButton->GetIsLight() && false == LButton->GetIsBonnie())
				{
					--PowerMeterUpDownCheck;
					LButton->SetIsLight(false);
					LButton->SetButtonImage(LeftButtonAllOFF);
					LButton->SetLightAnimation(false, "LeftLightON");
				}
				// 보니가 있을 때
				else if (false == LButton->GetIsCloseDoor() && false == LButton->GetIsLight() && true == LButton->GetIsBonnie())
				{
					++PowerMeterUpDownCheck;
					LButton->SetIsLight(true);
					LButton->SetButtonImage(LeftLightON);
					LButton->SetLightAnimation(true, "LeftBonnieON");

					if (false == RButton->GetIsCloseDoor() && true == RButton->GetIsLight())
					{
						--PowerMeterUpDownCheck;
						RButton->SetIsLight(false);
						RButton->SetButtonImage(RightButtonAllOFF);
						RButton->SetLightAnimation(false, "RightLightON");
						RButton->SetLightAnimation(false, "RightChicaOn");
					}
					else if (true == RButton->GetIsCloseDoor() && true == RButton->GetIsLight())
					{
						--PowerMeterUpDownCheck;
						RButton->SetIsLight(false);
						RButton->SetButtonImage(RightDoorON);
						RButton->SetLightAnimation(false, "RightLightON");
						RButton->SetLightAnimation(false, "RightChicaOn");
					}
				}
				else if (true == LButton->GetIsCloseDoor() && false == LButton->GetIsLight() && true == LButton->GetIsBonnie())
				{
					++PowerMeterUpDownCheck;
					LButton->SetIsLight(true);
					LButton->SetButtonImage(LeftButtonAllOn);
					LButton->SetLightAnimation(true, "LeftBonnieON");

					if (false == RButton->GetIsCloseDoor() && true == RButton->GetIsLight())
					{
						--PowerMeterUpDownCheck;
						RButton->SetIsLight(false);
						RButton->SetButtonImage(RightButtonAllOFF);
						RButton->SetLightAnimation(false, "RightLightON");
						RButton->SetLightAnimation(false, "RightChicaOn");
					}
					else if (true == RButton->GetIsCloseDoor() && true == RButton->GetIsLight())
					{
						--PowerMeterUpDownCheck;
						RButton->SetIsLight(false);
						RButton->SetButtonImage(RightDoorON);
						RButton->SetLightAnimation(false, "RightLightON");
						RButton->SetLightAnimation(false, "RightChicaOn");
					}
				}
				else if (true == LButton->GetIsCloseDoor() && true == LButton->GetIsLight() && true == LButton->GetIsBonnie())
				{
					--PowerMeterUpDownCheck;
					LButton->SetIsLight(false);
					LButton->SetButtonImage(LeftDoorON);
					LButton->SetLightAnimation(false, "LeftBonnieON");
				}
				else if (false == LButton->GetIsCloseDoor() && true == LButton->GetIsLight() && true == LButton->GetIsBonnie())
				{
					--PowerMeterUpDownCheck;
					LButton->SetIsLight(false);
					LButton->SetButtonImage(LeftButtonAllOFF);
					LButton->SetLightAnimation(false, "LeftBonnieON");
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
				if (false == RButton->GetIsCloseDoor() && false == RButton->GetIsLight())
				{
					++PowerMeterUpDownCheck;
					RButton->SetIsCloseDoor(true);
					RButton->SetButtonImage(RightDoorON);
					RButton->SetDoorAnimation("RightDoorClose");
				}
				else if (false == RButton->GetIsCloseDoor() && true == RButton->GetIsLight())
				{
					++PowerMeterUpDownCheck;
					RButton->SetIsCloseDoor(true);
					RButton->SetButtonImage(RightButtonAllOn);
					RButton->SetDoorAnimation("RightDoorClose");
				}
				else if (true == RButton->GetIsCloseDoor() && true == RButton->GetIsLight())
				{
					--PowerMeterUpDownCheck;
					RButton->SetIsCloseDoor(false);
					RButton->SetButtonImage(RightLightON);
					RButton->SetDoorAnimation("RightDoorOpen");
				}
				else
				{
					--PowerMeterUpDownCheck;
					RButton->SetIsCloseDoor(false);
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
				if (false == RButton->GetIsCloseDoor() && false == RButton->GetIsLight() && false == RButton->GetIsChica())
				{
					++PowerMeterUpDownCheck;
					RButton->SetIsLight(true);
					RButton->SetButtonImage(RightLightON);
					RButton->SetLightAnimation(true, "RightLightON");

					if (false == LButton->GetIsCloseDoor() && true == LButton->GetIsLight())
					{
						--PowerMeterUpDownCheck;
						LButton->SetIsLight(false);
						LButton->SetButtonImage(LeftButtonAllOFF);
						LButton->SetLightAnimation(false, "LeftLightON");
						LButton->SetLightAnimation(false, "LeftBonnieON");
					}
					else if (true == LButton->GetIsCloseDoor() && true == LButton->GetIsLight())
					{
						--PowerMeterUpDownCheck;
						LButton->SetIsLight(false);
						LButton->SetButtonImage(LeftDoorON);
						LButton->SetLightAnimation(false, "LeftLightON");
						LButton->SetLightAnimation(false, "LeftBonnieON");
					}
				}
				else if (true == RButton->GetIsCloseDoor() && false == RButton->GetIsLight() && false == RButton->GetIsChica())
				{
					++PowerMeterUpDownCheck;
					RButton->SetIsLight(true);
					RButton->SetButtonImage(RightButtonAllOn);
					RButton->SetLightAnimation(true, "RightLightON");

					if (false == LButton->GetIsCloseDoor() && true == LButton->GetIsLight())
					{
						--PowerMeterUpDownCheck;
						LButton->SetIsLight(false);
						LButton->SetButtonImage(LeftButtonAllOFF);
						LButton->SetLightAnimation(false, "LeftLightON");
						LButton->SetLightAnimation(false, "LeftBonnieON");
					}
					else if (true == LButton->GetIsCloseDoor() && true == LButton->GetIsLight())
					{
						--PowerMeterUpDownCheck;
						LButton->SetIsLight(false);
						LButton->SetButtonImage(LeftDoorON);
						LButton->SetLightAnimation(false, "LeftLightON");
						LButton->SetLightAnimation(false, "LeftBonnieON");
					}
				}
				else if (true == RButton->GetIsCloseDoor() && true == RButton->GetIsLight() && false == RButton->GetIsChica())
				{
					--PowerMeterUpDownCheck;
					RButton->SetIsLight(false);
					RButton->SetButtonImage(RightDoorON);
					RButton->SetLightAnimation(false, "RightLightON");
				}
				else if (false == RButton->GetIsCloseDoor() && true == RButton->GetIsLight() && false == RButton->GetIsChica())
				{
					--PowerMeterUpDownCheck;
					RButton->SetIsLight(false);
					RButton->SetButtonImage(RightButtonAllOFF);
					RButton->SetLightAnimation(false, "RightLightON");
				}

				// 치카가 있을 때
				else if (false == RButton->GetIsCloseDoor() && false == RButton->GetIsLight() && true == RButton->GetIsChica())
				{
					++PowerMeterUpDownCheck;
					RButton->SetIsLight(true);
					RButton->SetButtonImage(RightLightON);
					RButton->SetLightAnimation(true, "RightChicaOn");

					if (false == LButton->GetIsCloseDoor() && true == LButton->GetIsLight())
					{
						--PowerMeterUpDownCheck;
						LButton->SetIsLight(false);
						LButton->SetButtonImage(LeftButtonAllOFF);
						LButton->SetLightAnimation(false, "LeftLightON");
						LButton->SetLightAnimation(false, "LeftBonnieON");
					}
					else if (true == LButton->GetIsCloseDoor() && true == LButton->GetIsLight())
					{
						--PowerMeterUpDownCheck;
						LButton->SetIsLight(false);
						LButton->SetButtonImage(LeftDoorON);
						LButton->SetLightAnimation(false, "LeftLightON");
						LButton->SetLightAnimation(false, "LeftBonnieON");
					}
				}
				else if (true == RButton->GetIsCloseDoor() && false == RButton->GetIsLight() && true == RButton->GetIsChica())
				{
					++PowerMeterUpDownCheck;
					RButton->SetIsLight(true);
					RButton->SetButtonImage(RightButtonAllOn);
					RButton->SetLightAnimation(true, "RightChicaOn");

					if (false == LButton->GetIsCloseDoor() && true == LButton->GetIsLight())
					{
						--PowerMeterUpDownCheck;
						LButton->SetIsLight(false);
						LButton->SetButtonImage(LeftButtonAllOFF);
						LButton->SetLightAnimation(false, "LeftLightON");
						LButton->SetLightAnimation(false, "LeftBonnieON");
					}
					else if (true == LButton->GetIsCloseDoor() && true == LButton->GetIsLight())
					{
						--PowerMeterUpDownCheck;
						LButton->SetIsLight(false);
						LButton->SetButtonImage(LeftDoorON);
						LButton->SetLightAnimation(false, "LeftLightON");
						LButton->SetLightAnimation(false, "LeftBonnieON");
					}
				}
				else if (true == RButton->GetIsCloseDoor() && true == RButton->GetIsLight() && true == RButton->GetIsChica())
				{
					--PowerMeterUpDownCheck;
					RButton->SetIsLight(false);
					RButton->SetButtonImage(RightDoorON);
					RButton->SetLightAnimation(false, "RightChicaOn");
				}
				else if (false == RButton->GetIsCloseDoor() && true == RButton->GetIsLight() && true == RButton->GetIsChica())
				{
					--PowerMeterUpDownCheck;
					RButton->SetIsLight(false);
					RButton->SetButtonImage(RightButtonAllOFF);
					RButton->SetLightAnimation(false, "RightChicaOn");
				}
			}
		}
	);
}
