#pragma once
#include "EngineCore/Actor.h"
#include "ContentsEnum.h"

class APlayGameMode;
class ABonnie;
class AChica;
class AFreddy;
class ADiningArea : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ADiningArea();
	~ADiningArea();

	// delete Function
	ADiningArea(const ADiningArea& _Other) = delete;
	ADiningArea(ADiningArea&& _Other) noexcept = delete;
	ADiningArea& operator=(const ADiningArea& _Other) = delete;
	ADiningArea& operator=(ADiningArea&& _Other) noexcept = delete;

	int GetCurDiningAreaCam()
	{
		return CurDiningAreaCam;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void DiningAreaMonsterCheck();

	APlayGameMode* PGMode = nullptr;
	std::shared_ptr<ABonnie> Bonnie = nullptr;
	std::shared_ptr<AChica> Chica = nullptr;
	std::shared_ptr<AFreddy> Freddy = nullptr;

	int CurDiningAreaCam = static_cast<int>(EDiningArea::DiningArea_Default);
};

