#pragma once
#include <string>
#include <memory>
#include <Novice.h>

class Game;
class GameLocation
{
private:
	std::string m_name;
	Game* m_game;
	bool m_isLevelCleared = false;
	int m_id;

	//vector<>
public:
	GameLocation(int id, Game* game);
	std::string GetName();
	void Initialize();
	void Update();
	void Draw();
	bool IsStageCleared();
	int GetId();
};

