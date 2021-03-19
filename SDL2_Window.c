#include "SDL2_Window.h"
#define NK_IMPLEMENTATION
#include"nuklear.h"
#include "CommandInt.h"
bool RenderingDisabled = false;
SDL_bool SDL_RenderLoop = SDL_FALSE;
SDL_bool SDL_ONLY_DEBUG_DRAW = SDL_FALSE;
const luaL_Reg SDL2_GL_Lib[] = {
        {"CreateWindow",SDL2_GL_CreateWindowLibWrap},
        {"EnterRenderLoop",SDL2_GL_RenderLoopWrapper},
        {NULL,NULL}
};
const luaL_Reg SDL2_Lib[] = {
        {"CreateWindow",SDL2_CreateWindowWrapper},
        {"EnterRenderLoop",SDL2_RenderLoopWrapper},
        {NULL,NULL}
};
int SDL2_GL_RenderLoopWrapper(lua_State* L){

}
void SDL2_CreateWindow(int w, int h)
{

	int window_renderer_combo = SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_RESIZABLE, &SDL_window, &SDL_renderer);


	//if (SDL_window == NULL) {
   //SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Project", "Failed to create SDL 2 Window", NULL);
//	SDL_Quit();
//}
//if (SDL_renderer == NULL) {
	//SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Project", "Failed to create SDL 2 Renderer", NULL);
//SDL_Quit();
//}
	if (window_renderer_combo == -1) {

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Project", "Failed to create SDL 2 Window and Renderer", NULL);
		//SDL_Quit();
        GetCommandInput();
	}
	else {
		Current_window = SDL;
Player_Special_init();

		SDL_RenderLoop = SDL_TRUE;
if(SDL_ONLY_DEBUG_DRAW == SDL_TRUE){

}else{
    RenderALLEntities();
}
		//SDL_GL_GetProcAddress(gladloadgl)


	}


}

void SDL2_RenderLoop()
{
	float prev_ypos;
	int delay;
	while (SDL_RenderLoop == SDL_TRUE) {
		SDL_PollEvent(&SDL_event);

		SDL_RenderClear(SDL_renderer);
		if(SDL_ONLY_DEBUG_DRAW == SDL_TRUE){

        }else{
            RenderALLEntities();
            //glClear(GL_COLOR_BUFFER_BIT);


            //SDL_GL_SetSwapInterval(1);
            UpdateALLEntities();

        }

		//SDL_GL_SwapWindow(SDL_window);
		SDL_RenderPresent(SDL_renderer);


		if (SDL_event.type == SDL_QUIT) {
			SDL_RenderLoop = SDL_FALSE;
			SDL_Quit();
		}
		if(SDL_ONLY_DEBUG_DRAW == SDL_TRUE ){

		}else{
            if(SDL_event.type == SDL_KEYDOWN){
                if(SDL_event.key.keysym.sym == SDLK_RIGHT){
                    Player_data->posX += 0.222225f;
                }
                if(SDL_event.key.keysym.sym == SDLK_LEFT){
                    Player_data->posX -= 0.222225f;
                }
                if(SDL_event.key.keysym.sym == SDLK_UP){
                    prev_ypos = Player_data->posY;
                    Player_data->posY += 0.222225f;
                }
                if(SDL_event.key.keysym.sym == SDLK_DOWN){
                    prev_ypos = Player_data->posY;
                    Player_data->posY -= 0.222225f;
                }
                if(SDL_event.key.keysym.sym == SDLK_SPACE){

                   /* Player_data->posY += 0.222225f;
                    delay++;
                    if(delay >= 60){
                        Player_data->posY += prev_ypos;
                    }*/


                }
		}




	   }

	   if(SDL_event.type == SDL_WINDOWEVENT){
		   if(SDL_event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED){

			 // glViewport(0,0,SDL_event.window.data1,SDL_event.window.data2);

		   }
	   }



}
}
void SDL2_GL_CreateWindow(int w,int h){
	int window_renderer_combo = SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE, &SDL_window, &SDL_renderer);
	if (window_renderer_combo == -1) {

			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Project", "Failed to create SDL 2 Window and Renderer", NULL);
        GetCommandInput();
			//SDL_Quit();
		}
		else {

		SDL_context = SDL_GL_CreateContext(SDL_window);

			if(SDL_context == NULL){

				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Project","Failed to create a SDL 2 OpenGL Context!",NULL);

			}
			if(SDL_GL_MakeCurrent(SDL_window,SDL_context) != 0){
				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Project","Failed to make OpenGL Current!",NULL);
				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Project",SDL_GetError(),NULL);
                GetCommandInput();
			}
			#ifdef HAVE_GLAD_H
			gladLoadGLLoader(SDL_GL_GetProcAddress);
			#else

			#endif
            Current_window = GL;
			SDL_RenderLoop = SDL_TRUE;

			//SDL_GL_GetProcAddress(gladloadgl)

       // if(SDL_ONLY_DEBUG_DRAW == SDL_TRUE ){
         //   RenderALLDebugObjects();
        //}else{
            RenderALLEntities();
        //}

		}
}
void SDL2_GL_RenderLoop(){
    float prev_ypos;
    int delay;
	while (SDL_RenderLoop == SDL_TRUE) {
			SDL_PollEvent(&SDL_event);

			//SDL_RenderClear(SDL_renderer);
      //  if(SDL_ONLY_DEBUG_DRAW == SDL_TRUE ){
            //RenderALLDebugObjects();
            //UpdateALLDebugObjects();
      //  }else{
      if(RenderingDisabled == true){
          SDL_RenderLoop = false;
			//SDL_RenderPresent(SDL_renderer);
      }else{


          RenderALLEntities();

          // }

          //

          glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
          UpdateALLEntities();

          //SDL_GL_SetSwapInterval(1);



          SDL_GL_SwapWindow(SDL_window);
      }

			if (SDL_event.type == SDL_QUIT) {

				SDL_RenderLoop = SDL_FALSE;
				SDL_Quit();
			}
        //if(SDL_ONLY_DEBUG_DRAW == SDL_TRUE ){

        //}else{
            if(SDL_event.type == SDL_KEYDOWN){
                if(SDL_event.key.keysym.sym == SDLK_RIGHT){
                    SDL2_OnPlayerMove(1);
                    Player_data->posX += 0.222225f;
                }
                if(SDL_event.key.keysym.sym == SDLK_LEFT){
                    SDL2_OnPlayerMove(1);
                    Player_data->posX -= 0.222225f;
                }
                if(SDL_event.key.keysym.sym == SDLK_UP){
                    SDL2_OnPlayerMove(0);
                    prev_ypos = Player_data->posY;
                    Player_data->posY += 0.222225f;
                }
                if(SDL_event.key.keysym.sym == SDLK_DOWN){
                    SDL2_OnPlayerMove(0);
                    prev_ypos = Player_data->posY;
                    Player_data->posY -= 0.222225f;
                }
                if(SDL_event.key.keysym.sym == SDLK_SPACE){
                    RenderingDisabled = true;
                    SDL_HideWindow(SDL_window);
                    GetCommandInput();
                    /*Player_data->posY -= 0.06f;
                    delay++;
                    if(delay >= 60){
                       Player_data->posY = prev_ypos;
                    }*/

                }

           }

		  // }

		   if(SDL_event.type == SDL_WINDOWEVENT){
			   if(SDL_event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED){

				  glViewport(0,0,SDL_event.window.data1,SDL_event.window.data2);

			   }
		   }
}
}

