#include <GL\freeglut.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <iostream>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include"Agua.h"
#include"Player.h"
#endif

float rotate_y = 160;
float rotate_x = -20;
GLfloat xRotated, yRotated, zRotated;
GLfloat angle, fAspect, stepX, stepY, stepZ;
Player jogador;
Agua mar;


void specialKeys();

void redisplayFunc(void)
{
	// limpa o bufffer de desenho
	glClear(GL_COLOR_BUFFER_BIT);
	// limpa a matriz identidade
	
	glLoadIdentity();

	// Rotaciona quando o usuário muda rotate_x e rotate_y
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);





	//// traslada o desenho para z = -5.0
	//glTranslatef(0.0, 0.0, -5.0);
	//// Define a cor do desenho
	//glColor3f(0.0, 0.5, 0.0);
	//// Mudanças na matriz de transformação
	//// rotação sobre o eixo X
	//glRotatef(xRotated, 1.0, 0.0, 0.0);
	//// rotação sobre o eixo Y
	//glRotatef(yRotated, 0.0, 1.0, 0.0);
	//// rotação sobre o eixo Z
	//glRotatef(zRotated, 0.0, 0.0, 1.0);
	//// Definição de escala
	//glScalef(1.0, 1.0, 1.0);

	jogador.DesenhaPlayer();
	mar.DesenhaAgua();





	// Função própria da glut para desenho de primitivas 3d
	//glutSolidTeapot(1);
	//void glutWireCube(GLdouble size);
	//void glutWireSphere(GLdouble radius, GLint slices, GLint stacks);
	//void glutWireCone(GLdouble radius, GLdouble height, GLint slices, GLint stacks);
	//void glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings);
	//void glutWireIcosahedron(void);
	//void glutWireOctahedron(void);
	//void glutWireTetrahedron(void);
	//void glutWireDodecahedron(GLdouble radius);

	// Esvazia o buffer na tela
	glFlush();
	// troca o buffer pois estamos usando double buffering 
	glutSwapBuffers();
	char ddd[10];

	printf("x: |%f| e y: |%f| \n", rotate_x, rotate_y);
}


// Especificação do volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);

	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
	gluPerspective(angle, fAspect, 0.1, 500);

	/*	Esta função estabelece os parâmetros da Projeção Perspectiva,
	atualizando a matriz de projeção perspectiva.
	Seu protótipo é:
	void gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar);
	Descrição dos parâmetros:
	1) fovy é o ângulo, em graus, na direção y (usada para determinar a
	"altura" do volume de visualização);
	2) aspect é a razão de aspecto que determina a área de visualização
	na direção x, e seu valor é a razão em x(largura) e y(altura);
	3) zNear, que sempre deve ter um valor positivo maior do que zero,
	é a distância do observador até o plano de corte mais próximo(em z);
	4) zFar, que também sempre tem um valor positivo maior do que zero,
	é a distância do observador até o plano de corte mais afastado(em z).
	Esta função sempre deve ser definida ANTES da função gluLookAt, e no modo GL_PROJECTION  */

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);

	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
	gluLookAt(0, 80, 200, 0, 0, 0, 0, 1, 0);

	/*Descrição dos parâmetros:
	1) eyex, eyey e eyez são usados para definir as
	coordenadas x, y e z, respectivamente, da posição
	da câmera(ou observador);
	2) centerx, centery e centerz são usados para
	definir as coordenadas x, y e z, respectivamente,
	da posição do alvo, isto é, para onde o
	observador está olhando  (normalmente, o centro da cena);
	3) upx, upy e upz são as coordenadas x, y e z,
	que estabelecem o vetor up(indica o
	"lado de cima" de uma cena 3D)*/
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

// Função callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x, int y)
{
	switch (key) {
	case 'a':
		stepX = 0.3;
		stepY = 0;
		stepZ = 0;
		break;
	case 's':
		stepX = 0;
		stepY = 0.3;
		stepZ = 0;
		break;
	case 'd':
		stepX = 0;
		stepY = 0;
		stepZ = 0.3;
		break;
	}
	redisplayFunc();
	glutPostRedisplay();
}

void idleFunc(void)
{
	// rotation around x axis 
	xRotated += stepX;
	yRotated += stepY;
	zRotated += stepZ;
}


// Inicializa parâmetros de rendering
void Inicializa(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	angle = 45;
	stepX = stepY = stepZ = 0;
}

void specialKeys(int key, int x, int y) {

	//  Seta direita - aumenta rotação em 5 graus
	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;

	//  Seta para esquerda - diminui a rotação por 5 graus
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;


	else if (key == GLUT_KEY_UP)
		rotate_x += 5;

	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;

	//  Requisitar atualização do display
	glutPostRedisplay();
}

// Função callback chamada para gerenciar eventos do mouse
//void GerenciaMouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON)
//		if (state == GLUT_DOWN) {  // Zoom-in
//			if (angle >= 10) angle -= 5;
//		}
//	if (button == GLUT_RIGHT_BUTTON)
//		if (state == GLUT_DOWN) {  // Zoom-out
//			if (angle <= 130) angle += 5;
//		}
//	EspecificaParametrosVisualizacao();
//	glutPostRedisplay();
//}

int main(int argc, char **argv)
{
	//Initializa a GLUT
	glutInit(&argc, argv);
	//double buffering utilizado para evitar o probema de flick da animação
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	// Inicializa a janela
	glutInitWindowSize(800, 600);

	// Cria a janela
	glutCreateWindow("3D animation");
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glPolygonMode(GL_FRONT_AND_BACK, GLU_FILL);

	xRotated = yRotated = zRotated = 0.0;

	glClearColor(0.0, 0.0, 0.0, 0.0);
	//Atribui as funções utilizados aos eventos
	glutDisplayFunc(redisplayFunc);
	glutSpecialFunc(specialKeys);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutKeyboardFunc(GerenciaTeclado);
	//glutMouseFunc(GerenciaMouse);

	Inicializa();
	glutIdleFunc(idleFunc);

	// Inicia o loop da glut
	glutMainLoop();
	return 0;
}