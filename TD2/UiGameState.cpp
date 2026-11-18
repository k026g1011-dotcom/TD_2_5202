#include "UiGameState.h"
#include "CommandInput.h"
#include "Game.h"
void UiGameState::HandleInput(Game& game, const CommandInput& input)
{
	if (game.GetUi()->GetCurrentMenu())
	{
		if (input.isW_)
		{
			game.GetUi()->GetCurrentMenu()->ToUpNeighbor();
		}
		if (input.isS_)
		{
			game.GetUi()->GetCurrentMenu()->ToDownNeighbor();
		}
		if (input.isSpace_)
		{
			game.GetUi()->GetCurrentMenu()->ClickReceived();
		}
	}
}
void UiGameState::Enter(Game& game)
{
	game.Foo();
}
void UiGameState::Update(Game& game)
{
	game.GetUi()->Update();
}
void UiGameState::Draw(Game& game)
{
	game.GetUi()->Draw();
}
void UiGameState::Exit(Game& game)
{
	game.Foo();
}
