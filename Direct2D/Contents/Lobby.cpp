#include "PreCompile.h"
#include "Lobby.h"
#include "ContentsEnum.h"

#include <EngineCore/Renderer.h>
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/DefaultSceneComponent.h>

ALobby::ALobby()
{
	UDefaultSceneComponent* StageRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	TheOfficeRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	TheOfficeRenderer->SetupAttachment(StageRoot);
	TheOfficeRenderer->SetSprite("TheOffice.png");
	TheOfficeRenderer->SetScale(FVector(1500.0f, 720.0f, 100.0f));
	TheOfficeRenderer->SetOrder(EOrderType::Background);
	TheOfficeRenderer->SetActive(false);

	FanRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	FanRenderer->SetupAttachment(StageRoot);
	FanRenderer->SetSprite("Fan.png");
	FanRenderer->CreateAnimation("FanRotation", "Fan.png", 0.01f, true, 0, 2);
	FanRenderer->ChangeAnimation("FanRotation");
	FanRenderer->SetScale(FVector(130.0f, 200.0f, 100.0f));
	FanRenderer->AddPosition(FVector(45.0f, -41.0f, 0.0f));
	FanRenderer->SetOrder(EOrderType::Actor);


	SetRoot(StageRoot);
}

ALobby::~ALobby()
{
}

void ALobby::BeginPlay()
{
	Super::BeginPlay();

}

void ALobby::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	DebugMessageFunction();

}

void ALobby::DebugMessageFunction()
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