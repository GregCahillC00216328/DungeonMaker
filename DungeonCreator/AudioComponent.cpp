#include "AudioComponent.h"



AudioComponent::AudioComponent()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	/// <summary>
	/// for thia function 41000 is the recommended frequency in Hertz
	/// 2 is the number of channels used for the audio
	/// 4096 is the number of chunks for this Audio
	/// </summary>
	Mix_OpenAudio(41000, MIX_DEFAULT_FORMAT, 2, 4096);
	if (Mix_OpenAudio(41000, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
	{
		std::cout << "Error initialising SDL" << std::endl;
	}
}

AudioComponent::~AudioComponent()
{
	Mix_Quit();
}



void AudioComponent::LoadMusicFile(const char* t_string)
{


	m_chunk = Mix_LoadWAV(t_string);



	if (m_chunk == nullptr)
	{
		std::cout << "error loading file in audio:" << t_string << std::endl;
	}

}

void AudioComponent::LoadMusicFileBG(const char* t_string)
{

	m_musicBG = Mix_LoadMUS(t_string);

	if (m_musicBG == nullptr)
	{
		std::cout << "error loading file in audio:" << t_string << std::endl;
	}

}



void AudioComponent::loadAudioInputUI(const char* t_string)
{
	m_inputUI = Mix_LoadWAV(t_string);
	if (m_inputUI == nullptr)
	{
		std::cout << "error loading file in audio:" << t_string << std::endl;
	}
}

void AudioComponent::playAudioBG()
{
	std::cout << "playing BG audio" << std::endl;
	Mix_VolumeMusic(5);
	Mix_PlayMusic(m_musicBG, -1);

}



void AudioComponent::playAudioInputUI()
{
	Mix_PlayChannel(-1, m_inputUI, 0);
}

void AudioComponent::closeAudio()
{
	Mix_FreeChunk(m_chunk);
	Mix_FreeMusic(m_musicBG);
	Mix_CloseAudio();
	Mix_Quit();
}


void AudioComponent::init()
{

}

void AudioComponent::update()
{
}

void AudioComponent::render()
{
}
