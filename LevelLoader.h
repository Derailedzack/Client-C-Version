#pragma once
#include<stdio.h>
typedef struct Tile {
	int tile_id;
	int tile_type;
	int tile_X;
	int tile_Y;
	int tile_W;
	int title_H;
}Tile;
typedef struct LevelData {
	const char* magic;
	char* padding;
	char* level_data;
}LevelData;
Tile* Level_tiles;
FILE* Level_File;
void WriteLevelToFile(const char* path,LevelData* leveldata,Tile* leveltiles);
void ReadLevelFromFile(const char* path, LevelData* leveldata);
char ReadLevelFromBuffer(char* Level_Buffer);