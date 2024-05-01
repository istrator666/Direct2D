#pragma once
class AWestHall
{
public:
	// constrcuter destructer
	AWestHall();
	~AWestHall();

	// delete Function
	AWestHall(const AWestHall& _Other) = delete;
	AWestHall(AWestHall&& _Other) noexcept = delete;
	AWestHall& operator=(const AWestHall& _Other) = delete;
	AWestHall& operator=(AWestHall&& _Other) noexcept = delete;

protected:

private:

};

