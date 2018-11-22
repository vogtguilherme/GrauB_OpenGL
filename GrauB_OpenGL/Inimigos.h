#pragma once

#include <GL\freeglut.h>
class Inimigos
{



public:
	float movX;
	void Movimentar(float x);

	void DesenhaInimigos();


	Inimigos();
	~Inimigos();
};

