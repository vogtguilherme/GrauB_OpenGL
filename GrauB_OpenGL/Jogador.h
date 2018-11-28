#pragma once
#include <gl/freeglut.h>
class Jogador
{
public:

	float x, y, z;
	float smooth_x;
	float angle_z;

	int vidas, acertos;

	bool toLeft = false;
	bool toRight = false;

	float combustivel;

	void Desenhajogador();
	void Update();
	void CriaPlayer(float _x, float _y, float _z);

	void Movimenta(float _x);

	Jogador();
	~Jogador();
};

