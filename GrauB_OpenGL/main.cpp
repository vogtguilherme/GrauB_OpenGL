//Quais as diferen�as entre luz ambiente, especular, difusa e emissiva?
//O que � SHININESS?
//O que acontece quando trocamos o par�metro da fun��o glShadeModel?
// Ligue apenas 1 luz por vez e descreva seus efeitos
// Fa�a testes e explique os efeitos das cores nas ilumina��es. Como as luzes interagem?
// (e.g. vermelho na ambiente + azul no objeto, amarelo na difusa + vermelho na especular)
// At� que ponto a poligonagem da esfera � impactada pela ilumina��o? Explique com suas palavras.
#include <gl/freeglut.h>
#include  <iostream>
#include "Barco.h"
#include "Objetos.h"
#include "Jogador.h"
#include "Bullet.h"
#include "Fuel.h"
#include"Helicoptero.h"

GLfloat angle, fAspect;
GLfloat cubeAngle, cubeX, cubeY, cubeZ, moveX, moveY, moveZ;


Barco IA[5];
helicoptero Coptero[5];
Bullet Bullets[10];
Objetos Pecas;
Jogador Player;
Fuel fuel[3];

bool lado = true;
float speed = 5.0f;
const int FPS = 60;

void runMainLoop(int val);

void EscreveVidas();
void EscreveKills();
void EscreveFuel();


// Fun��o callback chamada para fazer o desenho
void Desenha(void)
{
	// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//criando os objetos dentro do jogo
	Pecas.criaMar();
	Pecas.CriaParedes();
	Pecas.CriaMontanhas();
	for (int i = 0; i < 5; i++)
	{
		Coptero[i].DesenhaHelecoptero();
	}

	for (int i = 0; i < 5; i++)
	{
		IA[i].DesenhaInimigo();
	}

	for (int i = 0; i < 10; i++)
	{
		Bullets[i].DesenhaBullet();
	}

	for (int i = 0; i < 3; i++)
	{
		fuel[i].DesenhaFuel();

	}

	Player.Desenhajogador();

	EscreveVidas();
	EscreveKills();
	EscreveFuel();

	glutSwapBuffers();
}

// Inicializa par�metros de rendering
void Inicializa(void)
{
	GLfloat luzAmbiente[4] = { 0.5,0.5,0.5,1.0 };
	GLfloat luzDifusa[4] = { 0.7,0.7,0.7 };		 // "cor" 
	GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 };// "brilho" 

	// Especifica que a cor de fundo da janela ser� preta
	glClearColor(0.2f, 0.4f, 0.9f, 1.0f);
	
	// Habilita o modelo de coloriza��o de Gouraud
	glShadeModel(GL_SMOOTH);
	glShadeModel(GL_FLAT);


	// Define emis�o do material
	//glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);


	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os par�metros da luz de n�mero 0 (total de 8 luzes [0..7])
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);

	angle = 35;
	cubeAngle = 0;
	cubeX = 0;
	cubeY = 1.0;
	cubeZ = 0;
	moveX = 0;
	moveY = 0;
	moveZ = 0;


	//onde o player esta sendo inicializado e variaveis de vida,combustivel,acertos
	Player.CriaPlayer(0, 5, 0);
	Player.vidas = 3;
	Player.acertos = 0;
	Player.combustivel = 100;


	//criando os objetos aleatoriamente dentro do mapa
	for (int i = 0; i < 3; i++)
	{
		fuel[i].CriaFuel(rand() % 70 - 35, 5.0f, -1100 * (i + 1));
		fuel[i].speed = 2.0f;
		fuel[i].combustivel = 50.0f;
	}

	for (int i = 0; i < 5; i++)
	{
		IA[i].CriaInimigo(rand() % 80 - 40, 5.0f, -1000 * (i + 1));
		IA[i].speed = 1.0f;
	}

	for (int i = 0; i < 5; i++)
	{
		Coptero[i].CriaHelecoptero(rand() % 70 - 35, 5.0f, -1100 * (i + 1));
		Coptero[i].speed = 1.0f;
	}

	//criando a bala 
	for (int i = 0; i < 10; i++)
	{
		Bullets[i].CriaBullet(0, Player.y, 1000);
		Bullets[i].usada = false;
		Bullets[i].speed = 5;
	}
}

