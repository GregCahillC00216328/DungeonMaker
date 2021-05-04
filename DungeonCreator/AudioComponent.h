#ifndef AUDIOCOMPONENT
#define AUDIOCOMPONENT
#include <SDL_mixer.h>
#include <SDL.h>
#include <iostream>
#include <string>
#include "Component.h"
class AudioComponent : public Component
{
public:
	AudioComponent();
	~AudioComponent();
	void LoadMusicFile(const char* t_string);
	void LoadMusicFileBG(const char* t_string);
	void loadAudioInputUI(const char* t_string);
	void playAudioBG();
	void playAudioInputUI();
	void closeAudio();
	void init() override;
	void update() override;
	void render() override;
private:
	Mix_Chunk* m_chunk;
	Mix_Music* m_musicBG;
	Mix_Chunk* m_inputUI;
	bool doOnceBG = false;
};
#endif // !AUDIOCOMPONENT
