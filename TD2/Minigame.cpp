#include "Minigame.h"
#include <Novice.h>
void Minigame::Draw()
{
	Novice::DrawSprite(0, 0, bgGh_, 0.0f, 0.0f, 0.0f, WHITE);
}
void Minigame::SetBgGh(int bgGh)
{
	bgGh_ = bgGh;
}
void Minigame::Start(CommandInput* input)
{
	commands_ = input;
}
CommandInput* Minigame::GetCommand()
{
	return commands_;
}