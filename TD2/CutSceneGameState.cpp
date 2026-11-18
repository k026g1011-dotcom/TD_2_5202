#include "CutSceneGameState.h"
#include "CommandInput.h"
#include "Game.h"
void CutSceneGameState::HandleInput(Game& game, const CommandInput& input)
{
	if (input.isSpace_)
	{
		game.GetCutscenePlayer()->GetCutScene()->NextFrame();
	}
}
void CutSceneGameState::Enter(Game& game)
{
	game.Foo();
}
void CutSceneGameState::Update(Game& game)
{
	game.Foo();
}
void CutSceneGameState::Draw(Game& game)
{
	game.GetCutscenePlayer()->Draw();
}
void CutSceneGameState::Exit(Game& game)
{
	game.Foo();
}