#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED
#include"Window.h"
#include<stdio.h>
#include<stdlib.h>
typedef struct ClientConf_Raw{
    WINDOW_TYPE default_window_type;
    WINDOW_TYPE current_window_type;
    int default_window_width;
    int default_window_height;
    int window_width;
    int window_height;
}ClientConf_Raw;
typedef struct ClientConf_Str{
    const char* default_window_type;
    const char* current_window_type;
    const char* default_window_width;
    const char* default_window_height;
    const char* window_width;
    const char* window_height;
}ClientConf_Str;

void WriteDefaultsToConfig(const char* conf_path);
void WriteValuesToConfig(const char* conf_path);

ClientConf_Str ReadConfigFromFile(const char* path);
const char* GetWindowTypeStr(WINDOW_TYPE window_type);
#endif // CONFIG_H_INCLUDED
