#pragma once
#include "GameMenu.h"
class CreditsMenu :
    public GameMenu
{
public:
    CreditsMenu();
    CreditsMenu(Game* game);
    ~CreditsMenu() override = default;
    void ClickReceived() override;
    void Update() override;
    void Draw() override;
    void HoveredByMouse(Vector2Int mousePos);
    void RegisterComponents() override;
private:
    ClickableComponent m_nextButton;
};

