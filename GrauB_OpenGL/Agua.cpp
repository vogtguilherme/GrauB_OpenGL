#include "Agua.h"



void Agua::DesenhaAgua()
{
	//mar
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 255);
	glVertex3f(-1.5, 0, 999999.999999999f);
	glVertex3f(1.5, 0, 999999.999999999f);
	glVertex3f(1.5, 0, -999999.99999999f);
	glVertex3f(-1.5, 0, -999999.9999999f);
	glEnd();
	glPopMatrix();
}

Agua::Agua()
{
}


Agua::~Agua()
{
}
