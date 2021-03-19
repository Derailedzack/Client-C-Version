#include"Config.h"
void WriteDefaultsToConfig(const char* conf_path){
   // ClientConf_Raw* clientconf_raw = malloc(sizeof(ClientConf_Raw));
    ClientConf_Str* clientconf  = malloc(sizeof(ClientConf_Str));
    clientconf->current_window_type = GetWindowTypeStr(Current_window);
    clientconf->default_window_width = "640";
    clientconf->default_window_height = "480";
    clientconf->window_width = "640";
    clientconf->window_height = "480";
    FILE* conf_file = fopen(conf_path,"w");
fputs("current_window_type=",conf_file);
fputs(clientconf->current_window_type,conf_file);
fclose(conf_file);

}
void WriteValuesToConfig(const char* conf_path){
}

ClientConf_Str ReadConfigFromFile(const char* path){
}
const char* GetWindowTypeStr(WINDOW_TYPE window_type){
    switch(window_type){
    case GL:
        return "OpenGL";
        break;
    case GDI:
        return "GDI+/Generic";
        break;
    case DIRECTX:
        return "DIRECTX";
        break;
    case NONE:
        return "NULL"; //NULL in this case means that there isn't a window
        break;
    case SDL:
        return "SDL 2";
        break;
    case LUA:
        return "LUA";
        break;

    }
}
