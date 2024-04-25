#pragma once
#include "EngineCore/Actor.h"

class UImage;

struct CamImage
{
	UImage* CamScreenBox = nullptr;
	UImage* CamName = nullptr;
};


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

	bool GetIsChangeCCTV();

	void SetCCTVUIRendererActvie();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void CCTVActive();

	bool IsCCTV = false;
	UImage* ChangeCCTVAnimation = nullptr;
	UImage* ChangeBarRenderer = nullptr;
	UImage* ChangeBarActiveArea = nullptr;

	UImage* RecordingMark = nullptr;
	UImage* CurMapName = nullptr;
	UImage* CCTVMap = nullptr;

};

