#include "Game.h"
#include "MapConfigs.h"
#include<Novice.h>
#include "Ui.h"
Game::Game(char(&keysArg)[256], char(&preKeysArg)[256]) :
	m_audioPlayer(this),
	//m_bgGh(Novice::LoadTexture("./resources/images/grid/BG.png")),
	m_currentLocation(nullptr),
	m_input(this, keysArg, preKeysArg),
	m_ui(this),

	test(0,this),
	stage1(1,this),
	stage2(2,this),
	stage3(3,this),
	m_cutscenePlayer(this)
	/*	m_bosFirstStage(-1, this, MapConfig::BossFirstStage),
		m_bossSecondStage(-1, this, MapConfig::BossSecondStage),
		m_bossFinalStage(-1, this, MapConfig::BossFinalStage)*/
{

}
void Game::IncreaseAccuracy(float value)
{
	m_averageAccuracy += value;
}
CutScenePlayer* Game::GetCutscenePlayer()
{
	return &m_cutscenePlayer;
}
void Game::OnNextStage()
{
	m_currentStageId++;
	if (m_currentStageId < MapConfig::LevelsCount)
	{
		RunStage(m_currentStageId);
	}
	if (m_currentStageId == MapConfig::LevelsCount)
	{
		if (m_averageAccuracy / 3 > 0.8f)
		{
			m_cutscenePlayer.PlayScene(CutScenes::GoodEnding);
		}
		else
		{
			m_cutscenePlayer.PlayScene(CutScenes::BadEnding);

		}
	}
}
void Game::Instantiate()
{
	//m_player.Instantiate();
	//RunStage(0);
	Novice::SetMouseCursorVisibility(false);
	m_ui.ShowTitleMenu();
}
/*int Game::GetBGGh()
{
	return m_bgGh;
}*/
Ui* Game::GetUi()
{
	return &m_ui;
}
void Game::Update()
{
	m_input.Update();
	m_ui.Update();
	if (m_currentLocation && !m_ui.GetCurrentMenu()&&!m_cutscenePlayer.GetCutScene())
	{
		m_currentLocation->Update();
	}


	//m_player.Update();
}
void Game::Draw()
{

	if (m_currentLocation != nullptr)
	{
		m_currentLocation->Draw();
	}
	m_cutscenePlayer.Draw();
	m_ui.Draw();
	/*	Novice::ScreenPrintf(0, 0, "angle %f", atan2f(0, 1));
		Novice::ScreenPrintf(0, 15, "angle %f", atan2f(1, 0));
		Novice::ScreenPrintf(0, 30, "angle %f", atan2f(0, -1));
		Novice::ScreenPrintf(0,45,"angle %f",atan2f(-1,0));*/
		//Novice::ScreenPrintf(0, 60, "target x: %f, y: %f", m_player.GetTarget().x, m_player.GetTarget().y);
}


AudioPlayer* Game::GetAudioPlayer()
{
	return &m_audioPlayer;
}
GameLocation* Game::GetCurrentLocation()
{
	return m_currentLocation;
}
void Game::RunStage(int stage)
{

	m_currentStageId = stage;
/*	switch (m_currentStageId)
	{
	case 1:
		m_cutscenePlayer.PlayScene(CutScenes::Intro);
		m_currentLocation = &stage1;
		m_currentLocation->GetWork()->Initialize();
		m_currentLocation->GetWork()->SetAdditionalLength(1);
		m_currentLocation->GetWork()->SetTaskCount(MapConfig::kFirstStageTaskCount);
		break;
	case 2:
		m_cutscenePlayer.PlayScene(CutScenes::SecondDayIntro);
		m_currentLocation = &stage2;
		m_currentLocation->GetWork()->Initialize();
		m_currentLocation->GetWork()->SetAdditionalLength(2);
		m_currentLocation->GetWork()->SwitchTimer(true);
		m_currentLocation->GetWork()->SetTaskCount(MapConfig::kSecondStageTaskCount);
		break;
	case 3:
		m_cutscenePlayer.PlayScene(CutScenes::ThirdDayIntro);
		m_currentLocation = &stage3;
		m_currentLocation->GetWork()->Initialize();
		m_currentLocation->GetWork()->SetAdditionalLength(3);
		m_currentLocation->GetWork()->SwitchTimer(true);
		m_currentLocation->GetWork()->SwitchManual(false);
		m_currentLocation->GetWork()->SetTaskCount(MapConfig::kThirdStageTaskCount);
		break;
	default:
		//m_cutscenePlayer.PlayScene(CutScenes::Intro);
		m_currentLocation = &test;
		break;
	}*/

}

