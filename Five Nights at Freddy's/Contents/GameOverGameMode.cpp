#include "PreCompile.h"
#include "GameOverGameMode.h"
#include "ContentsDebug.h"
#include "TitleGameMode.h"
#include "GameOver.h"

#include <EngineCore/Camera.h>

AGameOverGameMode::AGameOverGameMode()
{

}

AGameOverGameMode::~AGameOverGameMode()
{
}

void AGameOverGameMode::BeginPlay()
{
	Super::BeginPlay();
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	std::shared_ptr<AGameOver> GameOver = GetWorld()->SpawnActor<AGameOver>("GameOver");
}

void AGameOverGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AGameOverGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
	UContentsDebug::StageNumber = 2;
	GEngine->CreateLevel<ATitleGameMode>("TitleLevel");
}

void AGameOverGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
	GEngine->DestroyLevel("GameOverLevel");
}

