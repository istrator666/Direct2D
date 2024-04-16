#include "PreCompile.h"
#include "Stage.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/DefaultSceneComponent.h>

AStage::AStage() 
{
	UDefaultSceneComponent* StageRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	TheOfficeRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	TheOfficeRenderer->SetupAttachment(StageRoot);
	TheOfficeRenderer->SetSprite("TheOffice.png");
	TheOfficeRenderer->SetScale(FVector(1500.0f, 720.0f, 100.0f));
	TheOfficeRenderer->SetOrder(1);

	FanRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	FanRenderer->SetupAttachment(StageRoot);
	FanRenderer->SetSprite("Fan.png");
	FanRenderer->CreateAnimation("FanRotation", "Fan.png", 0.01f, true, 0, 2);
	FanRenderer->ChangeAnimation("FanRotation");
	FanRenderer->SetScale(FVector(110.0f, 200.0f, 100.0f));
	FanRenderer->AddPosition(FVector(38.5f, -41.0f, 0.0f));
	FanRenderer->SetOrder(2);

	SetRoot(StageRoot);
}

AStage::~AStage()
{
}

void AStage::BeginPlay()
{
	Super::BeginPlay();



}

void AStage::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	DebugMessageFunction();

}

void AStage::DebugMessageFunction()
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