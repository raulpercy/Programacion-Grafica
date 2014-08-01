#include <SDL.h>
#ifndef __Game__
#define __Game__
class Game
{
	public:
			
	Game(){}
	~Game(){}
	//Simplemente ajustamos la variable en_ejecucion a true
	bool init(const char* titulo, int posx,int posy,int alto, int ancho,int banderas);
	void render();
	void eventos();
	void limpiar();
	//una funcion para acceder a la variable privada en_ejecucion
	bool ejecucion()
	{
			return en_ejecucion;
	}

	private:
		bool en_ejecucion;
		SDL_Window* ventana;
		SDL_Renderer* dibujador;
};
#endif	//define (__Game__)