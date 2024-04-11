#include "PreCompile.h"
#include "TitleMenu.h"

ATitleMenu::ATitleMenu() 
{
	TitleRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
}

ATitleMenu::~ATitleMenu()
{
}

void ATitleMenu::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(1280.0f, 720.0f, 100.0f));


	TitleRenderer->SetSprite("IntroEndings.png", 0);
	TitleRenderer->CreateAnimation("FaceChange", "IntroEndings.png", 0.1f, true, 0, 0);
	//TitleRenderer->ChangeAnimation("FaceChange");
	TitleRenderer->SetOrder(1);

}

void ATitleMenu::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}
