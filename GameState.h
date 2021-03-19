#pragma once
typedef void (OnStart_func)();
typedef void (OnLoading_func)();
typedef void (OnFailure_func)();
typedef void (OnMainMenu_func)();
typedef enum GAME_STATE{
    MAIN_MENU,
    GAME,
    GUI,
    DEBUG_SCREEN,
    EDIT_MODE,
    EXITING,
    SERVER_START,
    CLIENT_START,
    CLIENT_CREATEWIN,
    CLIENT_RENLOOP,
    CUSTOM_STATE,
    CRASHED,
    CRASHED_SEH
}GAME_STATE;
void OnStart(OnStart_func* onstart);
void OnLoading(OnLoading_func* onloading);
void OnFailure(OnFailure_func* onfailure);
void OnMainMenu(OnMainMenu_func* onmainmenu);
