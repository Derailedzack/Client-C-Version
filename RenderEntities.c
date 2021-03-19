#include "RenderEntities.h"

void RenderALLEntities()
{
	Collision_draw();

	Player_draw();
}

void UpdateALLEntities()
{

	Collision_redraw();
	//

	Player_redraw();
	Player_CollisionCheck();
}
