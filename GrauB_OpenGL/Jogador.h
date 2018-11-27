#pragma once
#include <gl/freeglut.h>
class Jogador
{
public:

	float x, y, z;

	void Desenhajogador();
	void CriaPlayer(float _x, float _y, float _z);

	void Movimenta(float _x);

	Jogador();
	~Jogador();
};

