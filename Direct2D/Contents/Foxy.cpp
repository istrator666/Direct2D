#include "PreCompile.h"
#include "Foxy.h"

#include "PirateCove.h"
#include "LeftButton.h"

AFoxy::AFoxy()
{
}

AFoxy::~AFoxy()
{
}

void AFoxy::BeginPlay()
{
	Super::BeginPlay();
}

void AFoxy::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	FoxyMove();
}

void AFoxy::FoxyMove()
{

}
