/*
 * EntityCollisionTest.c
 *
 *  Created on: Aug 3, 2020
 *      Author: admin
 */

#include"EntityCollisionTest.h"
#define CUTE_C2_IMPLEMENTATION
#include"cute_c2.h"

void Collsion_init(){

    bb2.max = c2V(16.0,0.0f);
    bb2.min = c2V(-16.0,0.0f);
	Collision_Entity_Data = malloc(sizeof(EntityData));
	Collision_Entity_Data->Entity_ID = 1;
	Collision_Entity_Data->posX = 1.0f;
	Collision_Entity_Data->posY = -1.0f;
	Collision_Entity_Data->Entity_Size.height = 32;
	Collision_Entity_Data->Entity_Size.width = 32;
}
void Collision_draw(){
    if(Current_window == GL){

    glRectf(2.0f,0.0f,-4.0f,0.0f);

glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.25f + Collision_Entity_Data->posX,0.25f + Collision_Entity_Data->posY,0.25f);
    glVertex3f(-0.25 + Collision_Entity_Data->posX,0.25f + Collision_Entity_Data->posY,0.25f);
    glVertex3f(-0.25f + Collision_Entity_Data->posX,-0.25f + Collision_Entity_Data->posY,-0.25f);
    glSecondaryColor3f(9.0f,2.0f,1.0f);
    glVertex3f(0.25f + Collision_Entity_Data->posX,-0.25f + Collision_Entity_Data->posY,0.25f);
    glVertex3f(0.25f + Collision_Entity_Data->posX,0.25f + Collision_Entity_Data->posY,-0.25f);
      glRotatef(0.0f + 10.0f,0.25f + Collision_Entity_Data->posX,-0.25f + Collision_Entity_Data->posY,0.0f);

//glVertex3f(0.5f,-0.5f,0.5f);
glEnd();
/*glBegin(GL_POLYGON);
glColor3f(1.0f,1.0f,1.0f);
glVertex3f(2.0f,2.0f,2.0f);
glVertex3f(-2.0f,2.0f,2.0f);
glVertex3f(-2.0f,2.0f,-2.0f);
glVertex3f(-2.0f,0.0f,-2.0f);

glVertex3f(0.25f,0.25f,0.25f);
glVertex3f(-0.25f,0.0f,0.25f);
glVertex3f(-0.25f,0.25f,-0.25f);
glVertex3f(-0.25f,-0.25f,-0.25f);
glVertex3f(1.0f,1.0f,1.0f);
glEnd();*/
    }else if(Current_window == SDL){

    }
}
void Collision_redraw(){
	Collision_draw();
}
bool CollisionTest_Func(EntityData* entity1,EntityData* entity2){
    if(entity1 == NULL && entity2 == NULL){
        return false;
    }
  //  if(entity1->Entity_BB == NULL && entity2->Entity_BB){
    //    return false;
   // }else{
         int collision = c2AABBtoAABB(entity1->Entity_BB,entity2->Entity_BB);
    if(collision){
        return true;
    }
   // }

    return false;
}
