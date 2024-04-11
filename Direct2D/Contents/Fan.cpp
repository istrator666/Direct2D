#include "PreCompile.h"
#include "Fan.h"
#include <EngineCore/Renderer.h>

AFan::AFan()
{
	FanRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
}

AFan::~AFan()
{
}

void AFan::BeginPlay()
{
	Super::BeginPlay();


	FanRenderer->SetSprite("Fan.png");
	FanRenderer->CreateAnimation("FanRotation", "Fan.png", 0.1f, true, 0, 2);
	FanRenderer->ChangeAnimation("FanRotation");
	FanRenderer->SetOrder(2);

}

void AFan::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}