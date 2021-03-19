cmake_minimum_required(VERSION 3.17)
project(Client_C___Version_)

set(CMAKE_C_STANDARD 99)

include_directories(deps\\include\\lua\\ deps\\include\\sdl2\\  deps\\include\\gl\\)
link_directories(C:\\Users\\admin\\Downloads\\SDL2-devel-2.0.12-mingw.tar\\SDL2-devel-2.0.12-mingw\\SDL2-2.0.12\\i686-w64-mingw32\\lib C:\\Users\\admin\\Downloads\\SDL2_net-devel-2.0.1-mingw.tar\\SDL2_net-devel-2.0.1-mingw\\SDL2_net-2.0.1\\i686-w64-mingw32\\lib C:\\Users\\admin\\CLionProjects\\glad\\cmake-build-debug C:\\Users\\admin\\CLionProjects\\Lua5.4\\cmake-build-debug)
link_libraries(SDL2 SDL2_net Lua5_4 glad readline)
add_definitions(-D__OLD_CODE -DDISABLE_RENDERING -DHAVE_GLAD_H)
add_executable(${PROJECT_NAME} Main.c Main.h Audio.c Audio.h Client.c Client.h Client_log.c Client_log.h ClientLoader.h CuteSound.c CuteSound.h DirectSndAudio.h Entity.c Entity.h EntityCollisionTest.c EntityCollisionTest.h EntityLoader.c EntityLoader.h EntityState.c EntityState.h EntityUtils.c EntityUtils.h EntityUtilsLoader.h GameState.c GameState.h GameStateLoader.h GDIDisplay.c GDIDisplay.h GLWarpper.c GLWarpper.h INIConfig.c INIConfig.h Inventory.c Inventory.h ItemLUA.c ItemLUA.h LevelLoader.c LevelLoader.h LuaGameState.c LuaGameState.h LuaUtils.c LuaUtils.h Modloader.c Modloader.h OrgFile.h Player.c Player.h Render.h RenderDebug.c RenderDebug.h RenderEntities.c RenderEntities.h RenderUI.c RenderUI.h Script.c Script.h ScriptLoader.h SDL2_Window.c SDL2_Window.h SDLSound.c SDLSound.h SoundLoader.h test_item.c test_item.h TestLevel.c TestLevel.h UserdataTest.c UserdataTest.h Window.c Window.h WindowLoader.c WindowLoader.h SDL2_Inventory.c SDL2_Inventory.h nuklear.h clist.c clist.h cute_c2.h CommandInt.c CommandInt.h)