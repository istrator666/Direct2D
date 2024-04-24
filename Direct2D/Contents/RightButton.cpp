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
	RightButtonRenderer->SetSprite("Buttons.png", RightButtonAllOFF);
	RightButtonRenderer->SetAutoSize(1.0f, true);
	RightButtonRenderer->AddPosition(FVector(750.f, -50.0f, 0.0f));
	RightButtonRenderer->SetOrder(EOrderType::Actor);

	RightDoorAnimation = CreateDefaultSubObject<USpriteRenderer>("Render");
	RightDoorAnimation->SetupAttachment(RightButtonRoot);
	RightDoorAnimation->CreateAnimation("RightDoorClose", "RightDoor", 0.05f, false, 0, 14);
	RightDoorAnimation->CreateAnimation("RightDoorOpen", "RightDoor", 0.05f, false, 14, 0);
	RightDoorAnimation->SetFrameCallback("RightDoorOpen", 14, [=] { RightDoorAnimation->SetActive(false); });
	RightDoorAnimation->SetAutoSize(1.0f, true);
	RightDoorAnimation->AddPosition(FVector(580.0f, 0.0f, 0.0f));
	RightDoorAnimation->SetOrder(EOrderType::Actor);

	RightLightAnimation = CreateDefaultSubObject<USpriteRenderer>("Render");
	RightLightAnimation->SetupAttachment(RightButtonRoot);
	RightLightAnimation->CreateAnimation("RightLightON", "RightLight", 0.05f, true, 0, 1);
	RightLightAnimation->ChangeAnimation("RightLightON");
	RightLightAnimation->SetAutoSize(1.0f, true);
	RightLightAnimation->SetOrder(EOrderType::Overlay);
	RightLightAnimation->SetActive(false);

	ColRightDoor = CreateDefaultSubObject<UCollision>("Collision");
	ColRightDoor->SetupAttachment(RightButtonRoot);
	ColRightDoor->SetScale(FVector{ 50,50 });
	ColRightDoor->AddPosition(FVector(750.f, 0.0f, 0.0f));
	ColRightDoor->SetCollisionGroup(EColType::RightDoor);
	ColRightDoor->SetCollisionType(ECollisionType::Rect);

	ColRightLight = CreateDefaultSubObject<UCollision>("Collision");
	ColRightLight->SetupAttachment(RightButtonRoot);
	ColRightLight->SetScale(FVector{ 50,50 });
	ColRightLight->AddPosition(FVector(750.f, -100.0f, 0.0f));
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