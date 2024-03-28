#include "PreCompile.h"
#include "Core.h"
#include "PlayGameMode.h"

UCore::UCore()
{
}

UCore::~UCore()
{
}

void UCore::Initialize()
{
	GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->ChangeLevel("PlayLevel");

	//{
	//	UEngineDirectory Dir;
	//	Dir.MoveToSearchChild("ContentsResources");
	//	Dir.Move("Sound");

	//	std::list<UEngineFile> Files = Dir.AllFile({ ".wav" });
	//	for (UEngineFile& File : Files)
	//	{
	//		UEngineSound::Load(File.GetFullPath());
	//	}

	//	UEngineSound::SoundPlay("anipang_ingame_wav.wav");
	//}

	int a = 0;
}