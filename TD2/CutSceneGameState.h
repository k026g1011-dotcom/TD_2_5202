#pragma once
#include "IGameState.h"
#include "CommandInput.h"
class Game;
class CutSceneGameState :
    public IGameState
{
    void HandleInput(Game& game, const CommandInput& input) override;
    void Enter(Game& game) override;
    void Update(Game& game) override;
    void Draw(Game& game) override;
    void Exit(Game& game) override;
};

