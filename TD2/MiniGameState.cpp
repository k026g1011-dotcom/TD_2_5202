#include "MiniGameState.h"
#include "CommandInput.h"
#include "Game.h"
void MiniGameState::HandleInput(Game& game, const CommandInput& input)
{
	if (input.isSpace_)
	{
		game.Foo();
	}
}
void MiniGameState::Enter(Game& game)
{
	game.Foo();
}
void MiniGameState::Update(Game& game)
{
	game.Foo();
}
void MiniGameState::Draw(Game& game)
{
	game.Foo();
}
void MiniGameState::Exit(Game& game)
{
	game.Foo();
}