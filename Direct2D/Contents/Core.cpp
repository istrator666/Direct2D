#include "PreCompile.h"
#include "Core.h"
#include "PlayGameMode.h"
#include "TitleGameMode.h"
#include <EngineCore/EngineSprite.h>
#include <EngineCore/EnginePixelShader.h>

UCore::UCore()
{
}

UCore::~UCore()
{
}

void UCore::Initialize()
{
	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("ContentsShader");
		UEngineShader::AutoCompile(Dir);
	}

	// 머티리얼 생성
	{
		std::shared_ptr<UEngineMaterial> OverlayMaterial = UEngineMaterial::Create("OverlayMaterial");
		if (OverlayMaterial != nullptr)
		{
			OverlayMaterial->SetVertexShader("ImageShader.fx");
			OverlayMaterial->SetPixelShader("ImageShader.fx");
			OverlayMaterial->SetRasterizer("EngineBase");
			OverlayMaterial->SetBlend("Overlay");
		}

		std::shared_ptr<UEngineMaterial> FisheyeMaterial = UEngineMaterial::Create("FisheyeMaterial");
		if (FisheyeMaterial != nullptr)
		{
			FisheyeMaterial->SetVertexShader("Fisheye.fx");
			FisheyeMaterial->SetPixelShader("Fisheye.fx");
			FisheyeMaterial->SetRasterizer("EngineBase");
			FisheyeMaterial->SetBlend("EngineBase");
		}
	}


	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("ContentsResources");
		Dir.Move("Image");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : Files)
		{
			UEngineSprite::Load(File.GetFullPath());
		}

		std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			std::string Name = Directorys[i].GetFolderName();
			UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
		}

		// Title 이미지 커팅
		{
			UEngineSprite::CreateCutting("IntroEndings.png", 1, 9);
			UEngineSprite::CreateCutting("Static.png", 1, 8);
			UEngineSprite::CreateCutting("CameraEffects.png", 1, 16);
		}

		// Lobby 이미지 커팅
		{
			UEngineSprite::CreateCutting("TheOffice.png", 1, 11);
			UEngineSprite::CreateCutting("Fan.png", 3, 1);
		}

		// CCTV 이미지 커팅
		{
			UEngineSprite::CreateCutting("Camera.png", 4, 3);
		}

		// GameDay 이미지 커팅
		{
			UEngineSprite::CreateCutting("Day.png", 1, 6);
		}

		// StageUI 이미지 커팅
		{
			UEngineSprite::CreateCutting("PowerMeter.png", 1, 5);
		}

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

	GEngine->CreateLevel<ATitleGameMode>("TitleLevel");
	GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->ChangeLevel("PlayLevel");


}