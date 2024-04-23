#include "PreCompile.h"
#include "RightButton.h"
#include "ContentsEnum.h"
#include "ContentsDefine.h"

#include <EngineCore/Renderer.h>
#include <EngineCore/DefaultSceneComponent.h>

ARightButton::ARightButton()
{
	UDefaultSceneComponent* RightButtonRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	RightButtonRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	RightButtonRenderer->SetupAttachment(RightButtonRoot);
	RightButtonRenderer->SetSprite("Buttons.png", RightButtonOFF);
	RightButtonRenderer->SetAutoSize(1.0f, true);
	RightButtonRenderer->AddPosition(FVector(700.f, -50.0f, 0.0f));
	RightButtonRenderer->SetOrder(EOrderType::Actor);

	ColRightDoor = CreateDefaultSubObject<UCollision>("Collision");
	ColRightDoor->SetupAttachment(RightButtonRoot);
	ColRightDoor->SetScale(FVector{ 50,50 });
	ColRightDoor->AddPosition(FVector(700.f, 0.0f, 0.0f));
	ColRightDoor->SetCollisionGroup(EColType::RightDoor);
	ColRightDoor->SetCollisionType(ECollisionType::Rect);

	ColRightLight = CreateDefaultSubObject<UCollision>("Collision");
	ColRightLight->SetupAttachment(RightButtonRoot);
	ColRightLight->SetScale(FVector{ 50,50 });
	ColRightLight->AddPosition(FVector(700.f, -100.0f, 0.0f));
	ColRightLight->SetCollisionGroup(EColType::RightLight);
	ColRightLight->SetCollisionType(ECollisionType::Rect);

	SetRoot(RightButtonRoot);

}

ARightButton::~ARightButton()
{
}

void ARightButton::BeginPlay()
{
	Super::BeginPlay();



}

void ARightButton::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}