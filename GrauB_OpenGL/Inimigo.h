#pragma once
#include <gl/freeglut.h>
class Inimigo
{
public:


	float x, y, z;

	float speed;


	bool move;


	//criacao dos inimigs e objetos no cenario
	void CriaObjetos();


	void CriaInimigo(float _x, float _y, float _z);
	void DesenhaInimigo();
	void DesenhaBarco();


	void Movimento(float _x, float _z);



	Inimigo();
	~Inimigo();
};

