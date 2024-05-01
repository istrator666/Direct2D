#pragma once
class AEastHall
{
public:
	// constrcuter destructer
	AEastHall();
	~AEastHall();

	// delete Function
	AEastHall(const AEastHall& _Other) = delete;
	AEastHall(AEastHall&& _Other) noexcept = delete;
	AEastHall& operator=(const AEastHall& _Other) = delete;
	AEastHall& operator=(AEastHall&& _Other) noexcept = delete;

protected:

private:

};

