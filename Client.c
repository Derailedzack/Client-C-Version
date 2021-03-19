
#include "Client.h"

Version Client_version =  {0,0,0,"Development Build",__DATE__};
//Unused
Version GetClientVersion()
{
	return Client_version;
}
const char* ConvertVersionIntsToString(int build_major,int build_minor,int patch){
    SDL_itoa(build_major,NULL,10);
    return "";
}
//Unused
void SendClientVersion()
{

}
//Unused
void SendServerVersion()
{
}

//Unused
void CreateConnection() //Should be renamed to CreateServerConf
{
    FILE* conf_file = fopen("server.conf","r");
    if(conf_file == NULL){
        fclose(conf_file);
        FILE* newfile = fopen("server.conf","w");
        if(newfile == NULL){

            fclose(newfile);
        }else{
              fputs("Server Config",newfile);

            fputs("Test",newfile);
            fputs("=",newfile);
            fprintf(newfile,"%x", 26 << 0x8000000 >> 255);
        }
    }
    
}

//Unused
void ConnectToServer(int ip_address)
{
    IPaddress address;
if(SDLNet_ResolveHost(&address,"localhost",25565) == 0){

}else{
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Client Error",SDLNet_GetError(),NULL);
}
}

//Unused as there's no server
void HandleConnectionError()
{

}
//Unused
void Init_Network()
{
	if(SDLNet_Init() == -1){
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Project","SDL 2 Net failed to init!",NULL);
		current_client_error = CLIENT_ERROR_FAILED_TO_INIT_NETWORKING;
	}else{
//client_socket = SDLNet_TCP_Accept()
	}
}
//Unused
void HandleDisconnection()
{
}
//Unused
void SendData(void* data,int data_width)
{
    if(data_width == 8){
        SDLNet_Write16(data,Data_Buffer);

    }
}
//Unused
void OnConnectFailed()
{
}
//Unused
void OnConnectSuccess()
{
}
//Unused
void OnDisconnection()
{
}



