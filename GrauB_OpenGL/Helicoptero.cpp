#include "Helicoptero.h"

void Helicoptero::CriaHelecoptero(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Helicoptero::DesenhaHelecoptero()
{
	//helice 3d
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.3f, 0.5);
	glVertex3f(0.5f, 0.5f, 0.5);
	glVertex3f(0.6f, 0.5f, 0.5);
	glVertex3f(0.6f, 0.3f, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.3f, 0.6);
	glVertex3f(0.5f, 0.5f, 0.6);
	glVertex3f(0.6f, 0.5f, 0.6);
	glVertex3f(0.6f, 0.3f, 0.6);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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

void Helicoptero::Movimento(float _x, float _z)
{
	x += _x;
	z += _z;


	//helice 3d
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.3f, 0.5);
	glVertex3f(0.5f, 0.5f, 0.5);
	glVertex3f(0.6f, 0.5f, 0.5);
	glVertex3f(0.6f, 0.3f, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.3f, 0.6);
	glVertex3f(0.5f, 0.5f, 0.6);
	glVertex3f(0.6f, 0.5f, 0.6);
	glVertex3f(0.6f, 0.3f, 0.6);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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
	glTranslatef(x, y, z);
	glScalef(20, 20, 20);
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

Helicoptero::Helicoptero()
{
}


Helicoptero::~Helicoptero()
{
}