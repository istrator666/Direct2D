#pragma once
#include "SceneComponent.h"
#include "EngineMesh.h"
#include "EngineMaterial.h"

// 설명 : public std::enable_shared_from_this<URenderer>
// shared_ptr로 this를 배출할수 있는 기능을 가진 클래스입니다.

// URenderer는 지금 뭐든지 할수 있는 상황이다.
// 모든랜더링을 다할수 있다.
// 그러면 안된다.
// 기능이 집약되지 않았고 특화기능을 만들수가 없다.
// 특화기능?

// 랜더러는 순수하게 랜더링에 관련된 애가 아니다.
// 액터 오더 등등등
class UEngineShaderResources;
class URenderer : public USceneComponent, public std::enable_shared_from_this<URenderer>
{
	friend ULevel;
	GENERATED_BODY(USceneComponent)

public:

	// constrcuter destructer
	URenderer();
	~URenderer();

	// delete Function
	URenderer(const URenderer& _Other) = delete;
	URenderer(URenderer&& _Other) noexcept = delete;
	URenderer& operator=(const URenderer& _Other) = delete;
	URenderer& operator=(URenderer&& _Other) noexcept = delete;


	std::shared_ptr<UEngineMesh> GetMesh()
	{
		return Mesh;
	}

	std::shared_ptr<UEngineMaterial> GetMaterial()
	{
		return Material;
	}

	void SetMesh(std::string_view _Name);
	void SetMaterial(std::string_view _Name);
	virtual void MaterialSettingEnd() {}

	std::shared_ptr<UEngineShaderResources> Resources;

	template<typename EnumType>
	void SetOrder(EnumType _Order)
	{
		SetOrder(static_cast<int>(_Order));
	}

	void SetOrder(int _Order) override;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RenderingSetting();

	void ResCopy(UEngineShader* _Shader);

private:
	void RenderingTransformUpdate(std::shared_ptr<UCamera> _Camera);

	virtual void Render(float _DeltaTime);

	std::shared_ptr<UEngineInputLayOut> LayOut;
	std::shared_ptr<UEngineMesh> Mesh;
	std::shared_ptr<UEngineMaterial> Material;
};

