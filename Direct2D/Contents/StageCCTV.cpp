#include "PreCompile.h"
#include "StageCCTV.h"
#include "ContentsEnum.h"

#include <EngineCore/DefaultSceneComponent.h>

AStageCCTV::AStageCCTV()
{
	UDefaultSceneComponent* CCTVRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	CCTVRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	CCTVRenderer->SetupAttachment(CCTVRoot);
	CCTVRenderer->SetSprite("LeftButton", 0);
	CCTVRenderer->SetAutoSize(1.0f, true);
	CCTVRenderer->AddPosition(FVector(-400.f, -100.0f, 0.0f));
	CCTVRenderer->SetOrder(EOrderType::Actor);

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