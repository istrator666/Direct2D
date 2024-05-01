#pragma once
class Freddy
{
public:
	// constrcuter destructer
	Freddy();
	~Freddy();

	// delete Function
	Freddy(const Freddy& _Other) = delete;
	Freddy(Freddy&& _Other) noexcept = delete;
	Freddy& operator=(const Freddy& _Other) = delete;
	Freddy& operator=(Freddy&& _Other) noexcept = delete;

protected:

private:

};

