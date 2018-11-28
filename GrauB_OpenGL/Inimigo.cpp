#include "Inimigo.h"

void Inimigo::CriaInimigo(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Inimigo::DesenhaInimigo()
{
	/*glPushMatrix();
	glTranslatef(x, y, z);
	glColor3f(0, 255, 169);
	glutSolidCube(20);
	glPopMatrix();*/

	
	//base
	glPushMatrix();
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.1f, 0.3f, 0.0);
	glVertex3f(0.6f, 0.3f, 0.0);
	glVertex3f(0.5f, 0.1f, 0.0);
	glVertex3f(0.2f, 0.1f, 0.0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glTranslatef(0.0, 0.0, 0.1);
	glBegin(GL_QUADS);
	glVertex3f(0.1f, 0.3f, 0.0);
	glVertex3f(0.6f, 0.3f, 0.0);
	glVertex3f(0.5f, 0.1f, 0.0);
	glVertex3f(0.2f, 0.1f, 0.0);
	glEnd();
	glPopMatrix();
	//fim base

	//tronco
	glPushMatrix();
	glColor3f(0.74, 0.56, 0.56);
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glBegin(GL_QUADS);
	glVertex3f(0.3f, 0.3f, 0.0);
	glVertex3f(0.3f, 0.5f, 0.0);
	glVertex3f(0.4f, 0.5f, 0.0);
	glVertex3f(0.4f, 0.3f, 0.0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.74, 0.56, 0.56);
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glTranslatef(0.0, 0.0, 0.1);
	glBegin(GL_QUADS);
	glVertex3f(0.3f, 0.3f, 0.0);
	glVertex3f(0.3f, 0.5f, 0.0);
	glVertex3f(0.4f, 0.5f, 0.0);
	glVertex3f(0.4f, 0.3f, 0.0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.74, 0.56, 0.56);
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glTranslatef(0.4, 0.0, 0.4);
	glRotatef(90, 0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.3f, 0.3f, 0.0);
	glVertex3f(0.3f, 0.5f, 0.0);
	glVertex3f(0.4f, 0.5f, 0.0);
	glVertex3f(0.4f, 0.3f, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.74, 0.56, 0.56);
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glTranslatef(0.3, 0.0, 0.4);
	glRotatef(90, 0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.3f, 0.3f, 0.0);
	glVertex3f(0.3f, 0.5f, 0.0);
	glVertex3f(0.4f, 0.5f, 0.0);
	glVertex3f(0.4f, 0.3f, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.74, 0.56, 0.56);
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glTranslatef(-0.2, 0.1, -0.2);
	glRotatef(90, 1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.7f, 0.3f, 0.0);
	glVertex3f(0.7f, 0.2f, 0.0);
	glVertex3f(0.4f, 0.2f, 0.0);
	glVertex3f(0.4f, 0.3f, 0.0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.74, 0.56, 0.56);
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glTranslatef(-0.3, 0.3, -0.2);
	glRotatef(90, 1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.9f, 0.3f, 0.0);
	glVertex3f(0.9f, 0.2f, 0.0);
	glVertex3f(0.4f, 0.2f, 0.0);
	glVertex3f(0.4f, 0.3f, 0.0);
	glEnd();
	glPopMatrix();

	//fim tronco

	//velas
	glPushMatrix();
	glColor3f(0.75, 1.0, 0.0);
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.4f, 0.3f, 0.0);
	glVertex3f(0.4f, 0.5f, 0.0);
	glVertex3f(0.6f, 0.3f, 0.0);
	glEnd();
	glPopMatrix();

	
}

void Inimigo::Movimento(float _x, float _z)
{

	x += _x;
	z += _z;

	/*glPushMatrix();
	glTranslatef(x, y, z);
	glColor3f(0, 255, 169);
	glutSolidCube(20);
	glPopMatrix();*/

	///base
	glPushMatrix();
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.1f, 0.3f, 0.0);
	glVertex3f(0.6f, 0.3f, 0.0);
	glVertex3f(0.5f, 0.1f, 0.0);
	glVertex3f(0.2f, 0.1f, 0.0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glTranslatef(0.0, 0.0, 0.1);
	glBegin(GL_QUADS);
	glVertex3f(0.1f, 0.3f, 0.0);
	glVertex3f(0.6f, 0.3f, 0.0);
	glVertex3f(0.5f, 0.1f, 0.0);
	glVertex3f(0.2f, 0.1f, 0.0);
	glEnd();
	glPopMatrix();
	//fim base

	//tronco
	glPushMatrix();
	glColor3f(0.74, 0.56, 0.56);
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glBegin(GL_QUADS);
	glVertex3f(0.3f, 0.3f, 0.0);
	glVertex3f(0.3f, 0.5f, 0.0);
	glVertex3f(0.4f, 0.5f, 0.0);
	glVertex3f(0.4f, 0.3f, 0.0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.74, 0.56, 0.56);
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glTranslatef(0.0, 0.0, 0.1);
	glBegin(GL_QUADS);
	glVertex3f(0.3f, 0.3f, 0.0);
	glVertex3f(0.3f, 0.5f, 0.0);
	glVertex3f(0.4f, 0.5f, 0.0);
	glVertex3f(0.4f, 0.3f, 0.0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.74, 0.56, 0.56);
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glTranslatef(0.4, 0.0, 0.4);
	glRotatef(90, 0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.3f, 0.3f, 0.0);
	glVertex3f(0.3f, 0.5f, 0.0);
	glVertex3f(0.4f, 0.5f, 0.0);
	glVertex3f(0.4f, 0.3f, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.74, 0.56, 0.56);
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glTranslatef(0.3, 0.0, 0.4);
	glRotatef(90, 0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.3f, 0.3f, 0.0);
	glVertex3f(0.3f, 0.5f, 0.0);
	glVertex3f(0.4f, 0.5f, 0.0);
	glVertex3f(0.4f, 0.3f, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.74, 0.56, 0.56);
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glTranslatef(-0.2, 0.1, -0.2);
	glRotatef(90, 1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.7f, 0.3f, 0.0);
	glVertex3f(0.7f, 0.2f, 0.0);
	glVertex3f(0.4f, 0.2f, 0.0);
	glVertex3f(0.4f, 0.3f, 0.0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.74, 0.56, 0.56);
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glTranslatef(-0.3, 0.3, -0.2);
	glRotatef(90, 1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.9f, 0.3f, 0.0);
	glVertex3f(0.9f, 0.2f, 0.0);
	glVertex3f(0.4f, 0.2f, 0.0);
	glVertex3f(0.4f, 0.3f, 0.0);
	glEnd();
	glPopMatrix();

	//fim tronco

	//velas
	glPushMatrix();
	glColor3f(0.75, 1.0, 0.0);
	glScalef(8, 8, 8);
	glTranslatef(x, y, z);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.4f, 0.3f, 0.0);
	glVertex3f(0.4f, 0.5f, 0.0);
	glVertex3f(0.6f, 0.3f, 0.0);
	glEnd();
	glPopMatrix();

}

Inimigo::Inimigo()
{
}


Inimigo::~Inimigo()
{
}
