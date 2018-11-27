//Quais as diferenças entre luz ambiente, especular, difusa e emissiva?
//O que é SHININESS?
//O que acontece quando trocamos o parâmetro da função glShadeModel?
// Ligue apenas 1 luz por vez e descreva seus efeitos
// Faça testes e explique os efeitos das cores nas iluminações. Como as luzes interagem?
// (e.g. vermelho na ambiente + azul no objeto, amarelo na difusa + vermelho na especular)
// Até que ponto a poligonagem da esfera é impactada pela iluminação? Explique com suas palavras.
#include <gl/freeglut.h>
#include <iostream>
#include"Inimigo.h"
#include"Objetos.h"
#include"Jogador.h"
#include"Bullet.h"
#include"helicoptero.h"
GLfloat angle, fAspect;

GLfloat cubeAngle, cubeX, cubeY, cubeZ, moveX, moveY, moveZ;
Bullet Bullets[10];
Inimigo IA[5];
Objetos Pecas;
Jogador Player;
helicoptero Helecoptero[5];
bool lado = true;
float speed = 5.0f;
const int FPS = 60;

void runMainLoop(int val);

// Função callback chamada para fazer o desenho
void Desenha(void)
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


	//criacao dos barcos
	for (int i = 0; i < 5; i++)
	{
		IA[i].DesenhaInimigo();
		
	}

	//criacao dos helecopteros
	for (int i = 0; i < 5; i++)
	{
		Helecoptero[i].DesenhaHelecoptero();
	}

	
	//criação da balas
	for (int i = 0; i < 10; i++)
	{
		Bullets[i].DesenhaBullet();
	}


	Player.Desenhajogador();

	glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void Inicializa(void)
{
	GLfloat luzAmbiente[4] = { 0.2,0.2,0.2,1.0 };
	GLfloat luzDifusa[4] = { 0.7,0.7,0.7,1.0 };		 // "cor" 
	GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 };// "brilho" 
	GLfloat posicaoLuz[4] = { 0.0, 50.0, 50.0, 1.0 };

	GLfloat mat_emission[] = { 1.0, 0.0, 0.0, 1.0 };   // emisão do material

													   // Capacidade de brilho do material
	GLfloat especularidade[4] = { 1.0,1.0,1.0,1.0 };
	GLint especMaterial = 60;

	// Especifica que a cor de fundo da janela será preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);
	//glShadeModel(GL_FLAT);


	// Define emisão do material
	//glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

	// Define a refletância do material 
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);

	// Define a concentração do brilho
	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0 (total de 8 luzes [0..7])
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

	angle = 35;
	cubeAngle = 0;
	cubeX = 0;
	cubeY = 1.0;
	cubeZ = 0;
	moveX = 0;
	moveY = 0;
	moveZ = 0;

	Player.CriaPlayer(0, 0, 0);

	//criando os inimigos dentro da cena randomicamente
	for (int i = 0; i < 5; i++)
	{
		IA[i].CriaInimigo(rand() % 80 - 40, 5.0f, -1000 * (i + 1));
		IA[i].speed = 1.0f;
	}

	//criando os helecopteros dentro da cena randomicamente
	for (int i = 0; i < 5; i++)
	{
		Helecoptero[i].CriaHelecoptero(rand() % 90 - 140, 5.0f, -1000 * (i + 1));
		Helecoptero[i].speed = 1.5f;
	}

	
	//criacao das balas
	for (int i = 0; i < 10; i++)
	{
		Bullets[i].CriaBullet(0, Player.y, 1000);
		Bullets[i].usada = false;
		Bullets[i].speed = 1;
	}
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
	gluPerspective(angle, fAspect, 0.4, 3000);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo

	// Especifica posição do observador e do alvo
	gluLookAt(0, 40, 80, 0, 25, 0, 0, 10, 0);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if (h == 0) h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	fAspect = (GLfloat)w / (GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) 
		{  
			// Zoom-in
			//if (angle >= 10) angle -= 5;

			for (int i = 0; i < 10; i++)
			{
				if (Bullets[i].usada == false)
				{
					Bullets[i].CriaBullet(Player.x, Player.y, Player.z - 10);
					Bullets[i].usada = true;

					std::cout << "Taca Fogo";

					break;
				}
			}

		}	
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) 
		{  
			// Zoom-out
			//if (angle <= 130) angle += 5;
		}
	if (button == GLUT_KEY_LEFT)
	{
		if (state == GLUT_DOWN)
		{
			//IA.Movimento(+0.5f, 0.0f, 0.0f);
		}
	}
	
	//EspecificaParametrosVisualizacao();
	//glutPostRedisplay();
}

