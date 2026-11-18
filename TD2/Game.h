#pragma once
#pragma once
#include "GameLocation.h"

#include "Ui.h"
#include "Input.h"
#include "AudioPlayer.h"
#include "CutScenePlayer.h"
#include <vector>
#include "IGameState.h"
#include <utility>
#include "IGameState.h"
#include "MainGameState.h"
#include "UiGameState.h"
#include "MiniGameState.h"
#include "CutSceneGameState.h"
#include "Minigame.h"
#include "SealClassificationMiniGame.h"
class Game
{
private:
	//int m_bgGh;
	Minigame* currentMinigame_ = nullptr;
	GameLocation test;
	GameLocation stage1;
	GameLocation stage2;
	GameLocation stage3;
	GameLocation* m_currentLocation;
	Input m_input;
	std::unique_ptr<IGameState> currentState_;
	std::unique_ptr<IGameState> nextState_;
	/*	GameLocation m_bosFirstStage;
		GameLocation m_bossSecondStage;
		GameLocation m_bossFinalStage;*/
		//std::vector<GameLocation>  m_stages;
	Ui m_ui;
	AudioPlayer m_audioPlayer;
	int m_currentStageId;
	CutScenePlayer m_cutscenePlayer;
	float m_averageAccuracy=0.0f;

public:
	void IncreaseAccuracy(float value);
	Game(char(&keysArg)[256], char(&preKeysArg)[256]);
	AudioPlayer* GetAudioPlayer();
	GameLocation* GetCurrentLocation();
	//int GetBGGh();
	void ChangeState(std::unique_ptr<IGameState> newState);
	void HandleInput(const CommandInput& input);
	void Draw();
	void Update();
	void RunStage(int stage);
	Ui* GetUi();
	void Instantiate();
	void OnNextStage();
	CutScenePlayer* GetCutscenePlayer();
	void RunCutScene(CutScenes cutsceneId);
	void Foo();
	void EndMinigame();
};



