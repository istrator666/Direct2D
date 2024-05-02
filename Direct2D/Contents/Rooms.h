#pragma once

#include "EngineCore/Actor.h"
#include "Animatronics.h"

class Rooms : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	Rooms();
	~Rooms();

	// delete Function
	Rooms(const Rooms& _Other) = delete;
	Rooms(Rooms&& _Other) noexcept = delete;
	Rooms& operator=(const Rooms& _Other) = delete;
	Rooms& operator=(Rooms&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	virtual void SetAnimatronics(std::shared_ptr<AAnimatronics> _Animatronics);
	


private:

};

