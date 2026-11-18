#include "Game.h"
#include "MapConfigs.h"
#include<Novice.h>
#include "Ui.h"
#include <utility>
#include "IGameState.h"
#include "SealClassificationMiniGame.h"

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
void Game::Foo()
{

}
void Game::Update()
{
	if (nextState_)
	{
		if (currentState_)
		{
			currentState_->Exit(*this);

		}
		currentState_ = std::move(nextState_);
		currentState_->Enter(*this);
	}
	m_input.Update();
	currentState_->HandleInput(*this, m_input.GetInput());
	currentState_->Update(*this);



	/*m_ui.Update();
	if (m_currentLocation && !m_ui.GetCurrentMenu()&&!m_cutscenePlayer.GetCutScene())
	{
		m_currentLocation->Update();
	}*/


	//m_player.Update();
}

void Game::ChangeState(std::unique_ptr<IGameState> newState)
{
	nextState_=std::move(newState);
}

void Game::HandleInput (const CommandInput& input)
{
	currentState_->HandleInput(*this, input);
}

void Game::EndMinigame()
{
	currentMinigame_ = nullptr;
}

void Game::Draw()
{
	currentState_->Draw(*this);
/*	if (m_currentLocation != nullptr)
	{
		m_currentLocation->Draw();
	}
	
	m_ui.Draw();*/
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
void Game::RunCutScene(CutScenes cutsceneId)
{
	ChangeState(std::make_unique<CutSceneGameState>());
	m_cutscenePlayer.PlayScene(cutsceneId);
}
void Game::RunStage(int stage)
{

	m_currentStageId = stage;

	switch (m_currentStageId)
	{
	case 1:
		//currentMinigame_ = std::make_unique<SealClassificationMiniGame>();
		ChangeState(std::make_unique<MiniGameState>());
		break;
	case 2:
		ChangeState(std::make_unique<MiniGameState>());
		break;
	case 3:
		ChangeState(std::make_unique<MainGameState>());
		break;
	default:
		m_currentLocation = &test;
		break;
	}

}

