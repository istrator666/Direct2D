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
	LeftButtonRenderer->SetSprite("Buttons.png", LeftButtonOFF);
	LeftButtonRenderer->SetAutoSize(1.0f, true);
	LeftButtonRenderer->AddPosition(FVector(-700.f, -50.0f, 0.0f));
	LeftButtonRenderer->SetOrder(EOrderType::Actor);

	LeftDoorAnimation = CreateDefaultSubObject<USpriteRenderer>("Render");
	LeftDoorAnimation->SetupAttachment(LeftButtonRoot);
	LeftDoorAnimation->CreateAnimation("LeftDoorOpen", "LeftDoor", 0.1f, false, 0, 16);
	LeftDoorAnimation->CreateAnimation("LeftDoorClose", "LeftDoor", 0.1f, false, 16, 0);
	LeftDoorAnimation->SetAutoSize(1.0f, true);
	LeftDoorAnimation->AddPosition(FVector(-700.f, -50.0f, 0.0f));
	LeftDoorAnimation->SetOrder(EOrderType::Actor);
	LeftDoorAnimation->SetActive(false);

	LeftLightAnimation = CreateDefaultSubObject<USpriteRenderer>("Render");

	ColLeftDoor = CreateDefaultSubObject<UCollision>("Collision");
	ColLeftDoor->SetupAttachment(LeftButtonRoot);
	ColLeftDoor->SetScale(FVector{ 50,50 });
	ColLeftDoor->AddPosition(FVector(-700.f, 0.0f, 0.0f));
	ColLeftDoor->SetCollisionGroup(EColType::LeftDoor);
	ColLeftDoor->SetCollisionType(ECollisionType::Rect);

	ColLeftLight = CreateDefaultSubObject<UCollision>("Collision");
	ColLeftLight->SetupAttachment(LeftButtonRoot);
	ColLeftLight->SetScale(FVector{ 50,50 });
	ColLeftLight->AddPosition(FVector(-700.f, -100.0f, 0.0f));
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