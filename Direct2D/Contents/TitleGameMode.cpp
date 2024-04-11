#include "PreCompile.h"
#include "TitleGameMode.h"
#include "TitleMenu.h"
#include "TitleNoise.h"
#include <EngineCore/Camera.h>

ATitleGameMode::ATitleGameMode() 
{
	InputOn();
}

ATitleGameMode::~ATitleGameMode() 
{
}

void ATitleGameMode::BeginPlay() 
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	{
		std::shared_ptr<ATitleMenu> TitleMenu =GetWorld()->SpawnActor<ATitleMenu>("TitleMenu");
	}

	{
		std::shared_ptr<ATitleNoise> TitleNoise = GetWorld()->SpawnActor<ATitleNoise>("TitleNoise");
	}
	
}

void ATitleGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == IsDown('P'))
	{
		GEngine->ChangeLevel("PlayLevel");
	}
}

void ATitleGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void ATitleGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

}