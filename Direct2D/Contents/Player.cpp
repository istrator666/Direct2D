#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/Renderer.h>

APlayer::APlayer() 
{
	Renderer = CreateDefaultSubObject<URenderer>("Renderer");

	Renderer->SetMesh("Rect");
	Renderer->SetMaterial("2DImage");

	// Renderer->CreateConstBuffer("FTransform", Sizeof(Ftransform), 0);

	// Renderer->SetData("FTransform", Gettransfom());

	//cbuffer OutPutColor : register(b0)
	//{
	//	float4 Color;
	//};

	// Renderer->Createconstbuffer("OutPutColor", float4::Red);
	
	// Renderer->SetData("OutPutColor", float4::Red);

	size_t Size = sizeof(FTransform);

	int a = 0;

}

APlayer::~APlayer() 
{
}

void APlayer::BeginPlay()
{
	Super::BeginPlay();
	// ������ �̶� ������.


	// ���⼭ ��������ϴµ�.
}

void APlayer::Tick(float _DeltaTime)
{
	// ���� ������ �ľ��Ҷ��� �ִ�.
	Super::Tick(_DeltaTime);


}