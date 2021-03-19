#pragma once
/*Don't use window creation in the player draw script.If you do it will causes an infinite loop*/
#include <stdbool.h>
#include<errno.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#ifdef HAS_READLINE_H
#include"readline/readline.h"
#endif
#include"GLWarpper.h"
#include"UserdataTest.h"
//#include"GLFW_Window.h"


static const luaL_Reg library_test[] = {
		{"new",newtest},
		{"set",settest},
		{NULL,NULL}
};

static const luaL_Reg game_libs[] = {
        {"test",initUserData},
        {"Entity",LoadEntityLibrary},
        {NULL,NULL}
};

bool LUAIntLoop;
void Create_Lua();
void Register_C_Functions();
void CreateInterpertor();
void CreateInterpertor_file();
int Example_Lua_FUNCTION(lua_State* L);
int Lua_PanicFunc(lua_State* L);
void custom_OpenLibs(lua_State* L);
lua_State* Get_Lua_State();
//void Alloc_LUA(void* ud, void* ptr, size_t osize, size_t nsize);
