/*
 * LuaGameState.h
 *
 *  Created on: Aug 22, 2020
 *      Author: admin
 */

#ifndef LUAGAMESTATE_H_
#define LUAGAMESTATE_H_
#include"GameState.h"
#include<lua.h>
void Lua_OnStart();
void Lua_OnLoading();
void Lua_OnFailure();
void Lua_OnMainMenu();
#endif /* LUAGAMESTATE_H_ */
