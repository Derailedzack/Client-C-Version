#include "EntityUtils.h"

void Entity_Register(Register_func* register_func)
{
}

void Entity_RegisterAll()
{
}
const char* Entity_GetStrFlag(Entity_Flags entity_flag){
	if(entity_flag == INVISIBLE){
		return "invisible";
	}else if(entity_flag == INVINCIBLE){
		return "indestructible";
	}else if(entity_flag == START_DEAD){
		return "start dead";
	}else if(entity_flag == START_ALIVE){
		return "start alive";
	}else if(entity_flag == CLIENT_ONLY){
		return "Clientside only";
	}else if(entity_flag == SERVER_ONLY){
		return "Serverside only";
	}else if(entity_flag == CUSTOM_FLAG){
		return "Custom";
	}else{
		return "The specified entity flag doesn't have a const char*/string representation!";
	}
}
void Entity_SetCustomFlag(Entity_Flags entity_flags,char* Custom_entity_data,Entity_Data* EntityData)
{
	if (entity_flags == CUSTOM_FLAG) {
		EntityData->custom_data = Custom_entity_data;
	}else{
		printf("The Specifed Entity Flag isn't custom! EntityFlag:%s",Entity_GetStrFlag(entity_flags));
	}
}

void Entity_AddToList(Entity_Data* ent_data){
entity_list = CList_Init(sizeof(Entity_Data));
entity_list->add(entity_list,ent_data);
}
