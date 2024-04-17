#include "PreCompile.h"
#include "MouseCursor.h"
#include "StageCCTV.h"
#include "ContentsEnum.h"

#include <EngineCore/Renderer.h>
#include <EngineCore/DefaultSceneComponent.h>

AMouseCursor::AMouseCursor()
{
	ColMouse = CreateDefaultSubObject<UCollision>("Collision");
	ColMouse->SetScale(FVector{ 50,50 });
	ColMouse->SetCollisionGroup(EColType::Mouse);
	ColMouse->SetCollisionType(ECollisionType::Rect);


	SetRoot(ColMouse);
}

AMouseCursor::~AMouseCursor()
{
}

void AMouseCursor::BeginPlay()
{
	Super::BeginPlay();


}

void AMouseCursor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	SetMousePos();

	ColMouse->CollisionEnter(EColType::ChangeBar, [=](std::shared_ptr<UCollision>_Collision)
		{
			std::string ObjectType = _Collision->GetActor()->GetName();

			if ("StageUI" == ObjectType)
			{
				int a = 0;

			}
		}
	);
}

void AMouseCursor::SetMousePos()
{
	FVector CamPos = GetWorld()->GetMainCamera()->GetActorLocation();
	FVector MousePos = GEngine->EngineWindow.GetScreenMousePos();
	FVector WindowScale = GEngine->EngineWindow.GetWindowScale();
	FVector TargetPos = FVector(CamPos.X, CamPos.Y, 0.0f) + FVector(MousePos.X - WindowScale.hX(), -(MousePos.Y - WindowScale.hY()), 0.0f);
	SetActorLocation(TargetPos);
}
