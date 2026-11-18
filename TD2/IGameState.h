#pragma once
#include "CommandInput.h"

class Game;
class IGameState
{
public:
	virtual ~IGameState() = default;
	virtual void HandleInput(Game& game, const CommandInput& input) = 0;
	virtual void Enter(Game& game) = 0;
	virtual void Update(Game& game) = 0;
	virtual void Draw(Game& game) = 0;
	virtual void Exit(Game& game) = 0;
};

