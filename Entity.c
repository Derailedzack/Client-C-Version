#include <lauxlib.h>
#include "Entity.h"
EntityData* Lua_Entity;
const luaL_Reg Entity_Reg[] = {
        {"Create_Entity",CreateEntityDataLua},
        {"Scale_Entity",ScaleEntityLua},
        {"SetDrawCallback",SetDrawCallbackLua},
        {"SetXposition",SetXpositionLua},
        {"SetYposition",SetYpositionLua},
        {NULL,NULL}
};
void Draw(Draw_func* draw)
{
	(draw)();
}

void Redraw(Redraw_func* redraw)
{
	(redraw)();
}

void OnError(OnError_func* onerror)
{
	(onerror)();
}

void OnCullsion(OnCullsion_func* oncullsion)
{
	(oncullsion)(&Entity_Rectangle);
}

void SetSize(int w, int h,rect rectangle)
{
	Entity_Rectangle = rectangle;
	Entity_Rectangle.w = w;
	Entity_Rectangle.h = h;
}



void SetWidth(int w)
{
	Entity_Rectangle.w = w;
}

void SetHeight(int h)
{
	Entity_Rectangle.h = h;
}

int* GetSize()
{
	int* Size = {0};
	if (Size[0] || Size[1] == 0){

	}else{
		Size[0] = Entity_Rectangle.w;
		Size[1] = Entity_Rectangle.h;
	}

	return (Size);
}

void CollsionTest(EntityData ent_data, EntityData ent_other_data)
{

}

void SendEntity(EntityData* entity)
{

}
void Jump(EntityData* entityData){
//From https://gamedev.net/forums/topic/663764-sdl20-character-jumping-38-gravity/5198436/
//Also the code that was here no longer exists
//as I removed it
}
SDL_Rect* ConvertEntityRectToSDLRect(rect* entity_rect){
    SDL_Rect* convert;
    convert->x = entity_rect->x;
    convert->y = entity_rect->y;
    convert->w = entity_rect->w;
    convert->h = entity_rect->h;
    return convert;
}
void SendCullsionData()
{

}
int ScaleEntityLua(lua_State *L){
  if(Lua_Entity == NULL){
        luaL_error(L,"Lua_Entity is NULL! Pointer:%p\nConsider calling Create_Entity\n",Lua_Entity);
        return -1;
    }
}
int SetDrawCallbackLua(lua_State *L){
  if(Lua_Entity == NULL){
        luaL_error(L,"Lua_Entity is NULL! Pointer:%p\nConsider calling Create_Entity\n",Lua_Entity);
        return -1;
    }
}
int SetXpositionLua(lua_State *L){
  if(Lua_Entity == NULL){
        luaL_error(L,"Lua_Entity is NULL! Pointer:%p\nConsider calling Create_Entity\n",Lua_Entity);
        return -1;
    }
}
int SetYpositionLua(lua_State *L){
    if(Lua_Entity == NULL){
        luaL_error(L,"Lua_Entity is NULL! Pointer:%p\nConsider calling Create_Entity\n",Lua_Entity);
        return -1;
    }
}
int LoadEntityLibrary(lua_State *L){
    luaL_newlib(L,Entity_Reg);
}
int CreateEntityDataLua(lua_State *L){
    const char* entity_name = lua_tostring(L,1);
    float entity_x = lua_tonumber(L,2);
    float entity_y = lua_tonumber(L,3);
    int entity_ID = lua_tointeger(L,4);
    Lua_Entity = malloc(sizeof(EntityData));
    Lua_Entity->name = entity_name;
    Lua_Entity->posX = entity_x;
    Lua_Entity->posY = entity_y;
    Lua_Entity->Entity_ID = entity_ID;

}
