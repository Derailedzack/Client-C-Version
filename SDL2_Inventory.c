//
// Created by admin on 10/23/2020.
//

#include "SDL2_Inventory.h"
void SDL2_DrawInventory(Slot* inventory){
   // SDL_RenderDrawRectsF()
}
void SDL2_GL_DrawInventory(Slot* inventory){
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.5f,0.4f);
    glVertex3f(1.0f,1.0f,1.0f);
    glVertex3f(-1.0f,1.0f,1.0f);
    glVertex3f(-1.0f,1.0f,-1.0f);
    glVertex3f(1.0f,-1.0f,-1.0f);
    glEnd();
}