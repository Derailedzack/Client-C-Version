#pragma once
#include<windows.h>

void Client_LoadGetClientVersionFromSharedLib(const char* path);
void Client_LoadSendServerVersionFromSharedLib(const char* path);
void Client_LoadCreateConnectionFromSharedLib(const char* path);
void Client_LoadConnectToServerFromSharedLib(const char* path);
void Client_LoadHandleConnectionErrorFromSharedLib(const char* path);
void Client_LoadInitNetworkFromSharedLib(const char* path);
void Client_LoadHandleDisconnectionFromSharedLib(const char* path);
void Client_LoadSendDataFromSharedLib(const char* path);
void Client_LoadOnConnectFailedFromSharedLib(const char* path);
void Client_LoadOnConnectSuccessFromSharedLib(const char* path);
void Client_LoadOnDisconnectionFromSharedLib(const char* path);
void Client_LoadCustomFunctionFromSharedLib(const char* path,const char* function_name);
