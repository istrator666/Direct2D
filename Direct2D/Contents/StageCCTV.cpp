#include "PreCompile.h"
#include "StageCCTV.h"
#include "ContentsEnum.h"

#include <EngineCore/DefaultSceneComponent.h>

AStageCCTV::AStageCCTV()
{
	UDefaultSceneComponent* CCTVRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	StageCCTVRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	StageCCTVRenderer->SetupAttachment(CCTVRoot);
	StageCCTVRenderer->SetSprite("ShowStage", 0);
	StageCCTVRenderer->SetAutoSize(1.0f, true);
	StageCCTVRenderer->AddPosition(FVector(0.0f, 0.0f, 0.0f));
	StageCCTVRenderer->SetOrder(EOrderType::CCTVActor);
	StageCCTVRenderer->SetActive(false);

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

}


void AStageCCTV::SetRendererActive(bool _Active)
{
	StageCCTVRenderer->SetActive(_Active);
}
