#pragma once
class Foxy
{
public:
	// constrcuter destructer
	Foxy();
	~Foxy();

	// delete Function
	Foxy(const Foxy& _Other) = delete;
	Foxy(Foxy&& _Other) noexcept = delete;
	Foxy& operator=(const Foxy& _Other) = delete;
	Foxy& operator=(Foxy&& _Other) noexcept = delete;

protected:

private:

};

