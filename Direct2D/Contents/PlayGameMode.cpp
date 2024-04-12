#include "PreCompile.h"
#include "PlayGameMode.h"
#include "Stage.h"
#include "Fan.h"
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
		Lobby->SetActorScale3D(FVector(1280.0f, 720.0f, 100.0f));
	}

	{
		std::shared_ptr<AFan> Fan = GetWorld()->SpawnActor<AFan>("Fan");
		Fan->AddActorScale3D(FVector(110.0f, 200.0f, 100.0f));
		Fan->AddActorLocation(FVector(38.0f, -40.0f, 100.0f));
	}

	
}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}