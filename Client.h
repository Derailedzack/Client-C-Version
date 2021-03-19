#pragma once
#include<SDL_net.h>
#include<stdio.h>
#include <stdbool.h>

typedef enum CLIENT_ERROR {
	CLIENT_ERROR_FAILED_TO_CONNECT_TO_HOST,
	CLIENT_ERROR_FAILED_TO_INIT_NETWORKING,
	CLIENT_NO_ERROR
}CLIENT_ERROR;
typedef struct{
    const char* section;
    int ip_address;
    int port;
    const char* owner_name;
    bool HasMods;
    bool CanBeModded;
}Server_Config;
TCPsocket client_socket;
CLIENT_ERROR current_client_error;
void* Data_Buffer;
/*Only one of these will be implemented depending on the type of program it is*/
void SendClientVersion();
void SendServerVersion();
void CreateConnection();
void ConnectToServer(int ipaddress);
void HandleConnectionError();
void Init_Network();
void HandleDisconnection();
void SendData(void* data,int data_width);
void OnConnectFailed();
void OnConnectSuccess();
void OnDisconnection();
bool IsConnected;
/**
 * \brief Version Structure
 */
typedef struct Version {
	int major;
	int minor;
	int patch;
	const char* build_type;
	const char* build_info;
}Version;
Version GetClientVersion();
const char* ConvertVersionIntsToString(int build_major,int build_minor,int patch);
