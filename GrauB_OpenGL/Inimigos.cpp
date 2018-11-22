#include "Inimigos.h"



void Inimigos::Movimentar(float x)
{

	
	movX = x;


}

void Inimigos::DesenhaInimigos()
{

	glPushMatrix();
	glTranslatef(0.5 + movX , 0.2, 0.0f);
	glScalef(0.5, 0.5, 0.5);
	glColor3f(0.35, 0.15, 0.0);
	glutSolidCube(0.5);
	glPopMatrix();

}

Inimigos::Inimigos()
{
}


Inimigos::~Inimigos()
{
}
