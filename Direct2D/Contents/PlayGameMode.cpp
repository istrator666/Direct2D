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
		Fan->SetActorScale3D(FVector(150.0f, 150.0f, 100.0f));
		Fan->AddActorLocation(FVector(300.0f, -50.0f, 100.0f));
	}

	
}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}