#include "MainGameState.h"
#include "CommandInput.h"
#include "Game.h"
void MainGameState::HandleInput(Game& game, const CommandInput& input) 
{
	if (input.isSpace_)
	{
		game.Foo();
	}
}
void MainGameState::Enter(Game& game)
{
	game.Foo();
}
void MainGameState::Update(Game& game)
{
	game.Foo();
}
void MainGameState::Draw(Game& game)
{
	game.Foo();
}
void MainGameState::Exit(Game& game)
{
	game.Foo();
}
