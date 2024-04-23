#include "PreCompile.h"
#include "StageCCTV.h"
#include "ContentsEnum.h"

#include <EngineCore/DefaultSceneComponent.h>

AStageCCTV::AStageCCTV()
{
	UDefaultSceneComponent* CCTVRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	ChangeCCTVRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	ChangeCCTVRenderer->SetupAttachment(CCTVRoot);
	ChangeCCTVRenderer->CreateAnimation("CCTVON", "Camera.png", 0.04f, false, 0, 10);
	ChangeCCTVRenderer->ChangeAnimation("CCTVON");
	ChangeCCTVRenderer->SetAutoSize(1.0f, true);
	//ChangeCCTVRenderer->AddPosition(FVector(-400.f, -100.0f, 0.0f));
	ChangeCCTVRenderer->SetOrder(EOrderType::Cutscene);
	ChangeCCTVRenderer->SetActive(false);

	CCTVRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	CCTVRenderer->SetupAttachment(CCTVRoot);
	CCTVRenderer->SetSprite("Buttons.png", 0);
	CCTVRenderer->SetAutoSize(1.0f, true);
	CCTVRenderer->AddPosition(FVector(-400.f, -100.0f, 0.0f));
	CCTVRenderer->SetOrder(EOrderType::Actor);
	CCTVRenderer->SetActive(false);

	SetRoot(CCTVRoot);

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

	if (true == ChangeCCTVRenderer->IsCurAnimationEnd())
	{
		ChangeCCTVRenderer->SetActive(false);
	}

}


void AStageCCTV::SetRendererActive(USpriteRenderer* _Renderer)
{
	_Renderer->SetActive(true);
}
