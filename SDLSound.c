#include "SDLSound.h"

void SDL_snd_create(int snd_freq)
{
	SDL_memset(&snd_var1, 0, sizeof(snd_var1));
	snd_var1.freq = snd_freq;
	snd_var1.format = AUDIO_F32;
	snd_var1.channels = 2;
	snd_var1.samples = 4096;
	snd_dev_id = SDL_OpenAudioDevice(NULL, 0, &snd_var1, &snd_var2, SDL_AUDIO_ALLOW_FORMAT_CHANGE);
}



void SDL_snd_open(const char* path)
{
	if (SDL_LoadWAV(path, &snd_var1, &buf, &length) == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Sound Error", "Failed to load wave file!",NULL);
	}
}

void SDL_snd_play(const char* path)
{
	//SDL_PlayAudio();

	SDL_PauseAudioDevice(snd_dev_id, 0);
}