// Fun��o usada para especificar o volume de visualiza��o
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de proje��o
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de proje��o
	glLoadIdentity();

	// Especifica a proje��o perspectiva
	gluPerspective(angle, fAspect, 0.4, 3000);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Especifica posi��o do observador e do alvo
	gluLookAt(0, 40, 80, 0, 25, 0, 0, 10, 0);
}

// Fun��o callback chamada quando o tamanho da janela � alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divis�o por zero
	if (h == 0) h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);

	// Calcula a corre��o de aspecto
	fAspect = (GLfloat)w / (GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Fun��o callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) 
		{ 
			//clique do mouse e player atira
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
			
		}
	if (button == GLUT_KEY_LEFT)
	{
		if (state == GLUT_DOWN)
		{
			
		}
	}
	
}

void EscreveVidas(void)
{

	char texto[8] = "LIFES:";
	char teste[20];
	int i = 0;

	//Convers�o de inteiro para string, pois a OpenGL s� escreve string ou char
	sprintf_s(teste, "%d", Player.vidas);

	//Cor da fonte
	glColor3ub(255, 255, 255);
	glRasterPos3f(30.0f, 35.0f, -0.0f);

	//Uso do "for" para escrever mais de um caracter
	for (i = 0; i <= strlen(texto); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, texto[i]);

	for (i = 0; i <= strlen(teste); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, teste[i]);
}

void EscreveKills(void)
{
	char texto[8] = "KILLS:";
	char teste[20];
	int i = 0;

	//Convers�o de inteiro para string, pois a OpenGL s� escreve string ou char
	sprintf_s(teste, "%d", Player.acertos);

	//Cor da fonte
	glColor3ub(255, 255, 255);
	
	//Posi��o da palavra
	glRasterPos3f(30.0f, 33.5f, -0.0f);

	//Uso do "for" para escrever mais de um caracter
	for (i = 0; i <= strlen(texto); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, texto[i]);

	for (i = 0; i <= strlen(teste); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, teste[i]);
}

void EscreveFuel(void)
{
	char texto[8] = "FUEL:";
	char teste[20];
	int i = 0;

	//Convers�o de inteiro para string, pois a OpenGL s� escreve string ou char
	sprintf_s(teste, "%d", (int)Player.combustivel);

	//Cor da fonte
	glColor3ub(255, 255, 255);
	
	//Posi��o da palavra
	glRasterPos3f(30.0f, 32.0f, -0.0f);

	//Uso do "for" para escrever mais de um caracter
	for (i = 0; i <= strlen(texto); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, texto[i]);

	for (i = 0; i <= strlen(teste); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, teste[i]);
}

