#include "PreCompile.h"
#include "Freddy.h"

AFreddy::AFreddy()
{
}

AFreddy::~AFreddy()
{
}

void AFreddy::BeginPlay()
{
	Super::BeginPlay();
}

void AFreddy::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AFreddy::FreddyMove()
{
	// 프레디는 보니와 치카가 쇼 스테이지에 없을때 움직일 수 있다.
	// 프레디는 한 번 움직이면 뒤로가지 않는다. 공격 실패시에만 뒤로 갔다가 다시 공격한다.
	// Cam1A -> Cam1B -> Cam7 -> Cam6 -> Cam4A -> Cam4B -> RighrOffice -> Attack
	// 실패하면 Cam1B로 가서 다시 순서대로 진행


}
