#pragma once
class AWHallCorner
{
public:
	// constrcuter destructer
	AWHallCorner();
	~AWHallCorner();

	// delete Function
	AWHallCorner(const AWHallCorner& _Other) = delete;
	AWHallCorner(AWHallCorner&& _Other) noexcept = delete;
	AWHallCorner& operator=(const AWHallCorner& _Other) = delete;
	AWHallCorner& operator=(AWHallCorner&& _Other) noexcept = delete;

protected:

private:

};

