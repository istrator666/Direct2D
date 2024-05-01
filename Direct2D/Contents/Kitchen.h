#pragma once
class AKitchen
{
public:
	// constrcuter destructer
	AKitchen();
	~AKitchen();

	// delete Function
	AKitchen(const AKitchen& _Other) = delete;
	AKitchen(AKitchen&& _Other) noexcept = delete;
	AKitchen& operator=(const AKitchen& _Other) = delete;
	AKitchen& operator=(AKitchen&& _Other) noexcept = delete;

protected:

private:

};

