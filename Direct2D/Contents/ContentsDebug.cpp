#include "PreCompile.h"
#include "ContentsDebug.h"

#include <EngineCore/EngineCore.h>

#include "Core.h"

int UContentsDebug::StageNumber = 0;

UContentsDebug::UContentsDebug()
{
}

UContentsDebug::~UContentsDebug()
{
}

void UContentsDebug::Init()
{
}

void UContentsDebug::OnGui(ULevel* Level, float _Delta)
{
	if (true == ImGui::Button("TitleLevel"))
	{
		if (0 == StageNumber || 1 == StageNumber)
		{
			return;
		}
		StageNumber = 0;
		GEngine->ChangeLevel("TitleLevel");
	}

	if (true == ImGui::Button("PlayLevel"))
	{
		if (1 == StageNumber || 2 == StageNumber)
		{
			return;
		}
		StageNumber = 1;
		GEngine->ChangeLevel("PlayLevel");
	}

	if (true == ImGui::Button("GameOverLevel") && 1 == StageNumber)
	{
		if (0 == StageNumber || 2 == StageNumber)
		{
			return;
		}
		StageNumber = 2;
		GEngine->ChangeLevel("GameOverLevel");
	}

	if (true == ImGui::Button("Battery") && 1 == StageNumber)
	{
		if (0 == StageNumber || 2 == StageNumber)
		{
			return;
		}

		
	}
}
