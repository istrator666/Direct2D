#include "PreCompile.h"
#include "Animatronics.h"
#include "PlayGameMode.h"

AAnimatronics::AAnimatronics()
{
}

AAnimatronics::~AAnimatronics()
{
}

void AAnimatronics::BeginPlay()
{
	Super::BeginPlay();
	PGameMode = dynamic_cast<APlayGameMode*>(GetWorld()->GetGameMode().get());
}

void AAnimatronics::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
