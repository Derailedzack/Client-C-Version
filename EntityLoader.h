#pragma once

#include "Entity.h"
#include <stdio.h>
#ifdef _WIN32
#include<Windows.h>
#endif
//typedef void (OnError_func)();
//typedef void (OnCullsion_func)(rect*);
void LoadEntityDrawFromDLL(const char* path);
void LoadEntityRedrawFromDLL(const char* path);
void LoadEntityCullsionCheckFromDLL(const char* path, rect* entity_rect);
