#pragma once
typedef void (snd_init_func)();
typedef void (snd_open_func)(const char* path);
typedef void (snd_play_func)();
typedef void(snd_stop_func)();
typedef void (snd_close_func)(const char* path);
typedef void (snd_change_func)();
void Audio_Init(snd_init_func init_func);
void Audio_Open(snd_open_func open_func);
void Audio_Play(snd_play_func play_func);
void Audio_Stop(snd_stop_func stop_func);
void Audio_Close(snd_close_func close_func);
