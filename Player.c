#include "Player.h"

#include <stdlib.h>
//#include "cute_c2.h"
SDL_Rect Entity_Plr_spr;
SDL_Rect Entity_Plr_spr_test;
SDL_Texture* Player_Sprite_tex;
SDL_Surface* Player_Sprite;
int collision;
int GLCodeVer = 1;
float PlayerXpos = -0.566f;
float PlayerYpos = -0.566f;
float CollisionMax = 1.0f;
float CollisionMin = -1.0f;
void Player_init()
{
	Player_data = malloc(sizeof(EntityData));

    bb.max = c2V(CollisionMax,5.0f);
    bb.min = c2V(CollisionMin,-0.000002f);
	Player_data->Enitiy_Speed_Multiplier = 1;
	Player_data->Entity_ID = 1;
	Player_data->Entity_X_Speed = 2;
	Player_data->Entity_Y_Speed = 2;
	Player_data->name = "Player";
	Player_data->posX = 0.0f;
	Player_data->posY = 0.0f;
	Player_data->Entity_Size.width = 32;
	Player_data->Entity_Size.height = 32;


}

void Player_Special_init(){
    if(Current_window == SDL){
		Entity_Plr_spr.x = 0;
		Entity_Plr_spr.y = 0;
		Entity_Plr_spr.w = 16;
		Entity_Plr_spr.h = 16;
		Player_Sprite = SDL_LoadBMP("res//Image1.bmp");
		//Client_Logger_Log(DEBUG,"Test!");

	//Player_Sprite_tex = SDL_CreateTexture(SDL_renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, 32, 32);
	Player_Sprite_tex = SDL_CreateTextureFromSurface(SDL_renderer, Player_Sprite);
	if (Player_Sprite == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Project", "Failed to load bitmap image!",SDL_window);
	}

	if (Player_Sprite_tex == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Project", "Failed to create SDL 2 Texture!", SDL_window);
	}
	}
}
void Player_OldDraw(){
    glEnable(GL_BLEND); //Enable GL_Blend for transparency
    glEnable(GL_DEBUG_OUTPUT); //Enable OpenGL Debug Output
    //	SDL_Log("glEnable:%i,GL_BLEND",glGetError());
    glEnable(GL_FOG); //Enable Fog
    //	SDL_Log("glEnable:%i,GL_FOG",glGetError());
    //glFogiv(GL_FOG_MODE, GL_LINEAR);
    //glFogiv(GL_FOG_DENSITY, 3);
    //glFogiv(GL_FOG_COLOR, 0, 1, 2);
    //glViewport(0, 0, width, height);
    //glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, GL_AMBIENT);
    //glTranslatef(0.5f, 0.0f, 0.0f);

    //glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_CONSTANT_COLOR);
    //SDL_Log("glScaleF:%i,1.0f,1.0f,1.0f",glGetError());
    glScalef(1.0f, 1.0f, 1.0f); //Scale the player
    //SDL_Log("glColor3f:%i,10.0f,0.5f,0.5f",glGetError());
    glColor3f(10.0f, 0.5f, 0.5f); //Sets the player's color
    //SDL_Log("glBegin:%i,GL_POLYGON",glGetError());
    glBlendFunc(GL_SRC_ALPHA, GL_SRC_COLOR); //
    glBegin(GL_POLYGON); // Starts the OpenGL Rendering
    //SDL_Log("%i",glGetError());
    glColor3f(0.0f, 10.0f, 10.0f); //Yet again sets the player's color
    //SDL_Log("%i",glGetError());
    glVertex3f(1.0f + Player_data->posX, 1.0f + Player_data->posY, 1.0f); //Vertex 1
    //SDL_Log("%i",glGetError());
    glVertex3f(1.0f + Player_data->posX, 0.0f + Player_data->posY, 1.0f); //Vertex 2
    glVertex3f(0.0f + Player_data->posX, 1.0f + Player_data->posY, 0.0f); //Vertex 3
    glSecondaryColor3f(0.0f, 15.0f, 0.0f); //Adds an additional color
    glColor3f(10.0f, 0.0f, 10.0f); //Change the player's color

    glVertex3f(-1.0f + Player_data->posX, -1.0f + Player_data->posY, -1.0f); //Vertex 4
    glVertex3f(-1.0f + Player_data->posX, 0.0f + Player_data->posY, -1.0f); //Vertex 5
    glVertex3f(0.0f + Player_data->posX, -1.0f + Player_data->posY, 0.0f); //Vertex 6
    glColor3f(0.0f, 0.0, 10.0f); //Set the color of something

    glEnd(); //Ends OpenGL rendering
} //Use The 'OLD Code' Rendering code
void Player_NewDraw(){
     //glViewport(0, 0, 640, 480);
        glBegin(GL_POLYGON);
	glColor3f(0.0f, 10.0f, 10.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glSecondaryColor3f(0.0f, 15.0f, 0.0f);
	glColor3f(10.0f, 0.0f, 10.0f);

	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);

	glColor3f(0.0f, 0.0, 10.0f);

	glEnd();
}
void Player_draw()
{
	//printf("Current_window:%i", Current_window);
	switch(Current_window){
	    case GL:
	        SDL_Log("Current window type:%i",Current_window);
            //glEnable(GL_DEPTH_TEST);
            //glEnable(GL_2D);
            SDL_Log("glEnable:%i,GL_2D",glGetError());
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    //glColor3f(0.0f,25.0f,0.0f);
    //glBegin(GL_QUADS);

    //glVertex2f(CollisionMax,0.0f);
    //glVertex2f(CollisionMin,0.0f);
    //glEnd();

/*#ifdef __OLD_CODE
    glEnable(GL_BLEND);
            glEnable(GL_DEBUG_OUTPUT);
    //	SDL_Log("glEnable:%i,GL_BLEND",glGetError());
    glEnable(GL_FOG);
    //	SDL_Log("glEnable:%i,GL_FOG",glGetError());
    //glFogiv(GL_FOG_MODE, GL_LINEAR);
    //glFogiv(GL_FOG_DENSITY, 3);
    //glFogiv(GL_FOG_COLOR, 0, 1, 2);
    //glViewport(0, 0, width, height);
    //glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, GL_AMBIENT);
    //glTranslatef(0.5f, 0.0f, 0.0f);

    //glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_CONSTANT_COLOR);
    //SDL_Log("glScaleF:%i,1.0f,1.0f,1.0f",glGetError());
    glScalef(1.0f, 1.0f, 1.0f);
    //SDL_Log("glColor3f:%i,10.0f,0.5f,0.5f",glGetError());
    glColor3f(10.0f, 0.5f, 0.5f);
    //SDL_Log("glBegin:%i,GL_POLYGON",glGetError());
    glBlendFunc(GL_SRC_ALPHA, GL_SRC_COLOR);
    glBegin(GL_POLYGON);
    //SDL_Log("%i",glGetError());
    glColor3f(0.0f, 10.0f, 10.0f);
    //SDL_Log("%i",glGetError());
    glVertex3f(1.0f + Player_data->posX, 1.0f + Player_data->posY, 1.0f);
    //SDL_Log("%i",glGetError());
    glVertex3f(1.0f + Player_data->posX, 0.0f + Player_data->posY, 1.0f);
    glVertex3f(0.0f + Player_data->posX, 1.0f + Player_data->posY, 0.0f);
    glSecondaryColor3f(0.0f, 15.0f, 0.0f);
    glColor3f(10.0f, 0.0f, 10.0f);

    glVertex3f(-1.0f + Player_data->posX, -1.0f + Player_data->posY, -1.0f);
    glVertex3f(-1.0f + Player_data->posX, 0.0f + Player_data->posY, -1.0f);
    glVertex3f(0.0f + Player_data->posX, -1.0f + Player_data->posY, 0.0f);
    glColor3f(0.0f, 0.0, 10.0f);

    glEnd();

#endif
#ifdef _NEW_CODE
    glViewport(0, 0, 640, 480);
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 10.0f, 10.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glSecondaryColor3f(0.0f, 15.0f, 0.0f);
	glColor3f(10.0f, 0.0f, 10.0f);

	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);

	glColor3f(0.0f, 0.0, 10.0f);

	glEnd();
#endif*/
if(GLCodeVer == 1){
    Player_OldDraw();
}else{
    Player_NewDraw();
}
    //glBlendColor(1, 1, 10, 0);
    //glBlendFunc(GL_SRC_ALPHA, GL_SRC_COLOR);
	        break;

	//if (Current_window == GL) {

	//}
        case SDL:

            //SDL_RenderFillRect(SDL_renderer,&Entity_Plr_spr);
            //SDL_RenderDrawPoint(SDL_renderer,Entity_Plr_spr.x,Entity_Plr_spr.y);

            SDL_RenderCopy(SDL_renderer, Player_Sprite_tex,&Entity_Plr_spr, NULL);
            //SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Project","Failed to render the player!",SDL_window);

           // SDL_RenderDrawRect(SDL_renderer, &Entity_Plr_spr);
            break;
            #ifdef defined(_WIN32) || defined(WIN32)
        case GDI:
            GDI_CreateWin();
            break;
        case DIRECTX:
            break;
            #endif
        case NONE:
            printf("No window specified");
            break;
        case LUA:
            //lua_State* st = Get_Lua_State();
            //printf("LuaStatePointer:%i", &st);

            luaL_dofile(Get_Lua_State(), "scripts/player_draw.lua");
            break;
	    default:
	        printf("Invalid Window Specified!");
	        break;
    }

}

void Player_redraw()
{
	Player_draw();
}

void Player_draw_inventory()
{
}

void Player_redraw_inventory()
{
}

void Player_set_item_in_slot(Item item, Slot slot)
{
	slot.item = item;
}

void Player_set_item_in_inventory(Item item)
{
	for(int i = 0; i < 25; i++)
	{
		inventory[i].item = item;
	}
}

void Player_create_inventory()
{
	for (int i = 0; i < 25;  i++)
	{
		Item Player_Blank_Slot = {"(null)","(null)",0,0,NULL};

		Player_set_item_in_slot(Player_Blank_Slot, inventory[i]);
			//Player_set_item_in_slot(null_item, inventory[i]);

	}
}
void Player_CollisionCheck(){
    collision = c2AABBtoAABB(bb,bb2);
    if(collision){
        Collided = true;
       // printf("test");
    }
}
