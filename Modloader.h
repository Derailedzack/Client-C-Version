#pragma once
#include<Windows.h>
#include "Client.h"

//Todo:Implement the Modloader
//Note: CreateSound is currently useless as there is no sound implemented
typedef void (Mod_INIT_Function)();
typedef void (Mod_OnDraw)();
typedef void (Mod_CreateScript)();
typedef void (Mod_CreateEntity)();
typedef void (Mod_CreateSound)();
typedef struct ModInfo{
	const char* name;
	const char* author;
	Version client_version;
	const char* mod_init_func;
    const char* mod_ondraw_func;

}ModInfo;

void LoadMod(const char* path); //Load DLL/script
void Test();
//Utility Functions
void CreateEntity(const char* path);
void CreateSound(const char* path);
void CreateScript(const char* path);
