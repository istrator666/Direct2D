#include "PreCompile.h"
#include "StageCCTV.h"
#include "ContentsEnum.h"

#include <EngineCore/DefaultSceneComponent.h>

AStageCCTV::AStageCCTV()
{
	CCTVRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	StageCCTVRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	StageCCTVRenderer->SetupAttachment(CCTVRoot);
	StageCCTVRenderer->SetSprite("ShowStage", 0);
	StageCCTVRenderer->SetAutoSize(1.0f, true);
	StageCCTVRenderer->AddPosition(FVector(0.0f, 0.0f, 0.0f));
	StageCCTVRenderer->SetOrder(EOrderType::CCTVActor);

	KitchenBackgroundRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	KitchenBackgroundRenderer->SetupAttachment(CCTVRoot);
	KitchenBackgroundRenderer->SetSprite("Kitchen", 1);
	KitchenBackgroundRenderer->SetAutoSize(1.0f, true);
	KitchenBackgroundRenderer->AddPosition(FVector(0.0f, 0.0f, 0.0f));
	KitchenBackgroundRenderer->SetOrder(EOrderType::CCTVActor);
	KitchenBackgroundRenderer->SetActive(false);

	StaticRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	StaticRenderer->SetupAttachment(CCTVRoot);
	StaticRenderer->SetMaterial("OverlayMaterial");
	StaticRenderer->CreateAnimation("Noise", "Static.png", 0.1f, true, 0, 7);
	StaticRenderer->ChangeAnimation("Noise");
	StaticRenderer->SetScale(FVector(1600.0f, 720.0f, 0.0f));
	StaticRenderer->AddPosition(FVector(0.0f, 0.0f, 0.0f));
	StaticRenderer->SetOrder(EOrderType::Overlay);


	SetRoot(CCTVRoot);

	CCTVRoot->SetActive(false);

}

void AStageCCTV::SetRendererActive(bool _Active)
{
	{
		CCTVRoot->SetActive(_Active);
	}
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
