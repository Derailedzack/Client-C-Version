#pragma once
#include"Entity.h"
#include"Window.h"
#include "SDL2_Window.h"
#include"Inventory.h"
#include<stdio.h>
#include"LuaUtils.h"
#ifdef HAVE_GLAD_H
#include<glad/glad.h>
#else
#undef __gl_h_
#include<gl/glew.h>
#endif
#include <stdlib.h>
#include"Client_log.h"
#include"EntityCollisionTest.h"
#include "cute_c2.h"

#define CUTE_C2_IMPLEMENTATION
EntityData* Player_data;
//Fixme:Player rendering in lua
//Note:Don't forget to call Player_init otherwise an access violation will occur
//Item null_item = { "","",0,0,0 };
c2AABB bb;
bool Collided;
Slot inventory[26];

void Player_init(); //Initialize Player Veriables
void Player_draw(); //Initial Render of the Player
void Player_Special_init();
void Player_OldDraw(); //Use The 'OLD Code' Rendering code
void Player_NewDraw(); //Use the 'New Code' Rendering code
void Player_redraw(); //Rerender the player
void Player_draw_inventory(); //Draw the player's inventory
void Player_redraw_inventory(); //Rerender the player's inventory
void Player_set_item_in_slot(Item item, Slot slot); //Set a item in a specific slot
void Player_set_item_in_inventory(Item item); //Set a item in the inventory
void Player_create_inventory(); //Create the player's inventory
void Player_CollisionCheck(); //Check if a collision has occured between the player and another entity
