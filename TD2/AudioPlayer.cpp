#include "AudioPlayer.h"
#include <Novice.h>
AudioPlayer::AudioPlayer(Game* game)
{
	m_game = game;
	//m_blockSettedSH= Novice::LoadAudio("./resources/sounds/blockSetted.mp3");
	//m_starPickedUpSH= Novice::LoadAudio("./resources/sounds/blockSetted.mp3");
	//m_buttonPressed= Novice::LoadAudio("./resources/sounds/blockSetted.mp3");
/*	m_stepsSoundSH[0] = Novice::LoadAudio("./resources/sounds/footStep1.mp3");
	m_stepsSoundSH[1] = Novice::LoadAudio("./resources/sounds/footStep2.mp3");
	m_stepsSoundSH[2] = Novice::LoadAudio("./resources/sounds/footStep3.mp3");*/
	m_clearedSH = Novice::LoadAudio("./resources/sounds/cleared.wav");
	m_buttonSelected = Novice::LoadAudio("./resources/sounds/buttonSelected.mp3");
	m_buttonPressed = Novice::LoadAudio("./resources/sounds/buttonPressed.wav");
	m_startButtonPressed = Novice::LoadAudio("./resources/sounds/startButtonPressed.wav");
	m_FloatingCityBgmHS = Novice::LoadAudio("./resources/sounds/Floatng_City.mp3");
	m_DECADENSBgmHS = Novice::LoadAudio("./resources/sounds/DECADENCE.mp3");
	m_CosmicScapeBgmHS = Novice::LoadAudio("./resources/sounds/Cosmic_Scape.mp3");
	m_currentBGMSH = Novice::LoadAudio("./resources/sounds/startButtonPressed.wav");

}
void AudioPlayer::Play(Music sound)
{
	switch (sound)
	{
/*	case Music::Aim:
		Novice::PlayAudio(m_aim, false, 0.25f);
		break;
	case Music::Shoot:
		Novice::PlayAudio(m_shoot, false, 0.25f);
		break;
	case Music::ShootBEam:
		Novice::PlayAudio(m_shootBEam, false, 0.25f);
		break;
	case Music::Reflect:
		Novice::PlayAudio(m_reflect, false, 0.25f);
		break;
	case Music::Explosion:

		m_explosionSH.push_back(Novice::PlayAudio(m_explosion, false, 0.25f));
		for (int i = 0;i < m_explosionSH.size();i++)
		{
			Novice::SetAudioVolume(m_explosionSH[i], 0.25f / (m_explosionSH.size() == 0 ? 1 : m_explosionSH.size()));
		}
				for (auto& sound : m_explosionSH)
				{
					Novice::SetAudioVolume(sound, 0.25f / (m_explosionSH.size()==0?1: m_explosionSH.size()));
				}
		break;*/
	case Music::ButtonSelected:
		Novice::PlayAudio(m_buttonSelected, false, 0.25f);
		break;
	case Music::Button:
		Novice::PlayAudio(m_buttonPressed, false, 0.25f);
		break;
/*	case Music::StartButton:
		Novice::PlayAudio(m_startButtonPressed, false, 0.25f);
		break;
	case Music::Cleared:
		Novice::PlayAudio(m_clearedSH, false, 0.25f);
		break;*/
	}

}
void AudioPlayer::PlayBGM()
{
	if (!Novice::IsPlayingAudio(m_musicSH))
	{
		m_musicSH = Novice::PlayAudio(m_currentBGMSH, true, 0.25f);
	}

}
void AudioPlayer::StopBGM()
{
	Novice::StopAudio(m_musicSH);
}
void AudioPlayer::SetBGM(Music sound)
{
	switch (sound)
	{

	case Music::BGM:
		m_currentBGMSH = m_DECADENSBgmHS;
		break;
	default:
		StopBGM();
		break;
	}

}
void AudioPlayer::RemoveExplosionSH()
{
	m_explosionSH.erase(m_explosionSH.begin());
}