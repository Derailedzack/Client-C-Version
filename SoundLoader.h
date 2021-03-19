#pragma once

void LoadSoundInitFromDLL(const char* path);
void LoadSoundOpenFromDLL(const char* path,const char* mus_path);
void LoadSoundPlayFromDLL(const char* path);
void LoadSoundStopFromDLL(const char* path);
void LoadSoundCloseFromDLL(const char* path,const char* mus_path);
void LoadSoundChangeFromDLL(const char* path);