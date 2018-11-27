#pragma once
#include <gl/freeglut.h>
class Fuel
{
	public:

	float x, y, z;

	float combustivel;

	float speed;

	void DesenhaFuel();
	void CriaFuel(float _x, float _y, float _z);

	void Movimenta(float _x, float _z);

	Fuel();
	~Fuel();
};