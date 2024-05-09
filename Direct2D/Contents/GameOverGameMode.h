#pragma once

class GameOverGameMode
{
public:
	// constrcuter destructer
	GameOverGameMode();
	~GameOverGameMode();

	// delete Function
	GameOverGameMode(const GameOverGameMode& _Other) = delete;
	GameOverGameMode(GameOverGameMode&& _Other) noexcept = delete;
	GameOverGameMode& operator=(const GameOverGameMode& _Other) = delete;
	GameOverGameMode& operator=(GameOverGameMode&& _Other) noexcept = delete;

protected:

private:

};

