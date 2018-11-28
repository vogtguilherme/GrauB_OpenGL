#include "Scene.h"

Scene game;

void runMainLoop(int val);

void Desenha(void)
{
	// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glColor3f(0.0f, 0.0f, 1.0f);

	// Desenha uma esfera sólida
	//glutSolidSphere(50.0f, 100, 100);

	game.Pecas.criaMar();
	game.Pecas.CriaParedes();

	/*
	glRotatef(cubeAngle, cubeX, cubeY, cubeZ);
	glTranslatef(moveX, moveY, moveZ);
	glutSolidCube(50);
	*/

	for (int i = 0; i < 5; i++)
	{
		game.IA[i].DesenhaInimigo();
	}

	for (int i = 0; i < 10; i++)
	{
		game.bullets[i].DesenhaBullet();
	}

	for (int i = 0; i < 3; i++)
	{
		game.fuel[i].DesenhaFuel();

	}

	game.jogador.Desenhajogador();

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
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN)
		{
			for (int i = 0; i < 10; i++)
			{
				if (game.bullets[i].usada == false)
				{
					game.bullets[i].CriaBullet(game.jogador.x, game.jogador.y, game.jogador.z - 10);
					game.bullets[i].usada = true;

					std::cout << "Taca Fogo";

					break;
				}
			}
		}
}

void GerenciaTeclas(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		if (game.jogador.x > -39) game.jogador.Movimenta(-1);
		break;
	case 'd':
		if (game.jogador.x < 39) game.jogador.Movimenta(1);
		break;
	}

	glutPostRedisplay();
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
	//game.Update();

	std::cout << "FPS: " << game.FPS << std::endl;

	game.Playing();

	glutTimerFunc(1000 / game.FPS, runMainLoop, val);
}