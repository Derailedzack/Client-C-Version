#include "EntityLoader.h"



void LoadEntityDrawFromDLL(const char* path)
{
	HINSTANCE result = LoadLibrary(path);
	if (result == NULL) {
		printf("Failed to load DLL:%i",GetLastError());
	}
	else {
		Draw_func* draw2 = (Draw_func*)GetProcAddress(result, "draw");
		draw2();
	}
	
}

void LoadEntityRedrawFromDLL(const char* path)
{
	HINSTANCE result = LoadLibrary(path);
	if (result == NULL) {
		printf("Failed to load DLL:%i", GetLastError());
	}
	else {
		Redraw_func* redraw2 = (Redraw_func*)GetProcAddress(result, "redraw");
		redraw2();
	}
}

void LoadEntityCullsionCheckFromDLL(const char* path,rect* entity_rect)
{
	HINSTANCE result = LoadLibrary(path);
	if (result == NULL) {
		printf("Failed to load DLL:%i", GetLastError());
	}
	else {
		OnCullsion_func* cullTest = (OnCullsion_func*)GetProcAddress(result, "OnCullsion");
		cullTest(entity_rect);
	}
}
