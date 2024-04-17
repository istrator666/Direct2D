#include "PreCompile.h"
#include "LeftButton.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "ContentsEnum.h"

ALeftButton::ALeftButton()
{
	UDefaultSceneComponent* LeftButtonRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	LeftButtonRenerer = CreateDefaultSubObject<USpriteRenderer>("Render");
	LeftButtonRenerer->SetupAttachment(LeftButtonRoot);
	LeftButtonRenerer->SetSprite("LeftButton", 0);
	LeftButtonRenerer->SetAutoSize(1.0f, true);
	LeftButtonRenerer->AddPosition(FVector(-400.f, -100.0f, 100.0f));
	LeftButtonRenerer->SetOrder(EOrderType::Actor);

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
