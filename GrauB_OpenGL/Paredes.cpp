#include "Paredes.h"



void Paredes::DesenhaParedes()
{

	//desenho das paredes tanto escala quanto a translação

	glPushMatrix();
	glScalef(0.5f, 0.5f, 99.9f);
	glTranslatef(-1.9f, 0.0f, 0.0f);
	glColor3f(0.0, 0.5, 0.0);
	glutSolidCube(0.5);

	glTranslatef(3.8f, 0.0f, 0.0f);
	glColor3f(0.0, 0.9, 0.0);
	glutSolidCube(0.5);
	glFlush();
	glPopMatrix();
}

Paredes::Paredes()
{
}


Paredes::~Paredes()
{
}
