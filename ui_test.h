#ifndef UI_TEST_H_INCLUDED
#define UI_TEST_H_INCLUDED

//#define NK_IMPLEMENTATION
//#include"nuklear.h"
void UITest_Draw();
void UITest_Render();
//TODO:Figure out if I need to move these function prototype declarations to some other file
void UITest_Draw_GL();
void UITest_Render_GL();

void UITest_Draw_GDI();
void RenderUITest_GDI();

#endif // UI_TEST_H_INCLUDED
