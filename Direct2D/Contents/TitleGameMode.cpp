#include "PreCompile.h"
#include "TitleGameMode.h"
#include "TitleMenu.h"
#include "TitleSelect.h"
#include <EngineCore/Camera.h>

ATitleGameMode::ATitleGameMode() 
{

}

ATitleGameMode::~ATitleGameMode() 
{
}

void ATitleGameMode::BeginPlay() 
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	SetActor();
	SetUI();

}

void ATitleGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ATitleGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void ATitleGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

}

void ATitleGameMode::SetActor()
{
	TitleMenu = GetWorld()->SpawnActor<ATitleMenu>("TitleMenu");
	std::shared_ptr<ATitleSelect> TitleSelect = GetWorld()->SpawnActor<ATitleSelect>("TitleSelect");
}

void ATitleGameMode::SetUI()
{

}
