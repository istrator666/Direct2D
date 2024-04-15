#include "PreCompile.h"
#include "TitleSelect.h"

ATitleSelect::ATitleSelect()
{
	TitleSelectRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	TitleSelectRenderer->SetMaterial("OverlayMaterial");
	TitleSelectRenderer->SetAutoSize(1.0f, true);
	TitleSelectRenderer->SetSprite("Select.png", 0);
	TitleSelectRenderer->AddPosition(FVector(-500.0f, -70.0f, 100.0f));

	SetRoot(TitleSelectRenderer);
}

ATitleSelect::~ATitleSelect()
{
}

void ATitleSelect::BeginPlay()
{
	Super::BeginPlay();

	TitleSelectRenderer->SetOrder(2);

}

void ATitleSelect::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}