
#include "GameLocation.h"
#include "Game.h"
#include <string>
#include "Utils.h"
#include <vector>

GameLocation::GameLocation(int id, Game* game) :m_game(game)
{
	m_id = id;
	m_isLevelCleared = false;
}

std::string GameLocation::GetName()
{
	return m_name;
}
void GameLocation::Initialize()
{
	
}
void GameLocation::Update()
{
	
}
bool GameLocation::IsStageCleared()
{
	return false;
}

int GameLocation::GetId()
{
	return m_id;
}
void GameLocation::Draw()
{
	Novice::DrawBox(0, 0, MapConfig::kWindowWidth, MapConfig::kWindowHeight, 0.0f, WHITE, kFillModeSolid);
}

