#pragma once
#include"lua.h"
void scriptable_item_use();
void scriptable_init_item();
int scriptable_item_use_wrapper(lua_State *L);
int scriptable_init_item_wrapper(lua_State* L);