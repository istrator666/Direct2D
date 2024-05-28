#pragma once
#include <atomic>
#include "EngineProtocol.h"
#include "EngineNet.h"

// ���� :
class UNetObject
{
public:
	UNetObject();
	~UNetObject();

	// delete Function
	UNetObject(const UNetObject& _Other) = delete;
	UNetObject(UNetObject&& _Other) noexcept = delete;
	UNetObject& operator=(const UNetObject& _Other) = delete;
	UNetObject& operator=(UNetObject&& _Other) noexcept = delete;

	static int GetNewObjectToken()
	{
		return CurObjectToken++;
	}

	void SetObjectToken(int _ObjectToken)
	{
		ObjectToken = _ObjectToken;
	}


	void InitNet(std::shared_ptr<UEngineNet> _Net)
	{
		Net = _Net;
	}

	// net�� �޾ƾ� 
	bool IsNetInit()
	{
		return Net != nullptr;
	}

	void Send(std::shared_ptr<UEngineProtocol> _Protocol);

protected:
	static std::atomic<int> CurObjectToken;

private:
	std::shared_ptr<UEngineNet> Net = nullptr;
	// -1�̸� �ȹ������̴�.
	std::atomic<int> ObjectToken = -1;

};
