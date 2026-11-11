#pragma once
#pragma once
#include "GameLocation.h"

#include "Ui.h"
#include "Input.h"
#include "AudioPlayer.h"
#include "CutScenePlayer.h"
#include <vector>
class Game
{
private:
	//int m_bgGh;
	GameLocation test;
	GameLocation stage1;
	GameLocation stage2;
	GameLocation stage3;
	GameLocation* m_currentLocation;
	Input m_input;
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
	void Draw();
	void Update();
	void RunStage(int stage);
	Ui* GetUi();
	void Instantiate();
	void OnNextStage();
	CutScenePlayer* GetCutscenePlayer();
};



