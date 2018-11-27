#pragma once

#include <gl/freeglut.h>
class Objetos
{
public:

	float x;

	void criaMar();

	void CriaParedes();

	void Mmovimenta(float _x);

	Objetos();
	~Objetos();
};

