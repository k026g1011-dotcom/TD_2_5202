#pragma once
#include "GameMenu.h"
#include "Hud.h"
#include "TitleMenu.h"
#include "ClearMenu.h"
#include "LostMenu.h"
#include "CreditsMenu.h"
#include "Components.h"
class Game;
class Ui
{
public:
	Ui();
	Ui(Game* game);
	void Update();
	void Draw();
	void ShowTitleMenu();
	void ShowCreditsMenu();
	void CloseCurrentMenu();
	void ShowClearMenu(float accuracy);
	Game* GetGame();
	GameMenu* GetCurrentMenu();
	void RequireTutor();
	Hud* GetHud();
	void ShowLostMenu();
	Components* GetComponents();
private:
	GameMenu* m_currentMenu = nullptr;
	Game* m_game = nullptr;
	TitleMenu m_titleMenu;
	ClearMenu m_clearMenu;
	LostMenu m_lostMenu;
	CreditsMenu m_creditsMenu;
	Components m_components;
	Hud m_hud;
};

