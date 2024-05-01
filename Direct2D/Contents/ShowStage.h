#pragma once
#include "EngineCore/Actor.h"
#include "ContentsEnum.h"

class APlayGameMode;
class ABonnie;
class AShowStage : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AShowStage();
	~AShowStage();

	// delete Function
	AShowStage(const AShowStage& _Other) = delete;
	AShowStage(AShowStage&& _Other) noexcept = delete;
	AShowStage& operator=(const AShowStage& _Other) = delete;
	AShowStage& operator=(AShowStage&& _Other) noexcept = delete;

	int GetCurShowStageCam()
	{
		return CurShowStageCam;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void ShowStageMonsterCheck();

	APlayGameMode* PGMode = nullptr;
	std::shared_ptr<ABonnie> Bonnie = nullptr;

	int CurShowStageCam = static_cast<int>(EShowStage::ShowStage_Default);
};

