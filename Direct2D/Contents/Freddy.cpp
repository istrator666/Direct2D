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
	// ������� ���Ͽ� ġī�� �� ���������� ������ ������ �� �ִ�.
	// ������� �� �� �����̸� �ڷΰ��� �ʴ´�. ���� ���нÿ��� �ڷ� ���ٰ� �ٽ� �����Ѵ�.
	// Cam1A -> Cam1B -> Cam7 -> Cam6 -> Cam4A -> Cam4B -> RighrOffice -> Attack
	// �����ϸ� Cam1B�� ���� �ٽ� ������� ����


}
