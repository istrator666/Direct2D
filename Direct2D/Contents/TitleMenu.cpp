#include "PreCompile.h"
#include "TitleMenu.h"
#include <EngineCore/DefaultSceneComponent.h>

ATitleMenu::ATitleMenu() 
{
	UDefaultSceneComponent* TitleRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");


	TitleBackgroundRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	TitleBackgroundRenderer->SetupAttachment(TitleRoot);
	TitleBackgroundRenderer->SetScale(FVector(1280.0f, 720.0f, 100.0f));
	TitleBackgroundRenderer->SetSprite("IntroEndings.png", 0);
	//TitleBackgroundRenderer->CreateAnimation("FaceChange", "IntroEndings.png", 0.1f, true, 0, 0);
	//TitleBackgroundRenderer->ChangeAnimation("FaceChange");

	NoiseRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	NoiseRenderer->SetupAttachment(TitleRoot);
	NoiseRenderer->SetScale(FVector(1280.0f, 720.0f, 100.0f));
	NoiseRenderer->SetMaterial("OverlayMaterial");
	NoiseRenderer->CreateAnimation("Noise", "static.png", 0.1f, true, 0, 7);
	NoiseRenderer->ChangeAnimation("Noise");


	CameraEffectsRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	CameraEffectsRenderer->SetupAttachment(TitleRoot);
	CameraEffectsRenderer->SetAutoSize(1.0f, true);
	CameraEffectsRenderer->SetMaterial("OverlayMaterial");
	CameraEffectsRenderer->CreateAnimation("CameraEffects", "CameraEffects.png", 0.1f, true, 0, 15);
	CameraEffectsRenderer->ChangeAnimation("CameraEffects");

	TitleNameRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	TitleNameRenderer->SetupAttachment(TitleRoot);
	TitleNameRenderer->SetMaterial("OverlayMaterial");
	TitleNameRenderer->SetAutoSize(1.0f, true);
	TitleNameRenderer->SetSprite("GameTitle.png", 0);
	TitleNameRenderer->AddPosition(FVector(-350.0f, -20.0f, 100.0f));



	SetRoot(TitleRoot);


}

ATitleMenu::~ATitleMenu()
{
}

void ATitleMenu::BeginPlay()
{
	Super::BeginPlay();

	TitleBackgroundRenderer->SetOrder(1);
	NoiseRenderer->SetOrder(2);
	//CameraEffectsRenderer->SetOrder(2);
	TitleNameRenderer->SetOrder(3);

}

void ATitleMenu::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	DebugMessageFunction();
}

void ATitleMenu::DebugMessageFunction()
{
	{
		std::string Msg = std::format("PlayerPos : {}\n", GetActorLocation().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("MousePos : {}\n", GEngine->EngineWindow.GetScreenMousePos().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

}