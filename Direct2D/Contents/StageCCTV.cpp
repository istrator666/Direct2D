#include "PreCompile.h"
#include "StageCCTV.h"
#include "ContentsEnum.h"

#include <EngineCore/DefaultSceneComponent.h>

AStageCCTV::AStageCCTV()
{
	UDefaultSceneComponent* CCTVRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	ShowStageRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	ShowStageRenderer->SetupAttachment(CCTVRoot);
	ShowStageRenderer->CreateAnimation("ShowStage", "ShowStage", 0.1f, false, 0, 0);
	ShowStageRenderer->ChangeAnimation("ShowStage");
	ShowStageRenderer->SetAutoSize(1.0f, true);
	ShowStageRenderer->AddPosition(FVector(0.0f, 0.0f, 0.0f));
	ShowStageRenderer->SetOrder(EOrderType::CCTVActor);
	ShowStageRenderer->SetActive(false);

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

\

}


void AStageCCTV::SetRendererActive(USpriteRenderer* _Renderer)
{
	_Renderer->SetActive(true);
}
