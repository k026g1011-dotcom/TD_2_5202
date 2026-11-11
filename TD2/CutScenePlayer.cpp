#include "CutScenePlayer.h"
#include "Game.h"
CutScenePlayer::CutScenePlayer(Game* game):m_game(game)
{

}
void CutScenePlayer::PlayScene(CutScenes sceneId)
{
	if (m_cutscenes.contains(sceneId))
	{
		m_currentCutScene = &m_cutscenes.at(sceneId);
		m_currentCutScene->Start();
	}
}

void CutScenePlayer::Draw()
{
	if (m_currentCutScene)
	{
		m_currentCutScene->Draw();
	}
}

void CutScenePlayer::Update()
{

}

CutScene* CutScenePlayer::GetCutScene()
{
	return m_currentCutScene;
}

void CutScenePlayer::StopScene()
{
	
	if (m_currentCutScene->GetName() == CutScenes::BadEnding || m_currentCutScene->GetName() == CutScenes::GoodEnding)
	{
		m_game->GetUi()->ShowTitleMenu();
	}
	m_currentCutScene = nullptr;
}