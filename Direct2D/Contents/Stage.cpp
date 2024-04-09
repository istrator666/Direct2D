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

	TheOfficeRenderer->SetSprite("TheOffice.png");
	TheOfficeRenderer->CreateAnimation("Office", "TheOffice.png", 0.5f, true, 0, 3);
	//TheOfficeRenderer->ChangeAnimation("Office");
}

void AStage::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}