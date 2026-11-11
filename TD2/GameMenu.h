#pragma once
#include "ClickableComponent.h"
#include "Vector2.h"
class Game;
class GameMenu
{
public:
	GameMenu();
	GameMenu(Game* game);
	virtual ~GameMenu() = default;
	virtual void Update();
	virtual void Draw();
	virtual void RegisterComponents();
	void RegisterClickableComponent(ClickableComponent* component);
	virtual void ClickReceived();
	void SetBackGroundGh(int gh);
	virtual void CloseMenu();
	virtual void ToUpNeighbor();
	virtual void ToDownNeighbor();
	virtual void ToLeftNeighbor();
	virtual void ToRightNeighbor();
	ClickableComponent* GetSelectedButton();
	void SetSelectedButton(ClickableComponent* button);
	Game* GetGame();
	virtual void ResetSelectedButton();

private:
	int m_backGroundGh;
	Game* m_game = nullptr;
	std::vector<ClickableComponent*> m_clickableComponents;
	ClickableComponent* m_selectedButton = nullptr;
};

