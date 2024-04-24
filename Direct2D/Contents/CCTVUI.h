#pragma once
#include "EngineCore/Actor.h"

class UImage;

class ACCTVUI : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ACCTVUI();
	~ACCTVUI();

	// delete Function
	ACCTVUI(const ACCTVUI& _Other) = delete;
	ACCTVUI(ACCTVUI&& _Other) noexcept = delete;
	ACCTVUI& operator=(const ACCTVUI& _Other) = delete;
	ACCTVUI& operator=(ACCTVUI&& _Other) noexcept = delete;

	bool GetIsCCTV()
	{
		return IsCCTV;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void CCTVActive();

	bool IsCCTV = false;
	UImage* ChangeCCTVAnimation = nullptr;
	UImage* ChangeBarRenderer = nullptr;
	UImage* ChangeBarActiveArea = nullptr;

};

