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

	{
		// ������ ���
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("ContentsResources");
		Dir.Move("Miscellaneous");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : Files)
		{
			//File.Open(EIOOpenMode::Read, EIODataType::Binary);

			//char Arr[100];
			//File.Read(Arr, 100);

			UEngineTexture::Load(File.GetFullPath());
		}
		// UEngineSound::SoundPlay("anipang_ingame_wav.wav");
	}


	//{
	//	UEngineDirectory Dir;
	//	Dir.MoveToSearchChild("ContentsResources");
	//	Dir.Move("Sound");
	//	std::vector<UEngineFile> Files = Dir.GetAllFile({ ".wav" });
	//	for (UEngineFile& File : Files)
	//	{
	//		File.Open(EIOOpenMode::Read, EIODataType::Binary);

	//		char Arr[100];
	//		File.Read(Arr, 100);

	//		UEngineSound::Load(File.GetFullPath());
	//	}
	//	 UEngineSound::SoundPlay("anipang_ingame_wav.wav");
	//}

	GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->ChangeLevel("PlayLevel");


}