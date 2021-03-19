#include "Window.h"
/*SetCurrentWindowType and GetCurrentWindowType no longer have a function prototype in the header*/
//void SetCurrentWindowType()
//{
//}
//WINDOW_TYPE GetCurrentWindowType(WINDOW_TYPE win_type)
//{

	//return false;
//}
//void CreateWindow(Create_Window_Func* create_window)
//{
//	(create_window)(WINDOW_WIDTH,WINDOW_HEIGHT);
//}

void RenderLoop(RenderLoop_func* renderloop)
{
	(renderloop)();
}

//void DestroyWindow(Destroy_Window_func* destroywindow)
//{
//	(destroywindow)();
//}

void OnRenderingFinished(OnRenderingFinished_func* onrenderingfinished)
{
	(onrenderingfinished)();
}

void OnRenderingFailure(OnRenderingFailure_func* onrenderingfailure)
{
	(onrenderingfailure)();
}

void Tick()
{
}
