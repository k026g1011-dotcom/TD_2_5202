#include "Hud.h"
#include "Ui.h"
#include "Game.h"
#include "MapConfigs.h"
#include <vector>
Hud::Hud()
{
	m_digitsGh= Novice::LoadTexture("./resources/images/Ui/Hud/DigitFont.png");
	m_nextGh = Novice::LoadTexture("./resources/images/Ui/Hud/Next.png");
	m_guideGh = Novice::LoadTexture("./resources/images/Ui/Hud/KeyGuide.png");
/*	m_healthBarGH = Novice::LoadTexture("./resources/images/Ui/Hud/HealthBar.png");
	m_aimGuide = Novice::LoadTexture("./resources/images/Ui/Hud/guideplayerattack.png");
	m_horizontalGuide = Novice::LoadTexture("./resources/images/Ui/Hud/guidebothlineobject.png");
	m_verticalGuide = Novice::LoadTexture("./resources/images/Ui/Hud/guidebiglineobject.png");
	m_tripleGuide = Novice::LoadTexture("./resources/images/Ui/Hud/guidethreelineobject.png");
	m_crossGuide = Novice::LoadTexture("./resources/images/Ui/Hud/guidecrossobject.png");
	m_mirrorGuide = Novice::LoadTexture("./resources/images/Ui/Hud/guideenemyshild.png");*/
	/*m_swapToWhiteGh= Novice::LoadTexture("./resources/images/Ui/Hud/ChangeToWhite.png");
	m_swapToRedGh = Novice::LoadTexture("./resources/images/Ui/Hud/ChangeToRed.png");
	m_swapToGreenGh = Novice::LoadTexture("./resources/images/Ui/Hud/ChangeToGreen.png");
	m_swapToBlueGh = Novice::LoadTexture("./resources/images/Ui/Hud/ChangeToBlue.png");
	m_swapColorsGh = Novice::LoadTexture("./resources/images/Ui/Hud/Swap.png");
	m_starGh = Novice::LoadTexture("./resources/images/Ui/Hud/Star.png");
	m_tokenGh = Novice::LoadTexture("./resources/images/Ui/Hud/Token.png");
	m_currentColorGh = Novice::LoadTexture("./resources/images/Ui/Hud/CurrentCollor.png");
	m_spareColorGh = Novice::LoadTexture("./resources/images/Ui/Hud/SpareCollor.png");
	m_colorsOutlineGh = Novice::LoadTexture("./resources/images/Ui/Hud/ColorsOutline.png");
	m_retryGH= Novice::LoadTexture("./resources/images/Ui/Hud/Retry.png");
	m_tutorGH = Novice::LoadTexture("./resources/images/Ui/Hud/Tutor.png");
	m_isTutorNeeded = false;*/
}
Hud::Hud(Game* game) :Hud()
{
	m_game = game;
}
void Hud::RequireTutor()
{

	//m_isTutorNeeded = value;
}
void Hud::IsNextTaskMarkNeeded(bool value)
{
	m_isNextTaskMarkNeeded = value;
}
void Hud::Update()
{

}
void Hud::Draw()
{
/*	if (!m_game->GetCutscenePlayer()->GetCutScene())
	{
		int accuracy = static_cast<int>((1.0f + m_game->GetCurrentLocation()->GetWork()->GetAccuracy()) * 10000.0f);
		if (m_game->GetCurrentLocation()->GetWork()->GetAccuracy() == 1.0f)
		{
			Novice::DrawQuad(
				MapConfig::kWindowWidth - 64 * 6,
				0,
				MapConfig::kWindowWidth - 64 * 5,
				0,
				MapConfig::kWindowWidth - 64 * 6,
				64,
				MapConfig::kWindowWidth - 64 * 5,
				64,
				0 + 64,
				0,
				64,
				64,
				m_digitsGh,
				WHITE
			);
		}
		m_digits.clear();

		m_digits.push_back(accuracy % 10);
		m_digits.push_back((accuracy % 100) / 10);
		m_digits.push_back(10);
		m_digits.push_back((accuracy % 1000) / 100);
		m_digits.push_back((accuracy % 10000) / 1000);

		for (int i = static_cast<int>(m_digits.size());i > 0;i--)
		{
			Novice::DrawQuad(
				MapConfig::kWindowWidth - 64 * i,
				0,
				MapConfig::kWindowWidth - 64 * (i - 1),
				0,
				MapConfig::kWindowWidth - 64 * i,
				64,
				MapConfig::kWindowWidth - 64 * (i - 1),
				64,
				0 + 64 * m_digits[i - 1],
				0,
				64,
				64,
				m_digitsGh,
				WHITE
			);
		}
		Novice::DrawSprite(64, MapConfig::kWindowHeight - 164, m_guideGh, 1.0f, 1.0f, 0.0f, WHITE);
		if (m_isNextTaskMarkNeeded)
		{
			Novice::DrawSprite(MapConfig::kTaskPosOnScreen.x+640-128-16, MapConfig::kTaskPosOnScreen.y + 200 - 64-16, m_nextGh, 1.0f, 1.0f, 0.0f, WHITE);
		}
	}
	else
	{
		Novice::DrawSprite(MapConfig::kWindowWidth- 128,MapConfig::kWindowHeight-64, m_nextGh, 1.0f, 1.0f, 0.0f, WHITE);
	}
	/*Novice::DrawSprite(0, 720 - 64, m_healthBarGH, 1.0f, 1.0f, 0.0f, WHITE);
	int coeff = m_game->GetPlayer()->GetMaxHealth() * m_game->GetPlayer()->GetHealth();
	float coeff = 120 / static_cast<float>(m_game->GetPlayer()->GetMaxHealth());
	float currentWidth = coeff * static_cast<float>(m_game->GetPlayer()->GetHealth());
	Novice::DrawBox(4, 692, static_cast<int>(currentWidth), 24, 0.0f, GREEN, kFillModeSolid);
	switch (m_game->GetCurrentLocation()->GetId())
	{
	case 0:
		Novice::DrawSprite(950, 250, m_aimGuide, 1.0f, 1.0f, 0.0f, WHITE);
		break;
	case 1:
		Novice::DrawSprite(950, 250, m_aimGuide, 1.0f, 1.0f, 0.0f, WHITE);
		break;
	case 2:
		Novice::DrawSprite(950, 250, m_horizontalGuide, 1.0f, 1.0f, 0.0f, WHITE);
		break;
	case 3:
		Novice::DrawSprite(950, 250, m_verticalGuide, 1.0f, 1.0f, 0.0f, WHITE);
		break;
	case 4:
		Novice::DrawSprite(950, 250, m_tripleGuide, 1.0f, 1.0f, 0.0f, WHITE);
		break;
	case 5:
		Novice::DrawSprite(950, 250, m_crossGuide, 1.0f, 1.0f, 0.0f, WHITE);
		break;
	case 6:
		Novice::DrawSprite(950, 250, m_mirrorGuide, 1.0f, 1.0f, 0.0f, WHITE);
		break;
	case 7:
		Novice::DrawSprite(950, 250, m_mirrorGuide, 1.0f, 1.0f, 0.0f, WHITE);
		break;
	}
	Novice::DrawSprite(0, 272, m_retryGH, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(0, 250, m_swapToWhiteGh, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(0, 400, m_swapToRedGh, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(0, 464, m_swapToGreenGh, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(0, 528, m_swapToBlueGh, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(0, 592, m_swapColorsGh, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(576, 592,m_colorsOutlineGh, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(576, 592, m_currentColorGh, 1.0f, 1.0f, 0.0f, m_game->GetCurrentLocation()->GetMainColor());
	Novice::DrawSprite(640, 592,m_spareColorGh, 1.0f, 1.0f, 0.0f, m_game->GetCurrentLocation()->GetSpareColor());
	if (m_isTutorNeeded)
	{
		Novice::DrawSprite(0, 0, m_tutorGH, 1.0f, 1.0f, 0.0f, WHITE);
	}*/
}