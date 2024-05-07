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
	TheOfficeRenderer->SetSprite("The Office", static_cast<int>(ETheOffice::TheOffice));
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

	JumpScareRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	JumpScareRenderer->SetupAttachment(StageRoot);
	JumpScareRenderer->CreateAnimation("JumpScareBonnie", "JumpScareBonnie", 0.1f, true, 0, 10);
	JumpScareRenderer->CreateAnimation("JumpScareChica", "JumpScareChica", 0.1f, true, 0, 15);
	JumpScareRenderer->CreateAnimation("JumpScareFreddy", "JumpScareFreddy", 0.1f, true, 0, 27);
	JumpScareRenderer->CreateAnimation("JumpScareFoxy", "JumpScareFoxy", 0.1f, true, 0, 20);
	JumpScareRenderer->SetAutoSize(1.0f, true);
	JumpScareRenderer->SetOrder(EOrderType::Actor);

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

	//if (JumpScareRenderer->IsCurAnimationEnd())
	//{
	//	JumpScareRenderer->SetActive(false);
	//}

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