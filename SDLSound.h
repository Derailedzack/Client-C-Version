#pragma once
#include<SDL.h>
SDL_AudioSpec snd_var1, snd_var2,snd_wave;
SDL_AudioDeviceID snd_dev_id;
Uint32 length;
Uint8* buf;

void SDL_snd_create(int snd_freq);
void SDL_snd_open(const char* path);
void SDL_snd_play(const char* path);
