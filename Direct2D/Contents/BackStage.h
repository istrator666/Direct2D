#pragma once
#include "EngineCore/Actor.h"
#include "Rooms.h"
#include "ContentsEnum.h"

class APlayGameMode;
class ABonnie;
class ABackStage : public ARooms
{
	GENERATED_BODY(ARooms)

public:
	// constrcuter destructer
	ABackStage();
	~ABackStage();

	// delete Function
	ABackStage(const ABackStage& _Other) = delete;
	ABackStage(ABackStage&& _Other) noexcept = delete;
	ABackStage& operator=(const ABackStage& _Other) = delete;
	ABackStage& operator=(ABackStage&& _Other) noexcept = delete;

	int GetCurBackStageCam()
	{
		return CurBackStageCam;
	}

	bool GetIsAnimatronics();

	void SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void BackStageMonsterCheck();
	void FCamTimeCheck(float _DeltaTime);

	APlayGameMode* PGameMode = nullptr;
	ABonnie* Bonnie = nullptr;
	float CamTimeCheck = 5.0f;
	std::shared_ptr<AAnimatronics> Animatronics = nullptr;
	int CurBackStageCam = static_cast<int>(EBackstage::BackStage_Default);

};

