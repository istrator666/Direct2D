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

	SetActorScale3D(FVector(1280.0f, 720.0f, 100.0f));

	TheOfficeRenderer->SetSprite("static.png");
	TheOfficeRenderer->CreateAnimation("Office", "static.png", 0.01f, true, 0, 7);
	TheOfficeRenderer->ChangeAnimation("Office");
}

void AStage::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}