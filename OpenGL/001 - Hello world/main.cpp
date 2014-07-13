#include <GL/glut.h>						//libreria glut
int main(int argc, char **argv)				
{
	glutInit(&argc,argv);					//inicio de glut
	glutCreateWindow("001 - Hello World")	//funcion para crear la ventana
	glutMainLoop();							//bucle de la funcion main
}