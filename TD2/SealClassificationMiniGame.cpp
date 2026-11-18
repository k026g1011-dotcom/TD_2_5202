#include "SealClassificationMiniGame.h"
SealClassificationMiniGame::SealClassificationMiniGame(Game* game):game_(game)
{
	SetBgGh(Novice::LoadTexture("./resources/Images/MiniGame1Bg.png"));
}
void SealClassificationMiniGame::Update()
{
	if (GetCommand()->isSpace_)
	{
		End();
	}
}
void SealClassificationMiniGame::Draw()
{
	Minigame::Draw();
}
void SealClassificationMiniGame::Start(CommandInput* input)
{
	Minigame::Start(input);
}
void SealClassificationMiniGame::End()
{
	game_->RunCutScene(CutScenes::SecondDayIntro);

}