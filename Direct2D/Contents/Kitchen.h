#pragma once
#include "Rooms.h"
#include "ContentsEnum.h"

class AKitchen : public ARooms
{
	GENERATED_BODY(ARooms)

public:
	// constrcuter destructer
	AKitchen();
	~AKitchen();

	// delete Function
	AKitchen(const AKitchen& _Other) = delete;
	AKitchen(AKitchen&& _Other) noexcept = delete;
	AKitchen& operator=(const AKitchen& _Other) = delete;
	AKitchen& operator=(AKitchen&& _Other) noexcept = delete;

	int GetCurKitchenCam()
	{
		return CurKitchenCam;
	}

	bool GetIsAnimatronics();

	void SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void KitchenMonsterCheck();

	std::shared_ptr<AAnimatronics> Animatronics = nullptr;
	int CurKitchenCam = static_cast<int>(EKitchen::CameraDisabled);
};

