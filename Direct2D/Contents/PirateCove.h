#pragma once
class APirateCove
{
public:
	// constrcuter destructer
	APirateCove();
	~APirateCove();

	// delete Function
	APirateCove(const APirateCove& _Other) = delete;
	APirateCove(APirateCove&& _Other) noexcept = delete;
	APirateCove& operator=(const APirateCove& _Other) = delete;
	APirateCove& operator=(APirateCove&& _Other) noexcept = delete;

protected:

private:

};

