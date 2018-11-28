#include "Scene.h"

Scene game;

void runMainLoop(int val);

void Desenha(void)
{
	game.Render();

	glutSwapBuffers();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	game.SetWindowSize(w, h);
}

void GerenciaMouse(int button, int state, int x, int y)
{
	game.GetMouseInput(button, state, x, y);
}

void GerenciaTeclas(unsigned char key, int x, int y)
{
	game.GetKeyboardInput(key, x, y);
}

void GerenciaTeclasEspeciais(int key, int x, int y)
{
	game.GetSpecialKeyboardInput(key, x, y);
}

void Inicializa(void)
{
	game.Start();
}

int main(int argc, char **argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(900, 600);

	glutCreateWindow("River Raid 3D");

	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutKeyboardFunc(GerenciaTeclas);
	glutSpecialFunc(GerenciaTeclasEspeciais);

	Inicializa();
		
	glutTimerFunc(1000 / game.FPS, runMainLoop, 0);

	glutMainLoop();
}

void runMainLoop(int val)
{
	Desenha();

	game.Update();

	glutTimerFunc(1000 / game.FPS, runMainLoop, val);
}