#include "PreCompile.h"
#include "Core.h"
#include "PlayGameMode.h"
#include "TitleGameMode.h"
#include <EngineCore/EngineSprite.h>

UCore::UCore()
{
}

UCore::~UCore()
{
}

void UCore::Initialize()
{

	std::shared_ptr<UEngineMaterial> OverlayMaterial = UEngineMaterial::Create("OverlayMaterial");
	if (OverlayMaterial != nullptr)
	{
		OverlayMaterial->SetVertexShader("ImageShader.fx");
		OverlayMaterial->SetPixelShader("ImageShader.fx");
		OverlayMaterial->SetRasterizer("EngineBase");
		OverlayMaterial->SetBlend("Overlay");
	}

	{
		// ������ ���
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("ContentsResources");
		Dir.Move("Image");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : Files)
		{
			// CuttingTest.png texture�ε� ������ �ε尡 �ư�
			// ��������Ʈ�ε� 1��¥���� �ε尡 �� ��Ȳ�̾�.
			UEngineSprite::Load(File.GetFullPath());
		}

		// �ε������� �̷��� �Ѵٰ� Ĩ�ô�.
		std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			std::string Name = Directorys[i].GetFolderName();
			UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
		}

		// Ư�� ��������Ʈ�� 
		// Ư�� �ؽ�ó�� ã�Ƽ�
		// ���� ��������Ʈ�� �������� �ʴ´ٸ�
		// �̰� ����ϴ� ���� ������ �ڸ���.
		// �̹� �� �̸��� ���� ��������Ʈ�� �����Ѵ�.
		// �׷��� ������ ��������Ʈ �����ʹ� ����������
		// �ڸ� ��������Ʈ ������ �����Ѵ�.
		{
			UEngineSprite::CreateCutting("IntroEndings.png", 1, 9);
			UEngineSprite::CreateCutting("Static.png", 1, 8);
			UEngineSprite::CreateCutting("CameraEffects.png", 1, 16);
		}

		{
			UEngineSprite::CreateCutting("TheOffice.png", 1, 11);
			UEngineSprite::CreateCutting("Fan.png", 3, 1);
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
	GEngine->ChangeLevel("TitleLevel");


}