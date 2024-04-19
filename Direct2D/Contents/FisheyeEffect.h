#pragma once
#include "EngineCore/EngineRenderTarget.h"

class UFisheyeEffect : public UEffect
{
public:
	// constrcuter destructer
	UFisheyeEffect();
	~UFisheyeEffect();

	// delete Function
	UFisheyeEffect(const UFisheyeEffect& _Other) = delete;
	UFisheyeEffect(UFisheyeEffect&& _Other) noexcept = delete;
	UFisheyeEffect& operator=(const UFisheyeEffect& _Other) = delete;
	UFisheyeEffect& operator=(UFisheyeEffect&& _Other) noexcept = delete;

protected:
	void Init() override;
	void Effect(std::shared_ptr<UEngineRenderTarget> EffectTarget) override;

private:
	std::shared_ptr<UEngineRenderTarget> CopyTarget;

};

