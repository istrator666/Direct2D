#pragma once
class ABackStage
{
public:
	// constrcuter destructer
	ABackStage();
	~ABackStage();

	// delete Function
	ABackStage(const ABackStage& _Other) = delete;
	ABackStage(ABackStage&& _Other) noexcept = delete;
	ABackStage& operator=(const ABackStage& _Other) = delete;
	ABackStage& operator=(ABackStage&& _Other) noexcept = delete;

protected:

private:

};

