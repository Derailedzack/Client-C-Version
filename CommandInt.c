//
// Created by admin on 11/7/2020.
//

#include "CommandInt.h"
#ifdef HAS_READLINE_H
#include"readline/readline.h"
#endif
#include"SDL2_Window.h"
bool command_loop = true;
void GetCommandInput(){
#ifdef HAS_READLINE_H
    while(command_loop == true){
        char* in = readline(">");

        //printf("%s\n",GetCommandsArgs(in));
        if(strcmp("show",in) == 0){
            SDL_ShowWindow(SDL_window);
        }else if(strcmp("hide",in) == 0){
            SDL_HideWindow(SDL_window);
        }else if(strcmp("Connect",in) == 0){
            //SDLNet_TCP_Accept()
        }else if(strcmp("exit",in) == 0){
            command_loop = false;
        }else if(strcmp("startsdl",in) == 0){
            SDL2_GL_Restart();
        }else if(strcmp("splitstring",in) == 0){
            //char* tok = strtok(in," ");
           // while(tok != NULL){



        }else if(strcmp("help",in) == 0){
            printf("Command Name      Description\n");
            printf("show              Shows the SDL 2 Window\n");
            printf("hide              Hide the SDL2 Window\n");
            printf("Connect           Does nothing\n");
            printf("exit              Exits the interpreter and program\n");
            printf("startsdl          Restarts SDL 2 Rendering and Shows the window\n");
            printf("splitstring       Does nothing\n");

        }else if(strcmp("lua",in) == 0){
            LUAIntLoop = true;
            CreateInterpertor();
        }else if(strcmp("lua_file",in) == 0){
            LUAIntLoop = true;
            CreateInterpertor_file();
        }else if(strcmp("build_date",in) == 0){
            printf("Build Date:%i",GetClientVersion().build_info);
        }else if(strcmp("lua_version",in) == 0){
          //   Register_C_Functions();

         // printf("\x0020");
    Create_Lua();
    luaL_dostring(Get_Lua_State(),"print(_VERSION)");
           // printf("%s\n",);
        //}//else{
           // HINSTANCE inst = ShellExecuteA(NULL,"open",in,NULL,NULL,SW_SHOW );
           //if( inst > 32){

           //}else{
             //  printf("%s\n",strerror(GetLastError()));
           //}
        }else if(strcmp("WriteLevel",in) == 0){
           // WriteLevelToFile("Test.level",)
        }else if(strcmp("WriteConf",in) == 0){
           // CreateConnection();
           printf("%i",Current_window);
            WriteDefaultsToConfig("test.conf");
        }else if(strcmp("TestController",in) == 0){
           // CList_Init(EntityData);

            //printf(L"\32");
          /*  SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS);
            SDL_GameController* game_controller = SDL_GameControllerOpen(0);
            if(game_controller == NULL){
                printf("Failed to open GameController!:%s\n",SDL_GetError());
            }else{
                bool Controller_test = true;
                while(Controller_test == true){
                         if(SDL_GameControllerGetButton(game_controller,SDL_CONTROLLER_BUTTON_A) == 1){
                    Controller_test = false;
                 }
                 printf("X Axis:%i\n",SDL_GameControllerGetAxis(game_controller,SDL_CONTROLLER_AXIS_LEFTX));

                }*/

            }else if(strcmp("StartGL",in) == 0){
                SDL_Init(SDL_INIT_EVERYTHING);
                Collsion_init();
                Player_init();
                     command_loop = false;
                SDL2_GL_CreateWindow(640,480);

                SDL2_GL_RenderLoop();
            }

                  if(!in){
                printf("EOF\n");

            }
        }

#endif
#ifndef HAS_READLINE_H
printf(">");
scanf("%s");

#endif
}
char* GetCommandsArgs(const char* args){
    char* output = strtok(args,"\32");
    while(output != NULL){
        output = strtok(NULL,"\32");
        printf("%s\n",output);
        return output;
    }

}
