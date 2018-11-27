#include "Jogador.h"



void Jogador::Desenhajogador()
{
	glPushMatrix();
	glTranslatef(0.0f + x, 0.0f + y, 0.0f + z);
	glScalef(3, 3, 3);
	glColor3f(0.7, 0.13, 0.13);
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.26, 0.13);				glVertex3f(0.0f, 0.0f, -5.0f); //cores e verteces
	glColor3f(0.7, 0.13, 0.26);				glVertex3f(-1.0f, 1.0f, 0.0f); //cores e verteces
	glColor3f(0.7, 0.13, 0.13);				glVertex3f(1.0f, 1.0f, 0.0f); //cores e verteces
	glColor3f(0.15, 0.13, 0.13);			glVertex3f(1.0f, -1.0f, 0.0f); //cores e verteces
	glColor3f(0.7, 0.25, 0.13);				glVertex3f(-1.0f, -1.0f, 0.0f); //cores e verteces
	glColor3f(1.0, 0.13, 0.13);				glVertex3f(-1.0f, 1.0f, 0.0f); //cores e verteces
	glEnd();
	glPopMatrix();



}

void Jogador::Movimenta(float _x)
{
	x += _x;
}

void Jogador::CriaPlayer(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Jogador::Jogador()
{
}


Jogador::~Jogador()
{
}
