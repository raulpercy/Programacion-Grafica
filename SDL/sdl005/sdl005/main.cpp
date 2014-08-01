#include "Game.h"
//nuestro objeto Game
Game* game = 0;

int main(int argc, char* args[])
{
	game = new Game();

	game->init("Capitulo 1",100,100,640,480,0);
	

	while(game->ejecucion())
	{
		game->eventos();
		game->render();
	}
	//Salimos de SDL y la aplicacion
	game->limpiar();
	return 0;
}