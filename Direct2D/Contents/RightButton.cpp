#include "PreCompile.h"
#include "RightButton.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "ContentsEnum.h"

ARightButton::ARightButton()
{
	UDefaultSceneComponent* RightButtonRoot = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	RightButtonRenerer = CreateDefaultSubObject<USpriteRenderer>("Render");
	RightButtonRenerer->SetupAttachment(RightButtonRoot);
	RightButtonRenerer->SetSprite("RightButton", 0);
	RightButtonRenerer->SetAutoSize(1.0f, true);
	RightButtonRenerer->AddPosition(FVector(400.f, -100.0f, 100.0f));
	RightButtonRenerer->SetOrder(EOrderType::Actor);

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