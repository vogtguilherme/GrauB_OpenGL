#include "Inimigo.h"

void Inimigo::CriaInimigo(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Inimigo::DesenhaInimigo()
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glColor3f(0, 255, 169);
	glutSolidCube(20);
	glPopMatrix();
}

void Inimigo::Movimento(float _x, float _z)
{

	x += _x;
	z += _z;

	glPushMatrix();
	glTranslatef(x, y, z);
	glColor3f(0, 255, 169);
	glutSolidCube(20);
	glPopMatrix();
}

Inimigo::Inimigo()
{
}


Inimigo::~Inimigo()
{
}
