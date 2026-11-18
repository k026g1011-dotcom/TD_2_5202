#pragma once
#include "Minigame.h"
#include "Game.h"
class SealClassificationMiniGame :
    public Minigame
{
private:
    Game* game_;
public:
    SealClassificationMiniGame(Game* game);
    void Update() override;
    void Draw() override;
    void Start(CommandInput* input) override;
    void End() override;
};

