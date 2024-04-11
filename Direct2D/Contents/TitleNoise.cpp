#include "PreCompile.h"
#include "TitleNoise.h"

ATitleNoise::ATitleNoise()
{
	NoiseRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
}

ATitleNoise::~ATitleNoise()
{
}

void ATitleNoise::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(1280.0f, 720.0f, 100.0f));

	NoiseRenderer->SetMaterial("OverlayMaterial");
	NoiseRenderer->GetMaterial();
	NoiseRenderer->CreateAnimation("Noise", "static.png", 0.1f, true, 0, 7);
	NoiseRenderer->ChangeAnimation("Noise");
	NoiseRenderer->SetOrder(2);

}

void ATitleNoise::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}