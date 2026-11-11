#include "Input.h"
#include "Game.h"
Input::Input()
{

}
Input::Input(Game* game, char(&keysArg)[256], char(&preKeysArg)[256])
{
	m_game = game;
	m_keys = keysArg;
	m_preKeys = preKeysArg;
}
void Input::Update()
{
	/*if (m_game != nullptr)
	{
		if (m_game->GetUi()->GetCurrentMenu() != nullptr)
		{
			if (m_keys[DIK_W] && !m_preKeys[DIK_W]|| m_keys[DIK_UP] && !m_preKeys[DIK_UP])
			{
				m_game->GetUi()->GetCurrentMenu()->ToUpNeighbor();
			}
			if (m_keys[DIK_A] && !m_preKeys[DIK_A] || m_keys[DIK_LEFT] && !m_preKeys[DIK_LEFT])
			{
				m_game->GetUi()->GetCurrentMenu()->ToLeftNeighbor();
			}
			if (m_keys[DIK_S] && !m_preKeys[DIK_S] || m_keys[DIK_DOWN] && !m_preKeys[DIK_DOWN])
			{
				m_game->GetUi()->GetCurrentMenu()->ToDownNeighbor();
			}
			if (m_keys[DIK_D] && !m_preKeys[DIK_D] || m_keys[DIK_RIGHT] && !m_preKeys[DIK_RIGHT])
			{
				m_game->GetUi()->GetCurrentMenu()->ToRightNeighbor();
			}
			if ((m_keys[DIK_SPACE] && !m_preKeys[DIK_SPACE]) )
			{
				m_game->GetUi()->GetCurrentMenu()->ClickReceived();
			}
		}
		
		else if (m_game->GetCurrentLocation())
		{
			if (m_game->GetCurrentLocation()->GetWork())
			{
				if (m_game->GetCutscenePlayer()->GetCutScene())
				{
					if (m_keys[DIK_SPACE] && !m_preKeys[DIK_SPACE])
					{
						m_game->GetCutscenePlayer()->GetCutScene()->NextFrame();
					}
				}
				else if (m_game->GetCurrentLocation()->GetWork()->IsResultShorter())
				{
					if (m_keys[DIK_R] && !m_preKeys[DIK_R])
					{
						m_game->GetCurrentLocation()->GetWork()->Restart();
					}
					if (m_keys[DIK_SPACE] && !m_preKeys[DIK_SPACE])
					{
						m_game->GetCurrentLocation()->GetWork()->SetPressed(true);
					}
					if (m_preKeys[DIK_SPACE] && !m_keys[DIK_SPACE])
					{
						if (m_game->GetCurrentLocation()->GetWork()->IsPressed())
						{
							m_game->GetCurrentLocation()->GetWork()->StopPressing();
						}

					}
				}
				else
				{
					if (m_keys[DIK_SPACE] && !m_preKeys[DIK_SPACE])
					{
						
						m_game->GetCurrentLocation()->GetWork()->NewTask(true);
					}
				}
			}
		}
		
	}*/
}