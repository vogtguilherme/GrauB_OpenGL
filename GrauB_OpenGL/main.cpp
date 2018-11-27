#include "Scene.h"

Scene game;

void runMainLoop(int val);

int main(int argc, char **argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(900, 600);

	glutCreateWindow("River Raid 3D");

	//glutDisplayFunc(Desenha);
	glutDisplayFunc(game.Render);

	//glutReshapeFunc(AlteraTamanhoJanela);
	glutReshapeFunc(game.SetWindowSize);

	//glutMouseFunc(GerenciaMouse);
	glutMouseFunc(game.GetMouseInput);

	//glutKeyboardFunc(GerenciaTeclas);
	glutKeyboardFunc(game.GetKeyboardInput);

	game.Start();

	//Set main loop
	glutTimerFunc(1000 / game.FPS, runMainLoop, 0);

	glutMainLoop();
}

void runMainLoop(int val)
{
	game.Update();

	glutTimerFunc(1000 / game.FPS, runMainLoop, val);
}