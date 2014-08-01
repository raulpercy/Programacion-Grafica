#include "Game.h"
bool Game::init(const char* titulo, int posx,int posy,int alto, int ancho,int banderas)
{
	//iniciamos SDL
	if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
	{
		//creamos nuestra ventana
		ventana = SDL_CreateWindow(titulo,posx,posy,ancho,alto,banderas);
		//si se creo la ventana correctamente creamos el dibujador (renderer)
		if(ventana != 0)
		{
			dibujador = SDL_CreateRenderer(ventana,-1,0);
			if(dibujador != 0)
			{
				SDL_SetRenderDrawColor(dibujador,255,255,255,255);
			}
		}
	}
	en_ejecucion = true;
	return true;
}
void Game::render()
{
	//limpiamos la ventana a verde
	SDL_RenderClear(dibujador);
	//mostramos la ventana
	SDL_RenderPresent(dibujador);
}
void Game::limpiar()
{
	SDL_DestroyWindow(ventana);
	SDL_DestroyRenderer(dibujador);
	SDL_Quit();
}
void Game::eventos()
{
	SDL_Event evento;
	if(SDL_PollEvent(&evento))
	{
		switch(evento.type)
		{
			case SDL_QUIT:
			{
				en_ejecucion = false;
			}
			default:
			{
				break;
			}
		}
		
	}
}