void GerenciaTeclas(unsigned char key, int x, int y)
{
	//movimenta��o do player
	switch (key)
	{
	case 'a':
		if (Player.x > -39) Player.Movimenta(-1);
		break;
	case 'd':
		if (Player.x < 39) Player.Movimenta(1);
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
	glutCreateWindow("Ilumina��o");

	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutKeyboardFunc(GerenciaTeclas);

	Inicializa();

	//Set main loop
	glutTimerFunc(1000 / FPS, runMainLoop, 0);

	glutMainLoop();
}


//com se fosse um update onde vai verificar todo momento 
void runMainLoop(int val)
{
	Desenha();

	//decrementando o combustivel
	Player.combustivel -= (100.0f / 30.0f) / 60.0f;

	//coptero
	for (int i = 0; i < 5; i++)
	{
		if (Coptero[i].z < 100)Coptero[i].Movimento(0, Coptero[i].speed*speed);
		else
		{
			Coptero[i].CriaHelecoptero(rand() % 80 - 60, Coptero[i].y , -3000);
			if (Coptero[i].speed < 20)Coptero[i].speed += Coptero[i].speed*0.2f;
		}

		//sistema de colisao do player com o objeto
		if (Player.x - 1.5f < Coptero[i].x + 10 && Player.x + 1.5f > Coptero[i].x - 10)
		{
			if (Player.y - 1.5f < Coptero[i].y + 10 && Player.y + 1.5f > Coptero[i].y - 10)
			{
				if (Player.z - 1.5f < Coptero[i].z + 10 && Player.z + 1.5f > Coptero[i].z - 10)
				{
					std::cout << "BAteu Carai z";

					Coptero[i].CriaHelecoptero(40000, Coptero[i].y, Coptero[i].z);

					Player.vidas--;
				}
			}
		}
	}

	//barquinho
	for (int i = 0; i < 5; i++)
	{
		if (IA[i].z < 100) IA[i].Movimento(0, IA[i].speed * speed);
		else
		{
			IA[i].CriaInimigo(rand() % 80 - 40, IA[i].y, -4000);
			if (IA[i].speed < 20) IA[i].speed += IA[i].speed * 0.1f;
		}
//colisao do player com o objeto barquinho
		if (Player.x - 1.5f < IA[i].x + 10 && Player.x + 1.5f > IA[i].x - 10)
		{
			if (Player.y - 1.5f < IA[i].y + 10 && Player.y + 1.5f > IA[i].y - 10)
			{
				if (Player.z - 1.5f < IA[i].z + 10 && Player.z + 1.5f > IA[i].z - 10)
				{
					IA[i].CriaInimigo(50000, IA[i].y, IA[i].z);

					Player.vidas--;
				}
			}
		}
	}
	//gasolina
	for (int i = 0; i < 3; i++)
	{
		fuel[i].Movimenta(0, fuel[i].speed);

		if(fuel[i].z > 100) fuel[i].CriaFuel(rand() % 70 - 35, fuel[i].y, -4000);

		//colisao do player com o combustivel
		if (Player.x - 1.5f < fuel[i].x + 10 && Player.x + 1.5f > fuel[i].x - 10)
		{
			if (Player.y - 1.5f < fuel[i].y + 10 && Player.y + 1.5f > fuel[i].y - 10)
			{
				if (Player.z - 1.5f < fuel[i].z + 10 && Player.z + 1.5f > fuel[i].z - 10)
				{
					if(Player.combustivel + fuel[i].combustivel < 100) Player.combustivel += fuel[i].combustivel;
					else Player.combustivel = 100;

					fuel[i].CriaFuel(50000, fuel[i].y, fuel[i].x);
				}
			}
		}
	}

	//bala
	for (int j = 0; j < 10; j++)
	{
		if (Bullets[j].usada == true)
		{
			Bullets[j].Movimento(0, -Bullets[j].speed);

			if (Bullets[j].z < -2000)
			{
				Bullets[j].CriaBullet(0, Player.y, 1000);
				Bullets[j].usada = false;
			}

			//colisor da bala com o barco
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

							Player.acertos++;
						}
					}
				}
			}

			//colisor da bala no coptero
			for (int i = 0; i < 5; i++)
			{
				if (Bullets[j].x - 0.5f < Coptero[i].x + 10 && Bullets[j].x + 0.5f > Coptero[i].x - 10)
				{
					if (Bullets[j].y - 0.5f < Coptero[i].y + 10 && Bullets[j].y + 0.5f > Coptero[i].y - 10)
					{
						if (Bullets[j].z - 0.5f < Coptero[i].z + 10 && Bullets[j].z + 0.5f > Coptero[i].z - 10)
						{
							Coptero[i].CriaHelecoptero(50000, Coptero[i].y, Coptero[i].z);

							Bullets[j].CriaBullet(0, Player.y, 1000);
							Bullets[j].usada = false;

							Player.acertos++;
						}
					}
				}
			}

		}
	}


	
	//Frame logic
	//Update();

	//Render();
	//Run frame one more time

	glutTimerFunc(1000 / FPS, runMainLoop, val);
}