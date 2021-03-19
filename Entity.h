#pragma once

#include <stdbool.h>
#include<SDL.h>
#include "lauxlib.h"
#include<lua.h>
#include"cute_c2.h"
typedef struct {
	int w;
	int h;
	int x;
	int y;
}rect;

//Currently Unused Values
//Will be used later. as in when player collision is working properly
int Entity_X_Velocity;
int Entity_Y_Velocity;
float Entity_Position_X;
float Entity_Position_Y;
const char* name;
rect Entity_Rectangle;
typedef void (Draw_func)();
typedef void (Redraw_func)();
typedef void (OnError_func)();
typedef void (OnCullsion_func)(rect*);
//todo:Document all code
/*All EntityTypes aren't implemented yet.Some wont be implemented at all.*/
enum EntityType {
	RENDERABLE,
	PLAYER,
	SOUND,
	CAMERA,
	GUI,
	MAINMENU,

};
typedef struct Size{
	float width;
	float height;
	bool Shouldscale;
	float scalewidth;
    float scaleheight;
}Size;
typedef struct {
	const char* name;
	rect Entity_Sprite;
	Size Entity_Size;
    float posX;
	float posY;
	int Enitiy_Speed_Multiplier;
	int Entity_X_Speed;
	int Entity_Y_Speed;
	int Entity_ID;
	char* Entity_CustomData;
	c2AABB Entity_BB;
}EntityData;

//TODO Prefix Function names with Entity_FUNCNAME
int CreateEntityDataLua(lua_State *L);
int ScaleEntityLua(lua_State *L);
int SetDrawCallbackLua(lua_State *L);
int SetXpositionLua(lua_State *L);
int SetYpositionLua(lua_State *L);


int LoadEntityLibrary(lua_State *L);
void Draw(Draw_func* draw);
void Redraw(Redraw_func* redraw);
void OnError(OnError_func* onerror);
void OnCullsion(OnCullsion_func* oncullsion);
void SetSize(int w, int h,rect rectangle);
//void SetSize(int w, int h);
void SetWidth(int w);
void SetHeight(int h);
int* GetSize();
void CollsionTest(EntityData ent_data, EntityData ent_other_data);
/*For Server*/

void SendEntity (EntityData* entity); //SendEntity really means SendEntityData
void SendCullsionData();
void SDL2_CreateEntityRect();
void Jump(EntityData* entityData);

SDL_Rect* ConvertEntityRectToSDLRect(rect* entity_rect);
void ScaleEntity(int widthMulti,int heightMulti);
