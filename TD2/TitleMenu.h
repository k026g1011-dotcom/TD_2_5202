#pragma once
#include "GameMenu.h"
#include "ClickableComponent.h"
class Game;
class TitleMenu :
    public GameMenu
{
public:
    TitleMenu();
    TitleMenu(Game* game);
    ~TitleMenu() override = default;
    void ClickReceived() override;
    void Update() override;
    void Draw() override;
    void HoveredByMouse(Vector2Int mousePos);
    void RegisterComponents() override;
    void ResetSelectedButton() override;
    virtual void ToUpNeighbor() override;
    virtual void ToDownNeighbor() override;
    virtual void ToLeftNeighbor() override;
    virtual void ToRightNeighbor() override;
private:
    ClickableComponent m_startButton;
    ClickableComponent m_creditsButton;
    int m_titleGh;
};

