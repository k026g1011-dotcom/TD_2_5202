#pragma once
#include <vector>
class Game;
class Hud
{
public:
	Hud();
	Hud(Game* game);
	void RequireTutor();
	void Update();
	void Draw();
	int GetStarGH();
	void IsNextTaskMarkNeeded(bool value);
private:
	Game* m_game;
	int m_digitsGh;
	int m_nextGh;
	int m_guideGh;
	bool m_isNextTaskMarkNeeded;
	std::vector<int> m_digits;
	/*	int m_healthBarGH;
		int m_aimGuide;
		int m_horizontalGuide;
		int m_verticalGuide;
		int m_tripleGuide;
		int m_crossGuide;
		int m_mirrorGuide;
		int m_swapToWhiteGh;
		int m_swapToRedGh;
		int m_swapToGreenGh;
		int m_swapToBlueGh;
		int m_swapColorsGh;
		int m_starGh;
		int m_tokenGh;
		int m_currentColorGh;
		int m_spareColorGh;
		int m_colorsOutlineGh;
		int m_retryGH;
		int m_tutorGH;
		bool m_isTutorNeeded;*/
};
