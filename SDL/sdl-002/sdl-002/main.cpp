#include <SDL.h>
#include "Game.h"
#include <stdio.h>
Game* game=0;
int main(int argc, char* argv[])
{
	game = new Game();
	game->init("002 - SDL eee",100,100,640,480,0);
	while(game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clean();
	return 0;
}