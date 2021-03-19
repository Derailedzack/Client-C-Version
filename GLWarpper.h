#pragma once
#include<glad/glad.h>
#include<lua.h>
#include<stdio.h>
int GLBeginWrapper(lua_State* L);
int GLVertexWrapper(lua_State* L);
int GLColorWrapper(lua_State* L);
int GLEndWrapper(lua_State* L);