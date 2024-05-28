#pragma once
#include "Rooms.h"
#include "ContentsEnum.h"

class ABonnie;
class AChica;
class AFreddy;
class AShowStage : public ARooms
{
	GENERATED_BODY(ARooms)

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

	void SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void ShowStageMonsterCheck();
	std::vector<std::shared_ptr<AAnimatronics>> Animatronics;

	int CurShowStageCam = static_cast<int>(EShowStage::ShowStage_Default);

	ABonnie* Bonnie = nullptr;
	AChica* Chica = nullptr;
	AFreddy* Freddy = nullptr;
};

