#include <stdio.h>
#include "Modloader.h"
#define MAX_TEXT_LENGTH 65536
void LoadMod(const char* path)
{
    char* buf;
    ModInfo* mod_info = malloc(sizeof(ModInfo));
    FILE* test_file = fopen(path,"r");
    //fgets()
//    fgets(mod_info.author,MAX_TEXT_LENGTH,test_file);
    //fgets(mod_info.client_version.major)
    //fwrite(LoadMod,sizeof(LoadMod),sizeof(LoadMod),test_file);
  //  fputc(1.0f,test_file);
    fclose(test_file);
  /*  HINSTANCE result = LoadLibrary(path);
    if (result == NULL) {
        printf("Failed to load DLL:%i",GetLastError());
    }
    else {
        Draw_func* draw2 = (Draw_func*)GetProcAddress(result, "draw");
        draw2();
    }*/


}
void Test(){
    printf("test");
}
void CreateEntity(const char* path)
{
}

void CreateSound(const char* path)
{
}

void CreateScript(const char* path)
{
}
