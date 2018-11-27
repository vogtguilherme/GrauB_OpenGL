#include "Inimigo.h"

void Inimigo::CriaInimigo(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Inimigo::DesenhaInimigo()
{
	/*glPushMatrix();
	glTranslatef(x, y, z);
	glColor3f(0, 255, 169);
	glutSolidCube(20);
	glPopMatrix();*/

	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(45, x, y, z);
	glScalef(8, 8, 8);
	//helice
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.1f, 0.5f, 0.5);
	glVertex3f(0.1f, 0.7f, 0.5);
	glVertex3f(1.0f, 0.7f, 0.5);
	glVertex3f(1.0f, 0.5f, 0.5);
	glEnd();

	//tronco
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.3f, 0.5);
	glVertex3f(0.5f, 0.5f, 0.5);
	glVertex3f(0.6f, 0.5f, 0.5);
	glVertex3f(0.6f, 0.3f, 0.5);
	glEnd();

	//corpo
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.3f, 0.1f, 0.5);
	glVertex3f(0.3f, 0.3f, 0.5);
	glVertex3f(1.0f, 0.3f, 0.5);
	glVertex3f(1.0f, 0.1f, 0.5);
	glVertex3f(0.8f, 0.1f, 0.5);
	glVertex3f(0.7f, 0.0f, 0.5);
	glVertex3f(0.4f, 0.0f, 0.5);
	glVertex3f(0.3f, 0.1f, 0.5);
	glEnd();
	glPopMatrix();
}

void Inimigo::Movimento(float _x, float _z)
{

	x += _x;
	z += _z;

	/*glPushMatrix();
	glTranslatef(x, y, z);
	glColor3f(0, 255, 169);
	glutSolidCube(20);
	glPopMatrix();*/

	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(45, x, y, z);
	glScalef(8, 8, 8);
	//helice
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.1f, 0.5f, 0.5);
	glVertex3f(0.1f, 0.7f, 0.5);
	glVertex3f(1.0f, 0.7f, 0.5);
	glVertex3f(1.0f, 0.5f, 0.5);
	glEnd();

	//tronco
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.3f, 0.5);
	glVertex3f(0.5f, 0.5f, 0.5);
	glVertex3f(0.6f, 0.5f, 0.5);
	glVertex3f(0.6f, 0.3f, 0.5);
	glEnd();

	//corpo
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.3f, 0.1f, 0.5);
	glVertex3f(0.3f, 0.3f, 0.5);
	glVertex3f(1.0f, 0.3f, 0.5);
	glVertex3f(1.0f, 0.1f, 0.5);
	glVertex3f(0.8f, 0.1f, 0.5);
	glVertex3f(0.7f, 0.0f, 0.5);
	glVertex3f(0.4f, 0.0f, 0.5);
	glVertex3f(0.3f, 0.1f, 0.5);
	glEnd();
	glPopMatrix();
}

Inimigo::Inimigo()
{
}


Inimigo::~Inimigo()
{
}
