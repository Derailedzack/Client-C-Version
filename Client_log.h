/*
 * Client_log.h
 *
 *  Created on: Aug 2, 2020
 *      Author: admin
 */

#ifndef CLIENT_LOG_H_
#define CLIENT_LOG_H_
#include<stdio.h>
#include<stdarg.h>

typedef enum Client_Log_Level{
   DEBUG,
   WARNING,
   INFO,
   FATAL,
   SEVERE,
   CUSTOM_LOGGER
}Client_Log_Level;

void Client_Logger_Log(Client_Log_Level cll,const char* message);
void Client_Logger_Logf(Client_Log_Level cll,const char* message,...);
void Client_Logger_SetCustomLogLevel(Client_Log_Level cll,const char* level_name);
const char* Client_Logger_GetLoglevelFromClientLogLevel(Client_Log_Level cll);
#endif /* CLIENT_LOG_H_ */
