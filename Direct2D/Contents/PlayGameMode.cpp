#include "PreCompile.h"
#include "PlayGameMode.h"
#include "Stage.h"
#include "GameDay.h"
#include <EngineCore/Camera.h>


APlayGameMode::APlayGameMode() 
{
}

APlayGameMode::~APlayGameMode() 
{
}

void APlayGameMode::BeginPlay() 
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	{
		std::shared_ptr<AStage> Lobby = GetWorld()->SpawnActor<AStage>("Stage");
	}

	{
		std::shared_ptr<AGameDay> GameDay = GetWorld()->SpawnActor<AGameDay>("GameDay");
	}

	
}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}