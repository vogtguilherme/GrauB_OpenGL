#pragma once

#include <gl/freeglut.h>
class Objetos
{
public:

	float x,y,z;

	void criaMar();

	void CriaMontanhas();


	void CriaParedes();

	void Mmovimenta(float _x);

	Objetos();
	~Objetos();
};

