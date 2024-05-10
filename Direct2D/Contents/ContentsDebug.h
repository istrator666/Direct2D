#pragma once
#include <EngineCore/EngineDebugMsgWindow.h>

class UContentsDebug : public UEngineDebugMsgWindow
{
	GENERATED_BODY(UEngineDebugMsgWindow)

public:
	// constrcuter destructer
	UContentsDebug();
	~UContentsDebug();

	// delete Function
	UContentsDebug(const UContentsDebug& _Other) = delete;
	UContentsDebug(UContentsDebug&& _Other) noexcept = delete;
	UContentsDebug& operator=(const UContentsDebug& _Other) = delete;
	UContentsDebug& operator=(UContentsDebug&& _Other) noexcept = delete;	

	static int StageNumber;

protected:
	void Init() override;
	void OnGui(ULevel* Level, float _Delta) override;

private:
	
};

