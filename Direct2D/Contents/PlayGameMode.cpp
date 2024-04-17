#include "PreCompile.h"
#include "PlayGameMode.h"
#include "Lobby.h"
#include "GameDay.h"
#include "StageUI.h"
#include "StageCCTV.h"
#include "LeftButton.h"
#include "RightButton.h"
#include "MouseCursor.h"

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
		std::shared_ptr<ALobby> Lobby = GetWorld()->SpawnActor<ALobby>("Lobby");
		//std::shared_ptr<AGameDay> GameDay = GetWorld()->SpawnActor<AGameDay>("GameDay");
		std::shared_ptr<AStageUI> StageUI = GetWorld()->SpawnActor<AStageUI>("StageUI");
		std::shared_ptr<AStageCCTV> StageCCTV = GetWorld()->SpawnActor<AStageCCTV>("StageCCTV");
		std::shared_ptr<ALeftButton> LeftButton = GetWorld()->SpawnActor<ALeftButton>("LeftButton");
		std::shared_ptr<ARightButton> RightButton = GetWorld()->SpawnActor<ARightButton>("RightButton");
		std::shared_ptr<AMouseCursor> MouseCursor = GetWorld()->SpawnActor<AMouseCursor>("MouseCursor");
	}
	
}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}