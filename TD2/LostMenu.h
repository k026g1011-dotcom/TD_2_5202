#pragma once
#include "GameMenu.h"
class LostMenu :
    public GameMenu
{
public:
    LostMenu();
    LostMenu(Game* game);
    ~LostMenu() override = default;
    void ClickReceived() override;
    void Update() override;
    void Draw() override;
    void HoveredByMouse(Vector2Int mousePos);
    void RegisterComponents() override;
private:
    ClickableComponent m_nextButton;
};

