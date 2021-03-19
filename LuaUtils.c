#include "LuaUtils.h"
lua_State* state;

static const luaL_Reg libs_test[] = {
};
void Create_Lua()
{

	state = luaL_newstate();
		luaL_openlibs(state);

  //  LoadUserdata(state);
  custom_OpenLibs(state);
    Register_C_Functions();

    	//LoadUserdata(state);
    //lua_atpanic(state,Lua_PanicFunc);
}

void Register_C_Functions()
{
	lua_register(state, "Test_func", Example_Lua_FUNCTION);
	lua_register(state, "GLBegin", GLBeginWrapper);
	lua_register(state, "GLVertex3", GLVertexWrapper);
	lua_register(state, "GLColor3", GLColorWrapper);
	lua_register(state, "GLEnd", GLEndWrapper);

	lua_register(state,"InitTestUserdata",initUserData);
}

int Example_Lua_FUNCTION(lua_State* L)
{
	//if (lua_rawget(L, 1) == LUA_TFUNCTION) {
printf("%i",__LINE__);
	//	lua_call(L, 1, 0);
	//}
	//else {
		//printf("lua_rawget(L, -1):%i",lua_rawget(L, 1));
	//}
	return 0;
}

lua_State* Get_Lua_State()
{
	return state;
}
void CreateInterpertor(){
      Create_Lua();
      Register_C_Functions();



    //initUserData(Get_Lua_State());
        #ifdef HAS_READLINE_H
while(LUAIntLoop == true){

    char* in = readline("lua>");
    if(strcmp("exit",in) == 0){
        LUAIntLoop = false;
    }else if(strcmp("open_userdata",in) == 0){
        LoadUserdata(state);
    }

    else{

        //luaL_dostring(Get_Lua_State(),"print(_VERSION)");
        if(luaL_dostring(Get_Lua_State(),in) != 0){
           printf("%s\n",lua_tostring(Get_Lua_State(),-1));
        }
    }
}
#endif
}
int Lua_PanicFunc(lua_State* L){
}
void CreateInterpertor_file(){
    Create_Lua();

    Register_C_Functions();
    //initUserData(Get_Lua_State());
    while(LUAIntLoop == true){
        char* in = readline("lua_file>");
       // printf("The Lua Developement Interpertor\n");
        if(strcmp("exit",in) == 0){
            LUAIntLoop = false;
        }else{

            // luaL_dostring(Get_Lua_State(),"")
//if(access(in,F_OK) != 0 && access(in,R_OK) != 0){
  //  printf("The Specified file can't be opened! Error Message:%s",strerror(errno));
//}else{
    if(luaL_dofile(Get_Lua_State(),in) != 0){
        printf("%s\n",lua_tostring(Get_Lua_State(),-1));
    }
//}
        }
}

}
 void custom_OpenLibs(lua_State* L){
    luaL_getsubtable(L,LUA_REGISTRYINDEX,LUA_PRELOAD_TABLE);
    lua_pushcfunction(L,initUserData);
    lua_setfield(L,-2,"test");
    lua_pop(L,1);
}
