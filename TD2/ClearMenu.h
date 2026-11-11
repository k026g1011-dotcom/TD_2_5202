#pragma once
#include "GameMenu.h"
class ClearMenu :
    public GameMenu
{
public:
    ClearMenu();
    ClearMenu(Game* game);
    ~ClearMenu() override = default;
    void Update() override;
    void Draw() override;
    void ClickReceived() override;
    void RegisterComponents()override;
private:
    ClickableComponent m_titleButton;
    int m_timer;
    int m_currentFrame;
    int m_noiseGh;
    int m_stageGh;
};