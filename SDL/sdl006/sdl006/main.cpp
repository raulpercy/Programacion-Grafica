#include "Game.h"
//nuestro objeto Game
Game* game = 0;

int main(int argc, char* args[])
{
	game = new Game();

	game->init("Capitulo 2-001",100,100,800,800,0);
	

	while(game->ejecucion())
	{
		game->eventos();
		game->render();
	}
	//Salimos de SDL y la aplicacion
	game->limpiar();
	return 0;
}