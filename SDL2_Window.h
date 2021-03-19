#pragma once

#include <stdbool.h>
#include"Window.h"
#include "RenderEntities.h"
#include"RenderDebug.h"
#include"Client.h"
#include<SDL.h>

#ifdef HAVE_GLAD_H

#include<glad/glad.h>
#else
#undef __gl_h_
#include"gl/glew.h"
#endif
#include<lua.h>
#include <lauxlib.h>
#include <lualib.h>
//The _GL Indicates that the function is the opengl implementation of it
SDL_Window* SDL_window;
SDL_Renderer* SDL_renderer;
SDL_Event SDL_event;
SDL_GLContext SDL_context;
bool IsOnServer;
int SDL2_GL_CreateWindowLibWrap(lua_State* L);
int SDL2_GL_RenderLoopWrapper(lua_State* L);
int SDL2_CreateWindowWrapper(lua_State* L);
int SDL2_RenderLoopWrapper(lua_State *L);
int SDL2_ShowSimpleMessageBoxWrapper(lua_State* L);
int SDL2_SetRenderDrawColor(lua_State* L);
int SDL2_RenderClearWrapper(lua_State* L);
int SDL2_RenderDrawLine(lua_State* L);


int SDL_window_width;
int SDL_window_height;

void SDL2_CreateWindow(int w,int h);
void SDL2_RenderLoop();
void SDL2_ErrorCallback(int error, const char* description);

void SDL2_FramebuffersizeCallback(int width, int height);
void SDL2_KeyCallback(int key, int scancode, int action, int mods);
void SDL2_GL_ErrorCallback();
void SDL2_GL_CreateWindow(int w,int h);
void SDL2_GL_DrawPixel(float w,float h,float x,float y,float x2,float y2);
void SDL2_GL_RenderLoop();
void SDL2_GL_Restart();
void SDL2_OnPlayerMove(int axis);
void SDL2_GL_OpenLib(lua_State* L);

