#pragma once
#include <gl/freeglut.h>
class Bullet
{
	public:

	float x, y, z;

	float speed = 1;


	bool usada = false;


	void CriaBullet(float _x, float _y, float _z);
	void DesenhaBullet();
	void Movimento(float _x, float _z);

	Bullet();
	~Bullet();
};