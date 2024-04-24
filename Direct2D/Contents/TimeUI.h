#pragma once
#include <EngineCore/Actor.h>

class UImage;

class ATimeUI : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ATimeUI();
	~ATimeUI();

	// delete Function
	ATimeUI(const ATimeUI& _Other) = delete;
	ATimeUI(ATimeUI&& _Other) noexcept = delete;
	ATimeUI& operator=(const ATimeUI& _Other) = delete;
	ATimeUI& operator=(ATimeUI&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

