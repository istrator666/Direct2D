#include "PreCompile.h"
#include "TitleSelect.h"
#include "TitleGameMode.h"
#include "TitleMenu.h"

#include "ContentsEnum.h"


#include <EngineCore/Renderer.h>
#include <EngineCore/DefaultSceneComponent.h>

ATitleSelect::ATitleSelect()
{
	ColMouse = CreateDefaultSubObject<UCollision>("Collision");
	ColMouse->SetScale(FVector{ 50,50 });
	ColMouse->SetCollisionGroup(EColType::Mouse);
	ColMouse->SetCollisionType(ECollisionType::Rect);

	SetRoot(ColMouse);

	InputOn();
}

ATitleSelect::~ATitleSelect()
{
}

void ATitleSelect::BeginPlay()
{
	Super::BeginPlay();

	TGameMode = dynamic_cast<ATitleGameMode*>(GetWorld()->GetGameMode().get());
	TitleMenu = TGameMode->GetTitleMenu();
}

void ATitleSelect::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	SetMousePos();
	ColSelectMenu();

}

void ATitleSelect::SetMousePos()
{
	FVector CamPos = GetWorld()->GetMainCamera()->GetActorLocation();
	FVector MousePos = GEngine->EngineWindow.GetScreenMousePos();
	FVector WindowScale = GEngine->EngineWindow.GetWindowScale();
	FVector TargetPos = FVector(CamPos.X, CamPos.Y, 0.0f) + FVector(MousePos.X - WindowScale.hX(), -(MousePos.Y - WindowScale.hY()), 0.0f);
	SetActorLocation(TargetPos);
}

void ATitleSelect::ColSelectMenu()
{
	ColMouse->CollisionStay(EColType::Start, [=](std::shared_ptr<UCollision>_Collision)
		{
			TitleMenu->SetTitleSelectPos(-70.0f);

			if (true == IsDown(VK_LBUTTON))
			{
				GEngine->ChangeLevel("PlayLevel");
			}
		});

	ColMouse->CollisionStay(EColType::Continue, [=](std::shared_ptr<UCollision>_Collision)
		{
			TitleMenu->SetTitleSelectPos(-140.0f);

			if (true == IsDown(VK_LBUTTON))
			{
				// 이어서하기?
				// GEngine->ChangeLevel("PlayLevel");
			}
		});
}
