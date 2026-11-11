#include "Ui.h"
#include "Game.h"
#include "Hud.h"
#include "GameMenu.h"
Ui::Ui()
{

}
Ui::Ui(Game* game) :
	m_titleMenu(game),
	m_hud(game),
	m_clearMenu(game),
	m_lostMenu(game),
	
	m_creditsMenu(game)
{
	/*	m_titleMenu.RegisterComponents();
		m_levelSelectMenu.RegisterComponents();*/
	m_game = game;

}
Components* Ui::GetComponents()
{
	return &m_components;
}
Hud* Ui::GetHud()
{
	return &m_hud;
}
void Ui::ShowTitleMenu()
{
	m_currentMenu = &m_titleMenu;
	m_game->GetAudioPlayer()->StopBGM();
	m_game->GetAudioPlayer()->SetBGM(Music::BGM);
	m_game->GetAudioPlayer()->PlayBGM();
	m_currentMenu->RegisterComponents();
	m_currentMenu->ResetSelectedButton();
}
void Ui::RequireTutor()
{
	m_hud.RequireTutor();
}
void Ui::ShowLostMenu()
{
	m_currentMenu = &m_lostMenu;
	m_game->GetAudioPlayer()->StopBGM();
	m_currentMenu->RegisterComponents();
}

void Ui::ShowCreditsMenu()
{
	m_currentMenu = &m_creditsMenu;
	m_currentMenu->RegisterComponents();
	m_currentMenu->ResetSelectedButton();
}
void Ui::ShowClearMenu(float accuracy)
{
	Novice::ConsolePrintf("Showing levelClear menu \n");
	m_game->IncreaseAccuracy(accuracy);
	m_currentMenu = &m_clearMenu;
	m_currentMenu->RegisterComponents();
	//m_game->GetAudioPlayer()->StopBGM();
	//m_game->GetAudioPlayer()->SetBGM(Music::NoiseBGM);
	//m_game->GetAudioPlayer()->PlayBGM();
	//m_game->GetAudioPlayer()->Play(Music::Cleared);
}
void Ui::CloseCurrentMenu()
{
	//m_game->GetAudioPlayer()->StopBGM();
	m_currentMenu = nullptr;
}
Game* Ui::GetGame()
{
	return m_game;
}
GameMenu* Ui::GetCurrentMenu()
{
	return m_currentMenu;
}
void Ui::Update()
{
	m_hud.Update();
	if (m_currentMenu != nullptr)
	{
		m_currentMenu->Update();
	}
}
void Ui::Draw()
{

	if (m_currentMenu != nullptr)
	{
		m_currentMenu->Draw();
		//Novice::DrawSprite(static_cast<int>(mouseX), static_cast<int>(mouseY), m_cursorGH, 1.0f, 1.0f, 0, WHITE);
	}
	else
	{
		m_hud.Draw();
		
		//Novice::DrawSprite(static_cast<int>(mouseX - 16), static_cast<int>(mouseY - 16), m_cursorAimGH, 1.0f, 1.0f, 0, WHITE);
	}
}
/*	m_hud.Draw();
	Novice::ScreenPrintf(900, 0, "is current menu null: %s", m_currentMenu == nullptr ? "true" : "false");*/