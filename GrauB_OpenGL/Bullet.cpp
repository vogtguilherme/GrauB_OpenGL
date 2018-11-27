#include "Bullet.h"

void Bullet::CriaBullet(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Bullet::DesenhaBullet()
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glColor3f(1.0f, 0.1f, 0.1f);
	glutSolidCube(1);
	glPopMatrix();
}

void Bullet::Movimento(float _x, float _z)
{
	x += _x;
	z += _z;
}

Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}