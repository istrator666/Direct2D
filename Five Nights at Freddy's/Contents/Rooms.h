#pragma once

#include "EngineCore/Actor.h"
#include "Animatronics.h"

class ARooms : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ARooms();
	~ARooms();

	// delete Function
	ARooms(const ARooms& _Other) = delete;
	ARooms(ARooms&& _Other) noexcept = delete;
	ARooms& operator=(const ARooms& _Other) = delete;
	ARooms& operator=(ARooms&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	virtual void SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics);
	


private:

};

