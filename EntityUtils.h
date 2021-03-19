#pragma once
#include <stdio.h>
#include"clist.h"
//Note:There isn't a requirement for Regstering an entity in fact there isn't even anything that uses this
typedef enum Entity_Type {
	CAMERA,
    	PLAYER,
	GUI,
	SOUND,
	MUSIC,
	CUSTOM_ENTITY
}Entity_Type;
typedef enum Entity_Flags {
	INVISIBLE,
	INVINCIBLE,
	START_DEAD,
	START_ALIVE,
	CLIENT_ONLY,
	SERVER_ONLY,
	CUSTOM_FLAG
}Entity_Flags;
typedef struct Entity_Data {
	int id;
	float Entity_X;
	float Entity_Y;
	char* custom_data;
	int Entity_W;
	int Entity_H;
	const char* name;
}Entity_Data;
    CList* entity_list;
typedef void (Register_func)();


void Entity_Register(Register_func* register_func);
void Entity_RegisterAll();
const char* Entity_GetStrFlag(Entity_Flags entity_flag); //GetStrFlag means to get the string repsentation of the various entity flags
void Entity_SetCustomFlag(Entity_Flags entity_flags,char* Custom_entity_data,Entity_Data* EntityData);
void Entity_SetCustomEntityType(Entity_Type entity_type);
void Entity_InitList(Entity_Data ent_data);
void Entity_AddToList(Entity_Data* ent_data);
