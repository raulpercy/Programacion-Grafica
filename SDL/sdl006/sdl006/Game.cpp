#include "Game.h"
SDL_Surface* surface = SDL_LoadBMP("Homer.bmp");
bool Game::init(const char* titulo, int posx,int posy,int alto, int ancho,bool pantallacompleta)
{
	//iniciamos SDL
	
	

	if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
	{
		//si se creo la ventana correctamente creamos el dibujador (renderer)
		if(pantallacompleta)
		{
			pantallacompleta = SDL_WINDOW_FULLSCREEN;
		}
		//creamos nuestra ventana
		ventana = SDL_CreateWindow(titulo,posx,posy,ancho,alto,pantallacompleta);
		if(ventana != 0)
		{
			dibujador = SDL_CreateRenderer(ventana,-1,0);
			if(dibujador != 0)
			{
				textura = SDL_CreateTextureFromSurface(dibujador,surface);
				SDL_FreeSurface(surface);
				SDL_QueryTexture(textura,NULL,NULL,&rectangulo.w,&rectangulo.h);
				rectangulo_destino.x = rectangulo.x = 0;
				rectangulo_destino.y = rectangulo.y=0;
				rectangulo_destino.w = rectangulo.w;
				rectangulo_destino.h = rectangulo.h;
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
	SDL_RenderCopy(dibujador,textura,&rectangulo,&rectangulo_destino);
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
