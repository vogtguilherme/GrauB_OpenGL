#pragma once

#include <gl/freeglut.h>

class helicoptero
{
public:
	float x, y, z;

	float speed;


	bool move;
		
	void CriaHelecoptero(float _x, float _y, float _z);
	void DesenhaHelecoptero();
	

	void Movimento(float _x, float _z);


	helicoptero();
	~helicoptero();
};

