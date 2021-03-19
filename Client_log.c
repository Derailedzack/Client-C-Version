/*
 * Client_log.c
 *
 *  Created on: Aug 2, 2020
 *      Author: admin
 */

#include"Client_log.h"
void Client_Logger_Log(Client_Log_Level cll,const char* message){
printf("%s%s%s%s:%s","[",Client_Logger_GetLoglevelFromClientLogLevel(cll),"]",__FUNCTION__,message);
}
void Client_Logger_Logf(Client_Log_Level cll,const char* message,...){
printf("%s%s%s%s","[",Client_Logger_GetLoglevelFromClientLogLevel(cll),"]");
}
void Client_Logger_SetCustomLogLevel(Client_Log_Level cll,const char* level_name){

}
const char* Client_Logger_GetLoglevelFromClientLogLevel(Client_Log_Level cll){
   if(cll == DEBUG){
	   return "Debug";
   }else if(cll == WARNING){
	   return "Warning";
   }else if(cll == INFO){
   return "Info";
   }else if(cll == FATAL){
    return "Fatal";
   }else if(cll == SEVERE){
    return "Severe";
   }else{
	   return "The specified argument doesn't have a string rep!";
   }
}
