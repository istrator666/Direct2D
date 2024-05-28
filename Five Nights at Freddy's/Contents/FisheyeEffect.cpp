#include "PreCompile.h"
#include "FisheyeEffect.h"
#include "EngineCore/EngineCore.h"
#include "Core.h"

UFisheyeEffect::UFisheyeEffect()
{
}

UFisheyeEffect::~UFisheyeEffect()
{
}

void UFisheyeEffect::Init()
{
	SetMaterial("FisheyeMaterial");

	CopyTarget = UEngineRenderTarget::Create();
	float4 Scale = GEngine->EngineWindow.GetWindowScale();
	CopyTarget->CreateTexture(DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT, Scale, float4::Zero);
}

void UFisheyeEffect::Effect(std::shared_ptr<UEngineRenderTarget> EffectTarget)
{
	CopyTarget->Copy(EffectTarget);
	EffectTarget->Clear();
	EffectTarget->Setting();

	Resources->SettingTexture("Image", CopyTarget->GetTexture(), "POINT");

	Render(0.0f);

}