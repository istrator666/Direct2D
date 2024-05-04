#include "PreCompile.h"
#include "LeftButton.h"
#include "ContentsEnum.h"
#include "ContentsDefine.h"

#include <EngineCore/Renderer.h>
#include <EngineCore/DefaultSceneComponent.h>

ALeftButton::ALeftButton()
{
	UDefaultSceneComponent* LeftButtonRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	LeftButtonRenderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	LeftButtonRenderer->SetupAttachment(LeftButtonRoot);
	LeftButtonRenderer->SetSprite("Buttons.png", LeftButtonAllOFF);
	LeftButtonRenderer->SetAutoSize(1.0f, true);
	LeftButtonRenderer->AddPosition(FVector(-750.0f, -50.0f, 0.0f));
	LeftButtonRenderer->SetOrder(EOrderType::Actor);

	LeftDoorAnimation = CreateDefaultSubObject<USpriteRenderer>("Render");
	LeftDoorAnimation->SetupAttachment(LeftButtonRoot);
	LeftDoorAnimation->CreateAnimation("LeftDoorClose", "LeftDoor", 0.05f, false, 0, 14);
	LeftDoorAnimation->CreateAnimation("LeftDoorOpen", "LeftDoor", 0.05f, false, 14, 0);
	LeftDoorAnimation->SetFrameCallback("LeftDoorOpen", 14, [=] { LeftDoorAnimation->SetActive(false); });
	LeftDoorAnimation->SetAutoSize(1.0f, true);
	LeftDoorAnimation->AddPosition(FVector(-620.0f, 0.0f, 0.0f));
	LeftDoorAnimation->SetOrder(EOrderType::Actor);

	LeftLightAnimation = CreateDefaultSubObject<USpriteRenderer>("Render");
	LeftLightAnimation->SetupAttachment(LeftButtonRoot);
	LeftLightAnimation->CreateAnimation("LeftLightON", "LeftLight", 0.05f, true, 0, 1);
	LeftLightAnimation->CreateAnimation("LeftBonnieON", "LeftBonnieLight", 0.05f, true, 0, 1);
	LeftLightAnimation->ChangeAnimation("LeftLightON");
	LeftLightAnimation->SetAutoSize(1.0f, true);
	LeftLightAnimation->SetOrder(EOrderType::Actor);
	LeftLightAnimation->SetActive(false);

	ColLeftDoor = CreateDefaultSubObject<UCollision>("Collision");
	ColLeftDoor->SetupAttachment(LeftButtonRoot);
	ColLeftDoor->SetScale(FVector{ 50,50 });
	ColLeftDoor->AddPosition(FVector(-750.0f, 0.0f, 0.0f));
	ColLeftDoor->SetCollisionGroup(EColType::LeftDoor);
	ColLeftDoor->SetCollisionType(ECollisionType::Rect);

	ColLeftLight = CreateDefaultSubObject<UCollision>("Collision");
	ColLeftLight->SetupAttachment(LeftButtonRoot);
	ColLeftLight->SetScale(FVector{ 50,50 });
	ColLeftLight->AddPosition(FVector(-750.0f, -100.0f, 0.0f));
	ColLeftLight->SetCollisionGroup(EColType::LeftLight);
	ColLeftLight->SetCollisionType(ECollisionType::Rect);

	SetRoot(LeftButtonRoot);
}

ALeftButton::~ALeftButton()
{
}

void ALeftButton::BeginPlay()
{
	Super::BeginPlay();



}

void ALeftButton::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	

}
