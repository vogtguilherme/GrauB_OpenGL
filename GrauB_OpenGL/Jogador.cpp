#include "Jogador.h"

void Jogador::Desenhajogador()
{
	glPushMatrix();
	glTranslatef(0.0f + smooth_x, 0.0f + y, 0.0f + z);
	glScalef(3, 3, 3);
	glRotated(angle_z, 0.0, 0.0, 1.0);
	glColor3f(0.7, 0.13, 0.13);
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.26, 0.13);				glVertex3f(0.0f, 0.0f, -5.0f); //cores e verteces
	glColor3f(0.7, 0.13, 0.26);				glVertex3f(-1.0f, 1.0f, 0.0f); //cores e verteces
	glColor3f(0.7, 0.13, 0.13);				glVertex3f(1.0f, 1.0f, 0.0f); //cores e verteces
	glColor3f(0.15, 0.13, 0.13);			glVertex3f(1.0f, -1.0f, 0.0f); //cores e verteces
	glColor3f(0.7, 0.25, 0.13);				glVertex3f(-1.0f, -1.0f, 0.0f); //cores e verteces
	glColor3f(1.0, 0.13, 0.13);				glVertex3f(-1.0f, 1.0f, 0.0f); //cores e verteces
	glEnd();
	glPopMatrix();

}

void Jogador::Movimenta(float _x)
{
	x += _x;
}

void Jogador::CriaPlayer(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;

	smooth_x = x;
}

void Jogador::Update()
{
	if (smooth_x != x && smooth_x < x)
	{
		smooth_x += (x - smooth_x) * 0.1f;

		angle_z = -(x - smooth_x) * 3;
	}
	else if (smooth_x != x && smooth_x > x)
	{
		smooth_x -= (smooth_x - x) * 0.1f;

		angle_z = (smooth_x - x) * 3;
	}

	if (toLeft)
	{
		if (x > -39) Movimenta(-0.6f);
	}
	else if (toRight)
	{
		if (x < 39) Movimenta(0.6f);
	}


}


Jogador::Jogador()
{
}


Jogador::~Jogador()
{
}
