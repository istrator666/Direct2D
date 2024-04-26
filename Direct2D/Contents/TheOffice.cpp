#include "PreCompile.h"
#include "TheOffice.h"
#include "ContentsEnum.h"

#include <EngineCore/Renderer.h>
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/DefaultSceneComponent.h>

ATheOffice::ATheOffice()
{
	UDefaultSceneComponent* StageRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	TheOfficeRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	TheOfficeRenderer->SetupAttachment(StageRoot);
	TheOfficeRenderer->SetSprite("TheOffice.png");
	TheOfficeRenderer->SetAutoSize(1.0f, true);
	TheOfficeRenderer->SetOrder(EOrderType::Background);

	FanRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	FanRenderer->SetupAttachment(StageRoot);
	FanRenderer->SetSprite("Fan.png");
	FanRenderer->CreateAnimation("FanRotation", "Fan.png", 0.01f, true, 0, 2);
	FanRenderer->ChangeAnimation("FanRotation");
	FanRenderer->SetAutoSize(1.0f, true);
	FanRenderer->AddPosition(FVector(48.0f, -41.0f, 0.0f));
	FanRenderer->SetOrder(EOrderType::Actor);


	SetRoot(StageRoot);

}

ATheOffice::~ATheOffice()
{
}

void ATheOffice::BeginPlay()
{
	Super::BeginPlay();
}

void ATheOffice::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	DebugMessageFunction();

}

void ATheOffice::DebugMessageFunction()
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