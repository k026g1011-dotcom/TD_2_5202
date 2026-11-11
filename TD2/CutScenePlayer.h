#pragma once
#include "CutScene.h"
#include "Novice.h"
#include "GameTypes.h"
#include <unordered_map>
class Game;
class CutScenePlayer
{
private:
	std::unordered_map<CutScenes, CutScene> m_cutscenes
	{
		{CutScenes::Intro,CutScene
			(
				CutScenes::Intro,
				this,
				{
					{0,{Novice::LoadTexture("./resources/Images/CutScenes/Intro/1.png"),{0,0}}},
					{1,{Novice::LoadTexture("./resources/Images/CutScenes/Intro/2.png"),{0,0}}},
					{2,{Novice::LoadTexture("./resources/Images/CutScenes/Intro/3.png"),{0,0}}},
					{4,{Novice::LoadTexture("./resources/Images/CutScenes/Intro/4.png"),{0,0}}},
					{5,{Novice::LoadTexture("./resources/Images/CutScenes/Intro/5.png"),{0,0}}},
					{6,{Novice::LoadTexture("./resources/Images/CutScenes/Intro/6.png"),{0,0}}}
				},
				{
					{0,Novice::LoadTexture("./resources/Images/CutScenes/Intro/Dialogue/1_1.png")},
					{1,Novice::LoadTexture("./resources/Images/CutScenes/Intro/Dialogue/2_1.png")},
					{2,Novice::LoadTexture("./resources/Images/CutScenes/Intro/Dialogue/3_1.png")},
					{3,Novice::LoadTexture("./resources/Images/CutScenes/Intro/Dialogue/3_2.png")},
					{4,Novice::LoadTexture("./resources/Images/CutScenes/Intro/Dialogue/4_1.png")},
					{5,Novice::LoadTexture("./resources/Images/CutScenes/Intro/Dialogue/5_1.png")},
					{6,Novice::LoadTexture("./resources/Images/CutScenes/Intro/Dialogue/6_1.png")}
				}
				)
		},
		{CutScenes::SecondDayIntro,CutScene
			(
				CutScenes::SecondDayIntro,
				this,
				{
					{0,{Novice::LoadTexture("./resources/Images/CutScenes/SecondDayIntro/1.png"),{0,0}}},
					{1,{Novice::LoadTexture("./resources/Images/CutScenes/SecondDayIntro/2.png"),{0,0}}},
				},
				{
					{0,Novice::LoadTexture("./resources/Images/CutScenes/SecondDayIntro/Dialogue/1_1.png")},
					{1,Novice::LoadTexture("./resources/Images/CutScenes/SecondDayIntro/Dialogue/2_1.png")},
				}
				)
		},
		{CutScenes::ThirdDayIntro,CutScene
			(
				CutScenes::ThirdDayIntro,
				this,
				{
					{0,{Novice::LoadTexture("./resources/Images/CutScenes/ThirdDayIntro/1.png"),{0,0}}},
					{1,{Novice::LoadTexture("./resources/Images/CutScenes/ThirdDayIntro/2.png"),{0,0}}},
				},
				{
					{0,Novice::LoadTexture("./resources/Images/CutScenes/ThirdDayIntro/Dialogue/1_1.png")},
					{1,Novice::LoadTexture("./resources/Images/CutScenes/ThirdDayIntro/Dialogue/2_1.png")},

				}
				)
		},
				{CutScenes::GoodEnding,CutScene
			(
				CutScenes::GoodEnding,
				this,
				{
					{0,{Novice::LoadTexture("./resources/Images/CutScenes/GoodEnding/1.png"),{0,0}}},
					{1,{Novice::LoadTexture("./resources/Images/CutScenes/GoodEnding/2.png"),{0,0}}},
					{2,{Novice::LoadTexture("./resources/Images/CutScenes/GoodEnding/3.png"),{0,0}}},
					{3,{Novice::LoadTexture("./resources/Images/CutScenes/GoodEnding/4.png"),{0,0}}},
					{4,{Novice::LoadTexture("./resources/Images/CutScenes/GoodEnding/5.png"),{0,0}} }
				},
				{
					{0,Novice::LoadTexture("./resources/Images/CutScenes/GoodEnding/Dialogue/1_1.png")},
					{1,Novice::LoadTexture("./resources/Images/CutScenes/GoodEnding/Dialogue/2_1.png")},
					{2,Novice::LoadTexture("./resources/Images/CutScenes/GoodEnding/Dialogue/3_1.png")},
					{3,Novice::LoadTexture("./resources/Images/CutScenes/GoodEnding/Dialogue/4_1.png")},
					{4,Novice::LoadTexture("./resources/Images/CutScenes/GoodEnding/Dialogue/5_1.png") }
				}
				)
		},
				{CutScenes::BadEnding,CutScene
			(
				CutScenes::BadEnding,
				this,
				{
					{0,{Novice::LoadTexture("./resources/Images/CutScenes/BadEnding/1.png"),{0,0}}},
					{1,{Novice::LoadTexture("./resources/Images/CutScenes/BadEnding/2.png"),{0,0}}},
					{2,{Novice::LoadTexture("./resources/Images/CutScenes/BadEnding/3.png"),{0,0}}},
					{3,{Novice::LoadTexture("./resources/Images/CutScenes/BadEnding/4.png"),{0,0}}},
					{4,{Novice::LoadTexture("./resources/Images/CutScenes/BadEnding/5.png"),{0,0}} }
				},
				{
					{0,Novice::LoadTexture("./resources/Images/CutScenes/BadEnding/Dialogue/1_1.png")},
					{1,Novice::LoadTexture("./resources/Images/CutScenes/BadEnding/Dialogue/2_1.png")},
					{2,Novice::LoadTexture("./resources/Images/CutScenes/BadEnding/Dialogue/3_1.png")},
					{3,Novice::LoadTexture("./resources/Images/CutScenes/BadEnding/Dialogue/4_1.png")},
					{4,Novice::LoadTexture("./resources/Images/CutScenes/BadEnding/Dialogue/5_1.png") }
				}
				)
		}
	};
	CutScene* m_currentCutScene = nullptr;
	Game* m_game=nullptr;
public:
	CutScenePlayer(Game* game);
	void PlayScene(CutScenes sceneId);
	void Draw();
	void Update();
	void StopScene();
	CutScene* GetCutScene();
};

