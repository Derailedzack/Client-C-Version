#include "GameState.h"
void OnStart(OnStart_func* onstart){
	(onstart)();
}
void OnLoading(OnLoading_func* onloading){
	(onloading)();
}
void OnFailure(OnFailure_func* onfailure){
	(onfailure)();
}
void OnMainMenu(OnMainMenu_func* onmainmenu){
	(onmainmenu)();
}
