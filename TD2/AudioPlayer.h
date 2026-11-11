#pragma once
#include "GameTypes.h"
#include <vector>
class Game;
class AudioPlayer
{
private:
	int m_musicSH = 0;
	int m_buttonSelected = 0;
	int m_buttonPressed = 0;
	int m_startButtonPressed = 0;
	int m_FloatingCityBgmHS = 0;
	int m_DECADENSBgmHS = 0;
	int m_CosmicScapeBgmHS = 0;
	int m_currentBGMSH = 0;
	int m_aim = 0;
	int m_reflect = 0;
	int m_shootBEam = 0;
	int m_explosion = 0;
	int m_shoot = 0;
	int m_clearedSH = 0;
	//int m_explosionSH;
	std::vector<int>m_explosionSH;
	Game* m_game = nullptr;
public:
	AudioPlayer(Game* game);
	void Play(Music sound);
	void PlayBGM();
	void StopBGM();
	void SetBGM(Music sound);
	void RemoveExplosionSH();
};

