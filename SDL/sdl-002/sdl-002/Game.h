#ifndef __Game__
#define __Game__
#include <stdio.h>
class Game
{
	public:
		Game(){}
		~Game(){}
		//simplemente ajustamos la variable booleana
		bool init(const char* titulo, int posx, int posy, int ancho, int alto, int flags)
		{
			if(SDL_Init(SDL_INIT_EVERYTHING)==0)
			{
				printf("SDL inicio correctamente");
				//iniciamos la ventana
				ventana = SDL_CreateWindow(titulo,posx,posy,ancho,alto,flags);
				if(ventana !=0)
				{
					printf("creacion de la ventana satisfactoriamente");
					dibujador = SDL_CreateRenderer(ventana,-1,0);
					if(dibujador != 0)
					{
						printf("creacion del dibujador satisfactoriamente");
						SDL_SetRenderDrawColor(dibujador,255,255,255,255);

					}
					else
					{
						printf("fallo al inicializar el dibujador\n");
						return false;
					}
				}
				else
				{
					printf("fallo al inicializar la ventana\n");
					return false;
				}
			}
			else
			{
				printf("fallo al inicializar SDL\n");
				return false;
			}
			printf("init correcto\n");
			ejecucion=true;
			return true;
				}
		void render()
		{
			SDL_RenderClear(dibujador);
			SDL_RenderPresent(dibujador);
		}
		void update()
		{
		}
		void handleEvents()
		{
			SDL_Event evento;
			if(SDL_PollEvent(&evento))
			{
				switch(evento.type)
				{
					case SDL_QUIT:
					{
						ejecucion=false;
						break;
					}
					default:
					{
						break;
					}
				}
			}
		}
		void clean()
		{
			printf("limpiando game\n");
			SDL_DestroyWindow(ventana);
			SDL_DestroyRenderer(dibujador);
			SDL_Quit();
		}
		//una funcion para acceder la variable booleana de tipo privada
		bool running()
		{
			return ejecucion;
		}
	private:
		SDL_Window* ventana;
		SDL_Renderer* dibujador;
		bool ejecucion;
};
#endif/* defined(__Game__)*/
