/*
 * EntityCollisionTest.h
 *
 *  Created on: Aug 3, 2020
 *      Author: admin
 */

#ifndef ENTITYCOLLISIONTEST_H_
#define ENTITYCOLLISIONTEST_H_
#include"Entity.h"
#include"Player.h"
#include"cute_c2.h"
#ifdef HAVE_GLAD_H
#include<glad\glad.h>
#else
#undef __gl_h_
#include<GL/glew.h>
#endif
c2AABB bb2;
EntityData* Collision_Entity_Data;
void Collsion_init();
void Collision_draw();
void Collision_redraw();

bool CollisionTest_Func(EntityData* entity1,EntityData* entity2);

#endif /* ENTITYCOLLISIONTEST_H_ */
