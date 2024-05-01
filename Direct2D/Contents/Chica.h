#pragma once
class Chica
{
public:
	// constrcuter destructer
	Chica();
	~Chica();

	// delete Function
	Chica(const Chica& _Other) = delete;
	Chica(Chica&& _Other) noexcept = delete;
	Chica& operator=(const Chica& _Other) = delete;
	Chica& operator=(Chica&& _Other) noexcept = delete;

protected:

private:

};

