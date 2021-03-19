#include <memory.h>
#include <stdlib.h>
#include "LevelLoader.h"

void WriteLevelToFile(const char* path, LevelData* leveldata,Tile* leveltiles)
{
	Level_File = fopen(path, "w");
	leveldata->magic = "LEVELDATA";
	fputs(leveldata->magic,Level_File);

	for (int i = 0; i < 1024; i++) {
            fputc(leveldata->padding[i], Level_File);
		for (int i2 = 0; i2 < 600; i2++) {
		//	memset(leveldata->padding[i2], 0xFF, sizeof(leveldata->padding));
			//memset(leveldata->level_data, 255, sizeof(leveldata->level_data));


            fputc(leveldata->level_data[i2], Level_File);
		}
	}

	fclose(Level_File);
}

void ReadLevelFromFile(const char* path, LevelData* leveldata)
{
    char *Level_data;
    Level_File = fopen(path, "r");
    if(Level_File == NULL){
        fclose(Level_File);
        free(Level_File);
    }
    else{
        const char* sig = fgets(sig,sizeof("LEVELDATA"),Level_File);
        if(strcmp(sig,"LEVELDATA") != 0){
            printf("Level MAGIC String not found! Closing File! %s",path);
            fclose(Level_File);
            free(Level_File);
        }else{
            int val = fgetc(Level_File);


            while(val  != EOF){
                val = fgetc(Level_File);
                int i = 0;
                Level_data[i++] = val;
            }
        }
    }





}

char ReadLevelFromBuffer(char* Level_Buffer){
    for (int i = 0; i < 1024; ++i) {
        return Level_Buffer[i];
    }
    return 0;
}
