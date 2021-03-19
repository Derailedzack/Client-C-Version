/*
 * Userdata.c
 *
 *  Created on: Jul 27, 2020
 *      Author: admin
 */
#include"UserdataTest.h"


typedef struct test22{
	int test;
	float test2;
}test22;
luaL_Reg *library;

int newtest(lua_State *L){

	//int arg0 = luaL_checkinteger(L,1);
	//luaL_checktype(L,1,LUA_TFUNCTION);
	//lua_pushvalue(L,1);
	//lua_call(L,0,0);
	/*int arg0_store;
	int arg0 = lua_tointeger(L,1);
    test22 *Object = (test22*)lua_newuserdata(L,sizeof(test22));

    if(arg0 == 0){
    Object->test = 1;
	}
	float arg1 = lua_tonumber(L,2);
    if(arg1 == 0){
    Object->test2 = 1.0f;
    }*/

return 1;
}
int settest(lua_State *L){
return 0;
}
void LoadUserdata(lua_State *L){
    //const luaL_Reg *lib;
//FILE* test = fopen("reg.out","w");
//if(test == NULL){
    //printf("Failed to save registry output!\n");
//}
  // for (lib = game_libs; lib->func; lib++) {
     //   fputs(lib->name,test);
     //   fputs("\n",test);
   // luaL_requiref(Get_Lua_State(), game_libs->name, game_libs->func, 0);
    //luaL_newlib(L,library_test);
     //lua_pop(L, 1);  /* remove lib */
    // }
     //fclose(test);

}
int initUserData(lua_State *L){
    const luaL_Reg *lib;
	//luaL_getsubtable(L, LUA_REGISTRYINDEX, LUA_PRELOAD_TABLE);
	//lua_pushcfunction(L, initUserData);
	//lua_setfield(L, -2,library_test->name);
	//printf("%s", library_test->name);
	//lua_pop(L, 1);  // remove PRELOAD table
   // luaL_requiref(L, library->name, library->func, 1);
    //lua_pop(L, 1);
//	luaL_openlib(Get_Lua_State(),"test",library_test,0);

    /* "require" functions from 'loadedlibs' and set results to global table */
   // for (lib = library_test; lib->func; lib++) {
     // luaL_requiref(Get_Lua_State(), lib->name, lib->func, 1);

   //   lua_pop(L, 1);  /* remove lib */
//}
 luaL_newlib(L,game_libs);
	return 1;
}





