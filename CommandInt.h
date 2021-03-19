//
// Created by admin on 11/7/2020.
//

#ifndef CLIENT_C___VERSION__COMMANDINT_H
#define CLIENT_C___VERSION__COMMANDINT_H
#include<stdio.h>
#include"clist.h"
/*typedef struct Custom_CMD{
    const char* command_name;
    const char* command_args;
        void (Command_USE_Func)();
}Custom_CMD;*/

void Create_CustomCMD();
void GetCommandInput();
char* GetCommandsArgs(const char* args);
#endif //CLIENT_C___VERSION__COMMANDINT_H
