#include "PreCompile.h"
#include "TitleLogo.h"

ATitleLogo::ATitleLogo() 
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");

}

int Index = 0;

ATitleLogo::~ATitleLogo() 
{
}

void ATitleLogo::RendererOn()
{
	Renderer->SetSprite("Camera.png", 11);
	//Renderer->SetActive(true);
	DelayCallBack(0.2f, std::bind(&ATitleLogo::RendererOff, this));

	// ++Index;
}

void ATitleLogo::RendererOff()
{
	Renderer->SetSprite("Camera.png", 11);
	//Renderer->SetActive(false);
	DelayCallBack(0.2f, std::bind(&ATitleLogo::RendererOn, this));

	// ++Index;
}

void ATitleLogo::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(1280.0f, 720.0f, 100.0f));

	DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));

	// Renderer->SetSamplering(ETextureSampling::LINEAR);
	Renderer->SetSprite("Camera.png", 11);

	Renderer->CreateAnimation("Run", "Camera.png", 0.1f);

	Renderer->ChangeAnimation("Run");

}

void ATitleLogo::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	int a = 0;
}
