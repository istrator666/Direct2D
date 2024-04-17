#include "PreCompile.h"
#include "TitleMenu.h"
#include <EngineCore/DefaultSceneComponent.h>
#include "ContentsEnum.h"

ATitleMenu::ATitleMenu() 
{
	UDefaultSceneComponent* TitleRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");


	TitleBackgroundRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	TitleBackgroundRenderer->SetupAttachment(TitleRoot);
	TitleBackgroundRenderer->SetScale(FVector(1280.0f, 720.0f, 100.0f));
	TitleBackgroundRenderer->SetSprite("IntroEndings.png", 0);
	//TitleBackgroundRenderer->CreateAnimation("FaceChange", "IntroEndings.png", 0.1f, true, 0, 0);
	//TitleBackgroundRenderer->ChangeAnimation("FaceChange");
	TitleBackgroundRenderer->SetOrder(EOrderType::Background);

	NoiseRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	NoiseRenderer->SetupAttachment(TitleRoot);
	NoiseRenderer->SetScale(FVector(1280.0f, 720.0f, 100.0f));
	NoiseRenderer->SetMaterial("OverlayMaterial");
	NoiseRenderer->CreateAnimation("Noise", "static.png", 0.1f, true, 0, 7);
	NoiseRenderer->ChangeAnimation("Noise");
	NoiseRenderer->SetOrder(EOrderType::Overlay);


	CameraEffectsRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	CameraEffectsRenderer->SetupAttachment(TitleRoot);
	CameraEffectsRenderer->SetAutoSize(1.0f, true);
	CameraEffectsRenderer->SetMaterial("OverlayMaterial");
	CameraEffectsRenderer->CreateAnimation("CameraEffects", "CameraEffects.png", 0.1f, true, 0, 15);
	CameraEffectsRenderer->ChangeAnimation("CameraEffects");
	//CameraEffectsRenderer->SetOrder(2);

	TitleNameRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	TitleNameRenderer->SetupAttachment(TitleRoot);
	TitleNameRenderer->SetMaterial("OverlayMaterial");
	TitleNameRenderer->SetAutoSize(1.0f, true);
	TitleNameRenderer->SetSprite("GameTitle.png", 0);
	TitleNameRenderer->AddPosition(FVector(-350.0f, -20.0f, 100.0f));
	TitleNameRenderer->SetOrder(EOrderType::Overlay);


	SetRoot(TitleRoot);


}

ATitleMenu::~ATitleMenu()
{
}

void ATitleMenu::BeginPlay()
{
	Super::BeginPlay();


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