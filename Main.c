#include"Main.h"
#include "EntityLoader.h"
#include"Client.h"

#include<stdio.h>
#include"GDIDisplay.h"
#include"SDL2_Window.h"
#include "Player.h"
#include"LuaUtils.h"
#include"LevelLoader.h"
#include <signal.h>
#include<string.h>
//Todo:Find a crash reporting library if necessary implement it myself
//Todo:Find a discord library
/* TODO (admin#1#): Refactor the source*/
//Todo:Refactor the source code
//I'm not sure why I have quite a few of duplicated code
//That should have been caught and fixed

//#include <xkeycheck.h>
#include "CuteSound.h"
#include"TestLevel.h"
#include"Client.h"
#include"Modloader.h"
#include "CommandInt.h"
#undef main
//LevelData* data;
bool net_test;
FILE* client_data_log;
FILE* file;

char padding[1024];
//const char* data[25+16];
void segv_handler(int signal){
	exit(-223);
}
int main(int argc, char* argv[]) {
#ifdef DISABLE_RENDERING
   // memset(padding,0xff,1024);

    GetCommandInput();
#else
	SDL_Init(SDL_INIT_EVERYTHING);
    //Init_Network();
   //LoadLevel();
    Player_init();
	Collsion_init();
//    LoadLevel();
//setopt(argc,argv,"Test");
    //ConnectToServer(0);
   SDL2_CreateWindow(640,480);

   SDL2_RenderLoop();
#endif
	//SDL2_GL_CreateWindow(640,480);
	//SDL2_GL_RenderLoop();
    //LoadMod("Test.data");
	//data = malloc(sizeof(LevelData));
	//if(data == NULL){
		//printf("Failed to allocate level data!");
		//exit(-1);
	//}
	//data->level_data = "";
	//WriteLevelToFile("WriteTest.level",data,NULL);
	//LoadLevel();

	Client_Logger_Log(DEBUG,"Test!");

	return 0;
}
