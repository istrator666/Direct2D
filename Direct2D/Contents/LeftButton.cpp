#include "PreCompile.h"
#include "LeftButton.h"
#include "ContentsEnum.h"

#include <EngineCore/Renderer.h>
#include <EngineCore/DefaultSceneComponent.h>

ALeftButton::ALeftButton()
{
	UDefaultSceneComponent* LeftButtonRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	LeftButtonRenerer = CreateDefaultSubObject<USpriteRenderer>("Render");
	LeftButtonRenerer->SetupAttachment(LeftButtonRoot);
	LeftButtonRenerer->SetSprite("LeftButton", 0);
	LeftButtonRenerer->SetAutoSize(1.0f, true);
	LeftButtonRenerer->AddPosition(FVector(-400.f, -100.0f, 0.0f));
	LeftButtonRenerer->SetOrder(EOrderType::Actor);

	ColLeftDoor = CreateDefaultSubObject<UCollision>("Collision");
	ColLeftDoor->SetupAttachment(LeftButtonRoot);
	ColLeftDoor->SetScale(FVector{ 50,75 });
	ColLeftDoor->AddPosition(FVector(-400.f, -50.0f, 0.0f));
	ColLeftDoor->SetCollisionGroup(EColType::LeftDoor);
	ColLeftDoor->SetCollisionType(ECollisionType::Rect);

	ColLeftLight = CreateDefaultSubObject<UCollision>("Collision");
	ColLeftLight->SetupAttachment(LeftButtonRoot);
	ColLeftLight->SetScale(FVector{ 50,75 });
	ColLeftLight->AddPosition(FVector(-400.f, -150.0f, 0.0f));
	ColLeftLight->SetCollisionGroup(EColType::LeftDoor);
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