void SDL2_GL_Restart(){
	    RenderingDisabled = false; //Clear rendering disabled
	    SDL_ShowWindow(SDL_window);

	   // SDL2_GL_CreateWindow(640,480);
	    SDL2_GL_RenderLoop();
}

void SDL2_GL_DrawPixel(float w,float h,float x,float y,float x2,float y2){
        glScalef(w,h,0);
        glRectf(x,y,x2,y2);
}
void SDL2_ErrorCallback(int error, const char* description)
{

}
void  SDL2_GL_ErrorCallback() {

}

void SDL2_FramebuffersizeCallback(int width, int height)
{

}

void SDL2_KeyCallback( int key, int scancode, int action, int mods)
{

}
void SDL2_OnPlayerMove(int axis){
    if(IsOnServer == true){
        if(axis == 1){ //Check if the axis parameter is 1

        }else if(axis == 0){ //Else check if the axis parameter is 0

        }else{ //Do something or nothing when the axis parameter is invalid

        }
    }else{

    }
}

void SDL2_GL_OpenLib(lua_State* L){
   // luaL_newlib(L,)
}
int SDL2_GL_CreateWindowLibWrap(lua_State* L){
    int widthlua = lua_tointeger(L,1);
    int heightlua = lua_tointeger(L,2);
    if(widthlua == 0 ){
        widthlua = 640;
    }
    if(heightlua == 0){
        heightlua = 480;
    }
    SDL2_GL_CreateWindow(widthlua,heightlua);
}
int SDL2_CreateWindowWrapper(lua_State* L)
{
	return 0;
}

int SDL2_RenderLoopWrapper(lua_State *L)
{
	return 0;
}

int SDL2_ShowSimpleMessageBoxWrapper(lua_State* L)
{
	return 0;
}

int SDL2_SetRenderDrawColor(lua_State* L)
{
	return 0;
}

int SDL2_RenderClearWrapper(lua_State* L)
{
	return 0;
}

int SDL2_RenderDrawLine(lua_State* L)
{
	return 0;
}

