#include "PreCompile.h"
#include "Stage.h"
#include <EngineCore/Renderer.h>

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

}