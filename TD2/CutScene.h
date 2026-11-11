#pragma once
#include "CutsceneFrame.h"
#include <unordered_map>
#include "GameTypes.h"
class CutScenePlayer;
class CutScene
{
private:
	CutScenes m_name;
	int m_currentFrame;
	CutScenePlayer* m_player;
	std::unordered_map<int, CutSceneFrame> m_frames;
	std::unordered_map<int, int> m_dialogues;
	CutSceneFrame m_currentCutSceneFrame = { -1,{0,0} };
public:
	CutScene(CutScenes name,CutScenePlayer* player,std::unordered_map<int, CutSceneFrame> frames, std::unordered_map<int, int> dialogue);
	CutScenes GetName();
	void NextFrame();
	void Draw();
	void Start();
};

