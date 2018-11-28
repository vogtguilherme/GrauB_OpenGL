#pragma once
#include <gl/freeglut.h>
class Barco
{
public:


	float x, y, z;
	float speed;
	bool move;
	

	void CriaInimigo(float _x, float _y, float _z);
	void DesenhaInimigo();
	void Movimento(float _x, float _z);



	Barco();
	~Barco();
};

