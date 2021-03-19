#include<lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include "LuaUtils.h"
#include "Entity.h"

int newtest(lua_State *L);
int settest(lua_State *L);
void LoadUserdata(lua_State *L);
int initUserData(lua_State *L);

