#include<SDL.h>

#include "Game.h"


Game* g_gmae = 0;


int main(int argc, char* argv[])
{
	g_gmae = new Game();
	g_gmae->init("Chapter5", 100, 100, 640, 480, false);

	while (g_gmae->running())
	{
		g_gmae->handleEvents();
		g_gmae->update();
		g_gmae->render();

	}

	g_gmae->clean();
	return 0;
}