void GerenciaTeclas(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		if (Player.x > -39) Player.Movimenta(-1);
		break;
	case 'd':
		if (Player.x < 39) Player.Movimenta(1);
		break;
	}
	//std::cout << Player.x;

	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900, 600);
	glutCreateWindow("Iluminação");

	glutDisplayFunc(Desenha);

	glutReshapeFunc(AlteraTamanhoJanela);

	glutMouseFunc(GerenciaMouse);

	glutKeyboardFunc(GerenciaTeclas);

	Inicializa();

	//Set main loop
	glutTimerFunc(1000 / FPS, runMainLoop, 0);

	glutMainLoop();
}

void runMainLoop(int val)
{
	Desenha();

	//movimento dos helecopteros
	for (int i = 0; i < 5; i++)
	{
		if (Helecoptero[i].z < 100) Helecoptero[i].Movimento(0, Helecoptero[i].speed * speed);
		else
		{
			Helecoptero[i].CriaHelecoptero(rand() % 80 - 40, Helecoptero[i].y, -4000);
			if (Helecoptero[i].speed < 20) Helecoptero[i].speed += Helecoptero[i].speed * 0.1f;
		}

		if (Player.x - 1.5f < Helecoptero[i].x + 10 && Player.x + 1.5f > Helecoptero[i].x - 10)
		{
			if (Player.y - 1.5f < Helecoptero[i].y + 10 && Player.y + 1.5f > Helecoptero[i].y - 10)
			{
				if (Player.z - 1.5f < Helecoptero[i].z + 10 && Player.z + 1.5f > Helecoptero[i].z - 10)
				{
					std::cout << "BAteu Carai z";
				}
			}
		}

	
		//movimentacao dos inimigos e teste de colisao com o player
		for (int i = 0; i < 5; i++)
		{
			if (IA[i].z < 100) IA[i].Movimento(0, IA[i].speed * speed);
			else
			{
				IA[i].CriaInimigo(rand() % 80 - 40, IA[i].y, -4000);
				if (IA[i].speed < 20) IA[i].speed += IA[i].speed * 0.1f;
			}

			if (Player.x - 1.5f < IA[i].x + 10 && Player.x + 1.5f > IA[i].x - 10)
			{
				if (Player.y - 1.5f < IA[i].y + 10 && Player.y + 1.5f > IA[i].y - 10)
				{
					if (Player.z - 1.5f < IA[i].z + 10 && Player.z + 1.5f > IA[i].z - 10)
					{
						std::cout << "BAteu Carai z";
					}
				}
			}

			for (int i = 0; i < 10; i++)
			{
				if (Bullets[i].usada == true)
				{
					Bullets[i].Movimento(0, -Bullets[i].speed);

					for (int i = 0; i < 5; i++)
					{
						if (Bullets[i].x - 0.5f < IA[i].x + 10 && Bullets[i].x + 0.5f > IA[i].x - 10)
						{
							if (Bullets[i].y - 0.5f < IA[i].y + 10 && Bullets[i].y + 0.5f > IA[i].y - 10)
							{
								if (Bullets[i].z - 0.5f < IA[i].z + 10 && Bullets[i].z + 0.5f > IA[i].z - 10)
								{
									IA[i].CriaInimigo(50000, IA[i].y, IA[i].z);

									Bullets[i].CriaBullet(0, Player.y, 1000);
									Bullets[i].usada = false;
								}
							}
						}
					}
				}
			}
		}

		for (int j = 0; j < 10; j++)
		{
			if (Bullets[j].usada == true)
			{
				Bullets[j].Movimento(0, -Bullets[j].speed);

				for (int i = 0; i < 5; i++)
				{
					if (Bullets[j].x - 0.5f < IA[i].x + 10 && Bullets[j].x + 0.5f > IA[i].x - 10)
					{
						if (Bullets[j].y - 0.5f < IA[i].y + 10 && Bullets[j].y + 0.5f > IA[i].y - 10)
						{
							if (Bullets[j].z - 0.5f < IA[i].z + 10 && Bullets[j].z + 0.5f > IA[i].z - 10)
							{
								IA[i].CriaInimigo(50000, IA[i].y, IA[i].z);

								Bullets[j].CriaBullet(0, Player.y, 1000);
								Bullets[j].usada = false;
							}
						}
					}
				}
			}
		}


		/*
		if (lado == true)
		{
			if (moveX < 0)
			{
				//IA.Movimento(moveX - speed, 0.0f, 0.0f);
				Pecas.Mmovimenta(moveX - speed);
			}
			if (moveX >= 10)
			{
				lado = false;
			}
			moveX++;
			std::cout << "valor em x: " << moveX << std::endl;

			}
		if (lado == false) {
			if (moveX < 50)
			{
				// IA.Movimento(moveX - speed, 0.0, 0.0);
				Pecas.Mmovimenta(moveX - speed);
			}

			if (moveX <= -10)
			{
				lado = true;
			}
			moveX--;
			std::cout << "valor em x: " << moveX << std::endl;

		}*/



		//Frame logic
		//Update();

		//Render();
		//Run frame one more time

		glutTimerFunc(1000 / FPS, runMainLoop, val);
	}
}