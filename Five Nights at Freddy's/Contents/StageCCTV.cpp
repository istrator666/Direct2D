#include "PreCompile.h"
#include "StageCCTV.h"
#include "ContentsEnum.h"
#include "PlayGameMode.h"
#include "ShowStage.h"

#include <EngineCore/DefaultSceneComponent.h>

AStageCCTV::AStageCCTV()
{
	CCTVRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	StageCCTVRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	StageCCTVRenderer->SetupAttachment(CCTVRoot);
	StageCCTVRenderer->SetSprite("ShowStage", 5);
	StageCCTVRenderer->SetAutoSize(1.0f, true);
	StageCCTVRenderer->AddPosition(FVector(0.0f, 0.0f, 0.0f));
	StageCCTVRenderer->SetOrder(EOrderType::CCTVActor);

	StaticRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	StaticRenderer->SetupAttachment(CCTVRoot);
	StaticRenderer->SetMulColor({ 1.0f,1.0f,1.0f, 0.2f });
	StaticRenderer->CreateAnimation("Noise", "Static.png", 0.1f, true, 0, 7);
	StaticRenderer->ChangeAnimation("Noise");
	StaticRenderer->SetScale(FVector(1600.0f, 720.0f, 0.0f));
	StaticRenderer->AddPosition(FVector(0.0f, 0.0f, 0.0f));
	StaticRenderer->SetOrder(EOrderType::Overlay);

	AnimatronicsMoveRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	AnimatronicsMoveRenderer->SetupAttachment(CCTVRoot);
	AnimatronicsMoveRenderer->SetSprite("DayBackground.png");
	AnimatronicsMoveRenderer->SetScale(FVector(1600.0f, 720.0f, 0.0f));
	AnimatronicsMoveRenderer->SetOrder(EOrderType::Overlay);
	AnimatronicsMoveRenderer->SetActive(false);

	AnimatronicsMoveScanRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	AnimatronicsMoveScanRenderer->SetupAttachment(CCTVRoot);
	AnimatronicsMoveScanRenderer->CreateAnimation("ScanLineAni", "ScanLine", 0.1f, false, 0, 6);
	AnimatronicsMoveScanRenderer->ChangeAnimation("ScanLineAni");
	AnimatronicsMoveScanRenderer->SetScale(FVector(1600.0f, 720.0f, 0.0f));
	AnimatronicsMoveScanRenderer->SetOrder(EOrderType::OverlayF);
	AnimatronicsMoveScanRenderer->SetActive(false);

	RunningFoxy = CreateDefaultSubObject<USpriteRenderer>("Render");
	RunningFoxy->SetupAttachment(CCTVRoot);
	RunningFoxy->CreateAnimation("RunningFoxy", "RunningFoxy", 0.05f, false, 0, 30);
	RunningFoxy->SetAutoSize(1.0f, true);
	RunningFoxy->AddPosition(FVector(0.0f, 0.0f, 0.0f));
	RunningFoxy->SetOrder(EOrderType::Cutscene);

	KitchenBackRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	KitchenBackRenderer->SetupAttachment(CCTVRoot);
	KitchenBackRenderer->SetSprite("Kitchen", 1);
	KitchenBackRenderer->SetAutoSize(1.0f, true);
	KitchenBackRenderer->AddPosition(FVector(0.0f, 0.0f, 0.0f));
	KitchenBackRenderer->SetOrder(EOrderType::CCTVActor);

	SetRoot(CCTVRoot);

	CCTVRoot->SetActive(false);
}

void AStageCCTV::SetRendererActive(bool _Active)
{
	{
		CCTVRoot->SetActive(_Active);
	}
}

void AStageCCTV::SetStageCCTVRenderer(std::string_view _SelectMap, int _Index)
{
	StageCCTVRenderer->SetSprite(_SelectMap, _Index);
}

AStageCCTV::~AStageCCTV()
{
}

void AStageCCTV::BeginPlay()
{
	Super::BeginPlay();
}

void AStageCCTV::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}
