#pragma once
#include <EngineCore/GameMode.h>

class AGameOverGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	// constrcuter destructer
	AGameOverGameMode();
	~AGameOverGameMode();

	// delete Function
	AGameOverGameMode(const AGameOverGameMode& _Other) = delete;
	AGameOverGameMode(AGameOverGameMode&& _Other) noexcept = delete;
	AGameOverGameMode& operator=(const AGameOverGameMode& _Other) = delete;
	AGameOverGameMode& operator=(AGameOverGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:

};

