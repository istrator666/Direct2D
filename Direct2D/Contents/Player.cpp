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
	// 랜더가 이때 들어간간다.


	// 여기서 만들었야하는데.
}

void APlayer::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);


}