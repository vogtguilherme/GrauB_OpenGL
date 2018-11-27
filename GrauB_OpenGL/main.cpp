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
GLfloat angle, fAspect;

GLfloat cubeAngle, cubeX, cubeY, cubeZ, moveX,moveY ,moveZ;

Inimigo IA;
Objetos Pecas;
Jogador Player;
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

	IA.DesenhaInimigo();
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

	IA.CriaInimigo(0, 5.0f, -50);
	IA.speed = 0.1f;

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
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}
	if (button == GLUT_KEY_LEFT)
	{
		if (state == GLUT_DOWN)
		{
			//IA.Movimento(+0.5f, 0.0f, 0.0f);
		}
	}


	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

void GerenciaTeclas(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		if(Player.x > -40) Player.Movimenta(-1);
		break;
	case 'd':
		if(Player.x < 20) Player.Movimenta(1);
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

	//glutMouseFunc(GerenciaMouse);

	glutKeyboardFunc(GerenciaTeclas);

	Inicializa();

	//Set main loop
	glutTimerFunc(1000 / FPS, runMainLoop, 0);

	glutMainLoop();
}

void runMainLoop(int val)
{
	Desenha();

	if(IA.z < 100) IA.Movimento(0, IA.speed * speed);
	else
	{
		IA.CriaInimigo(0, 1.3f, -4000);
		if(IA.speed < 20) IA.speed += IA.speed * 0.2f;
	}

	if (Player.x - 0.1f < IA.x + 10 && Player.x + 0.1f > IA.x - 10)
	{
		if (Player.y - 0.1f < IA.y + 10 && Player.y + 0.1f > IA.y - 10)
		{
			if (Player.z - 0.1f > IA.z + 10 && Player.z + 0.1f < IA.z - 10)
			{
				std::cout << "BAteu Carai z";
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