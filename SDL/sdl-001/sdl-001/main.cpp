#include <SDL.h>
SDL_Window* g_pWindow =0;
SDL_Renderer* g_pRenderer = 0;
int main(int argc, char* args[])
{
	//iniciamos SDL
	if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
	{
		//creamos nuestra ventana
		g_pWindow = SDL_CreateWindow("001 - SDL",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN);
		//si la ventana se creo, creamos nuestro dibujador(renderer)
		if(g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow,-1,0);
		}
	}
	else
	{
		return 1; //sdl no fue iniciado
	}
	//si todo lo anterior es completado dibujamos la ventana
	//ajustamos a negro; esta funcion acepta rojo,verde,azul y alpha=transparencia
	SDL_SetRenderDrawColor(g_pRenderer,0,0,0,255);
	//limpiamos la ventana a negro
	SDL_RenderClear(g_pRenderer);
	//mostramos la ventana
	SDL_RenderPresent(g_pRenderer);
	//ajustamos el tiempo a 5 segundos
	SDL_Delay(5000);
	//limpiamos SDL
	SDL_Quit();
	return 0;
}