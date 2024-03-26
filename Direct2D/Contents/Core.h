#pragma once
#include <EngineCore/EngineCore.h>

class UCore : public UserCore
{
public:
	// constrcuter destructer
	UCore();
	~UCore();

	// delete Function
	UCore(const UCore& _Other) = delete;
	UCore(UCore&& _Other) noexcept = delete;
	UCore& operator=(const UCore& _Other) = delete;
	UCore& operator=(UCore&& _Other) noexcept = delete;

protected:
	void Initialize() override;

private:

};

