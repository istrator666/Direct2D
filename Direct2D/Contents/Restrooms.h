#pragma once
class ARestrooms
{
public:
	// constrcuter destructer
	ARestrooms();
	~ARestrooms();

	// delete Function
	ARestrooms(const ARestrooms& _Other) = delete;
	ARestrooms(ARestrooms&& _Other) noexcept = delete;
	ARestrooms& operator=(const ARestrooms& _Other) = delete;
	ARestrooms& operator=(ARestrooms&& _Other) noexcept = delete;

protected:

private:

};

