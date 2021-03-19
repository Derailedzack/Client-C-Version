#include "GLWarpper.h"

int GLBeginWrapper(lua_State* L)
{
    int val = lua_tointeger(L, 1);
    printf("\nGLBEGIN:%i\n", val);
    glBegin(val);
    return 0;
}

int GLVertexWrapper(lua_State* L)
{
   printf("\nX:%i,Y:%i,Z:%i", lua_tointeger(L, 1), lua_tointeger(L, 2), lua_tointeger(L, 3));
   glVertex3i(lua_tointeger(L, 1), lua_tointeger(L, 2), lua_tointeger(L, 3));
   return 0;
}

int GLColorWrapper(lua_State* L)
{
   printf("\nR:%i,G:%i,B:%i", lua_tointeger(L, 1), lua_tointeger(L, 2), lua_tointeger(L, 3));
   glColor3i(lua_tointeger(L, 1), lua_tointeger(L, 2), lua_tointeger(L, 3));
   return 0;
}

int GLEndWrapper(lua_State* L)
{
    glEnd();
    return 0;
}
