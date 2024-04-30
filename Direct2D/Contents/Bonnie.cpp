#include "PreCompile.h"
#include "Bonnie.h"

Bonnie::Bonnie()
{

}

Bonnie::~Bonnie()
{
}

void Bonnie::BeginPlay()
{
	Super::BeginPlay();
}

void Bonnie::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

bool Bonnie::GetIsBonnie()
{
	if (true == Bonnie1A)
	{
		return true;
	}
	else if (true == Bonnie1B)
	{
		return true;
	}
	else if (true == Bonnie2A)
	{
		return true;
	}
	else if (true == Bonnie2B)
	{
		return true;
	}
	else if (true == Bonnie3)
	{
		return true;
	}

	return false;
}
