#include "PreCompile.h"
#include "Stage.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/EngineDebugMsgWindow.h>

AStage::AStage() 
{
	TheOfficeRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
}

AStage::~AStage()
{
}

void AStage::BeginPlay()
{
	Super::BeginPlay();

	TheOfficeRenderer->SetSprite("TheOffice.png");
	TheOfficeRenderer->SetOrder(1);

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