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

	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutKeyboardFunc(GerenciaTeclas);

	/*glutDisplayFunc(game.Render);	
	glutReshapeFunc(game.SetWindowSize);	
	glutMouseFunc(game.GetMouseInput);	
	glutKeyboardFunc(game.GetKeyboardInput);*/

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

void Desenha()
{
	// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glColor3f(0.0f, 0.0f, 1.0f);

	// Desenha uma esfera sólida
	//glutSolidSphere(50.0f, 100, 100);

	Pecas.criaMar();
	Pecas.CriaParedes();

	/*
	glRotatef(cubeAngle, cubeX, cubeY, cubeZ);
	glTranslatef(moveX, moveY, moveZ);
	glutSolidCube(50);
	*/

	for (int i = 0; i < 5; i++)
	{
		IA[i].DesenhaInimigo();
	}

	for (int i = 0; i < 10; i++)
	{
		bullets[i].DesenhaBullet();
	}

	for (int i = 0; i < 3; i++)
	{
		fuel[i].DesenhaFuel();

	}

	jogador.Desenhajogador();

	/*EscreveVidas();
	EscreveKills();
	EscreveFuel();*/

	glutSwapBuffers();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if (h == 0) h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	game.fAspect = (GLfloat)w / (GLfloat)h;

	game.SpecifyViewParameters();
}

void GerenciaMouse(int button, int state, int x, int y)
{

}

void GerenciaTeclas(unsigned char key, int x, int y)
{

}