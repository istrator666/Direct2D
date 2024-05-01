#pragma once
class ASupplyCloset
{
public:
	// constrcuter destructer
	ASupplyCloset();
	~ASupplyCloset();

	// delete Function
	ASupplyCloset(const ASupplyCloset& _Other) = delete;
	ASupplyCloset(ASupplyCloset&& _Other) noexcept = delete;
	ASupplyCloset& operator=(const ASupplyCloset& _Other) = delete;
	ASupplyCloset& operator=(ASupplyCloset&& _Other) noexcept = delete;

protected:

private:

};

