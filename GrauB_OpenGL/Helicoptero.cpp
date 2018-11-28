#include "Helicoptero.h"

void helicoptero::CriaHelecoptero(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void helicoptero::DesenhaHelecoptero()
{
	//helice 3d
	glPushMatrix();
	glTranslatef(x, y, z);
	//glScalef(8, 8, 8);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.1f, 0.5f, 0.5);
	glVertex3f(0.1f, 0.7f, 0.5);
	glVertex3f(1.0f, 0.7f, 0.5);
	glVertex3f(1.0f, 0.5f, 0.5);

	glVertex3f(0.1f, 0.5f, 0.6);
	glVertex3f(0.1f, 0.7f, 0.6);
	glVertex3f(1.0f, 0.7f, 0.6);
	glVertex3f(1.0f, 0.5f, 0.6);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.3, 0.0, 0.6);
	glRotatef(90, 0.0, 0.2, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.0f, 0.5f, 0.7);
	glVertex3f(0.0f, 0.7f, 0.7);
	glVertex3f(0.1f, 0.7f, 0.7);
	glVertex3f(0.1f, 0.5f, 0.7);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(-0.6, 0.0, 0.6);
	glRotatef(90, 0.0, 0.2, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.0f, 0.5f, 0.7);
	glVertex3f(0.0f, 0.7f, 0.7);
	glVertex3f(0.1f, 0.7f, 0.7);
	glVertex3f(0.1f, 0.5f, 0.7);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(90, -1.0, 0.0, 0.0);
	glTranslatef(0.0, -1.1, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.1f, 0.5f, 0.5);
	glVertex3f(0.1f, 0.6f, 0.5);
	glVertex3f(1.0f, 0.6f, 0.5);
	glVertex3f(1.0f, 0.5f, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(90, -1.0, 0.0, 0.0);
	glTranslatef(0.0, -1.1, 0.2);
	glBegin(GL_QUADS);
	glVertex3f(0.1f, 0.5f, 0.5);
	glVertex3f(0.1f, 0.6f, 0.5);
	glVertex3f(1.0f, 0.6f, 0.5);
	glVertex3f(1.0f, 0.5f, 0.5);
	glEnd();
	glPopMatrix();
	//fim helice


	//tronco 3d
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.3f, 0.5);
	glVertex3f(0.5f, 0.5f, 0.5);
	glVertex3f(0.6f, 0.5f, 0.5);
	glVertex3f(0.6f, 0.3f, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.3f, 0.6);
	glVertex3f(0.5f, 0.5f, 0.6);
	glVertex3f(0.6f, 0.5f, 0.6);
	glVertex3f(0.6f, 0.3f, 0.6);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(-1.1, 0.0, -0.2);
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.3f, 0.7);
	glVertex3f(0.5f, 0.5f, 0.7);
	glVertex3f(0.6f, 0.5f, 0.7);
	glVertex3f(0.6f, 0.3f, 0.7);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(-1.1, 0.0, -0.1);
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.3f, 0.7);
	glVertex3f(0.5f, 0.5f, 0.7);
	glVertex3f(0.6f, 0.5f, 0.7);
	glVertex3f(0.6f, 0.3f, 0.7);
	glEnd();
	glPopMatrix();
	//fim tronco

	//corpo 3d
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.3f, 0.1f, 0.5);
	glVertex3f(0.3f, 0.3f, 0.5);
	glVertex3f(1.0f, 0.3f, 0.5);
	glVertex3f(1.0f, 0.1f, 0.5);
	glVertex3f(0.8f, 0.1f, 0.5);
	glVertex3f(0.7f, 0.0f, 0.5);
	glVertex3f(0.4f, 0.0f, 0.5);
	glVertex3f(0.3f, 0.1f, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.3f, 0.1f, 0.6);
	glVertex3f(0.3f, 0.3f, 0.6);
	glVertex3f(1.0f, 0.3f, 0.6);
	glVertex3f(1.0f, 0.1f, 0.6);
	glVertex3f(0.8f, 0.1f, 0.6);
	glVertex3f(0.7f, 0.0f, 0.6);
	glVertex3f(0.4f, 0.0f, 0.6);
	glVertex3f(0.3f, 0.1f, 0.6);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.0, -0.4, 0.6);
	glRotatef(90, -0.1, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.3f, 0.1f, 0.7);
	glVertex3f(0.3f, 0.0f, 0.7);
	glVertex3f(1.0f, 0.0f, 0.7);
	glVertex3f(1.0f, 0.1f, 0.7);
	glVertex3f(0.8f, 0.1f, 0.7);
	glVertex3f(0.7f, 0.0f, 0.7);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(-1.1, -0.2, -0.4);
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.3f, 0.7);
	glVertex3f(0.5f, 0.5f, 0.7);
	glVertex3f(0.6f, 0.5f, 0.7);
	glVertex3f(0.6f, 0.3f, 0.7);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(-1.1, -0.2, 0.3);
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.3f, 0.7);
	glVertex3f(0.5f, 0.5f, 0.7);
	glVertex3f(0.6f, 0.5f, 0.7);
	glVertex3f(0.6f, 0.3f, 0.7);
	glEnd();
	glPopMatrix();
	//fim corpo

}

void helicoptero::Movimento(float _x, float _z)
{
	x += _x;
	z += _z;


	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(8, 8, 8);
	//helice
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.1f, 0.5f, 0.5);
	glVertex3f(0.1f, 0.7f, 0.5);
	glVertex3f(1.0f, 0.7f, 0.5);
	glVertex3f(1.0f, 0.5f, 0.5);
	glEnd();
	//tronco
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.3f, 0.5);
	glVertex3f(0.5f, 0.5f, 0.5);
	glVertex3f(0.6f, 0.5f, 0.5);
	glVertex3f(0.6f, 0.3f, 0.5);
	glEnd();
	//corpo
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.3f, 0.1f, 0.5);
	glVertex3f(0.3f, 0.3f, 0.5);
	glVertex3f(1.0f, 0.3f, 0.5);
	glVertex3f(1.0f, 0.1f, 0.5);
	glVertex3f(0.8f, 0.1f, 0.5);
	glVertex3f(0.7f, 0.0f, 0.5);
	glVertex3f(0.4f, 0.0f, 0.5);
	glVertex3f(0.3f, 0.1f, 0.5);
	glEnd();
	glPopMatrix();
}

helicoptero::helicoptero()
{
}


helicoptero::~helicoptero()
{
}
