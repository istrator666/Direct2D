#include "PreCompile.h"
#include "TitleSelect.h"
#include "TitleGameMode.h"
#include "TitleMenu.h"

#include "ContentsEnum.h"

#include <EngineCore/Renderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "ContentsDebug.cpp"

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
	MenuSwitchSound.Off();
}

void ATitleSelect::BeginPlay()
{
	Super::BeginPlay();

	TGameMode = dynamic_cast<ATitleGameMode*>(GetWorld()->GetGameMode().get());
	TitleMenu = TGameMode->GetTitleMenu();

	//TitleMusic = UEngineSound::SoundPlay("TitleMusic.wav");
	//TitleMusic.Loop();
	//StaticLong = UEngineSound::SoundPlay("StaticLong.wav");
	//StaticLong.Loop();

	MenuSwitchSound = UEngineSound::SoundPlay("CCTVSwitch.wav");
	MenuSwitchSound.SetVolume(0.5f);
	MenuSwitchSound.Off();
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

			//if (false == IsMenuSwitchSound)
			//{
			//	IsMenuSwitchSound = true;
			//	MenuSwitchSound.On();
			//	MenuSwitchSound.Replay();
			//}

			if (true == IsDown(VK_LBUTTON))
			{
				GEngine->ChangeLevel("PlayLevel");
			}
		});

	ColMouse->CollisionStay(EColType::Continue, [=](std::shared_ptr<UCollision>_Collision)
		{
			TitleMenu->SetTitleSelectPos(-140.0f);

			//if (true == IsMenuSwitchSound)
			//{
			//	IsMenuSwitchSound = false;
			//	MenuSwitchSound.On();
			//	MenuSwitchSound.Replay();
			//}

			if (true == IsDown(VK_LBUTTON))
			{
				// �̾�ϱ�?
				// GEngine->ChangeLevel("PlayLevel");
			}
		});
}