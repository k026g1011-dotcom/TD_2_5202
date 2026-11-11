#include "CutScene.h"
#include<Novice.h>
#include <unordered_map>
#include "MapConfigs.h"
#include "CutScenePlayer.h"
#include "GameTypes.h"
CutScene::CutScene(CutScenes name,CutScenePlayer* player,std::unordered_map<int, CutSceneFrame> frames, std::unordered_map<int, int> dialogue):m_frames(frames),m_dialogues(dialogue)
{
	m_name = name;
	m_player = player;
	m_currentFrame = 0;
}
void CutScene::Start()
{
	m_currentFrame = 0;
	m_currentCutSceneFrame = m_frames.at(m_currentFrame);
}
CutScenes CutScene::GetName()
{
	return m_name;
}
void CutScene::NextFrame()
{
	
	if (m_currentFrame == m_dialogues.size()-1)
	{
		m_player->StopScene();
	}
	m_currentFrame++;
	if(m_frames.contains(m_currentFrame))
	{
		m_currentCutSceneFrame = m_frames.at(m_currentFrame);
	}
}
void CutScene::Draw()
{
	if (m_currentCutSceneFrame.frameGh != -1)
	{
		Novice::DrawSprite(
			m_currentCutSceneFrame.pos.x,
			m_currentCutSceneFrame.pos.y,
			m_currentCutSceneFrame.frameGh,
			1.0f,
			1.0f,
			0.0f,
			WHITE
		);
	}
	Novice::DrawSprite(
		MapConfig::kDialoguePosOnScreen.x,
		MapConfig::kDialoguePosOnScreen.y,
		m_dialogues.at(m_currentFrame),
		1.0f,
		1.0f,
		0.0f,
		WHITE
	);
}