#include "Fuel.h"

void Fuel::CriaFuel(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Fuel::DesenhaFuel()
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glTranslatef(1, 1, 3);
	glColor3f(1.0f, 0.0f, 0.25f);
	glutSolidCube(3);
	glPopMatrix();
}

void Fuel::Movimenta(float _x, float _z)
{
	x += _x;
	z += _z;
}

Fuel::Fuel()
{
}


Fuel::~Fuel()
{
}