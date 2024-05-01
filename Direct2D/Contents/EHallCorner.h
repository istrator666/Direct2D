#pragma once
class AEHallCorner
{
public:
	// constrcuter destructer
	AEHallCorner();
	~AEHallCorner();

	// delete Function
	AEHallCorner(const AEHallCorner& _Other) = delete;
	AEHallCorner(AEHallCorner&& _Other) noexcept = delete;
	AEHallCorner& operator=(const AEHallCorner& _Other) = delete;
	AEHallCorner& operator=(AEHallCorner&& _Other) noexcept = delete;

protected:

private:

};

