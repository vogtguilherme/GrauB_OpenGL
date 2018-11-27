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
	glPopMatrix();
	*/

	//criando barco
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(8, 8, 8);
	glColor3f(0.32, 0.32, 0.25);
	//base
	glBegin(GL_QUADS);
	glVertex3f(2.1f, 2.3f, 0.0);
	glVertex3f(2.6f, 2.3f, 0.0);
	glVertex3f(2.5f, 2.1f, 0.0);
	glVertex3f(2.2f, 2.1f, 0.0);
	glEnd();

	//tronco
	glColor3f(0.74, 0.56, 0.56);
	glBegin(GL_QUADS);
	glVertex3f(2.3f, 2.3f, 0.0);
	glVertex3f(2.3f, 2.5f, 0.0);
	glVertex3f(2.4f, 2.5f, 0.0);
	glVertex3f(2.4f, 2.3f, 0.0);
	glEnd();

	//velas
	glColor3f(0.75, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(2.4f, 2.3f, 0.0);
	glVertex3f(2.4f, 2.5f, 0.0);
	glVertex3f(2.6f, 2.3f, 0.0);
	glEnd();
	glPopMatrix();

}

//void Inimigo::DesenhaBarco()
//{
//
//	glPushMatrix();
//	glTranslatef(x, y, z);
//	glColor3f(0.32, 0.32, 0.25);
//	//base
//	glBegin(GL_QUADS);
//	glVertex3f( 0.1f, 0.3f,-10.0);
//	glVertex3f( 0.6f, 0.3f,-10.0);
//	glVertex3f( 0.5f, 0.1f,-10.0);
//	glVertex3f( 0.2f, 0.1f,-10.0);
//	glEnd();
//
//	//tronco
//	glColor3f(0.74, 0.56, 0.56);
//	glBegin(GL_QUADS);
//	glVertex3f( 0.3f, 0.3f,-10.0);
//	glVertex3f( 0.3f, 0.5f,-10.0);
//	glVertex3f( 0.4f, 0.5f,-10.0);
//	glVertex3f( 0.4f, 0.3f,-10.0);
//	glEnd();
//
//	//velas
//	glColor3f(0.75, 1.0, 0.0);
//	glBegin(GL_TRIANGLES);
//	glVertex3f( 0.4f, 0.3f,-10.0);
//	glVertex3f( 0.4f, 0.5f,-10.0);
//	glVertex3f( 0.6f,  0.3f,-10.0);
//	glEnd();
//	glPopMatrix();
//
//}

void Inimigo::Movimento(float _x, float _z)
{

	x += _x;
	z += _z;

	//criando barco
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(8, 8, 8);
	glColor3f(0.32, 0.32, 0.25);
	//base
	glBegin(GL_QUADS);
	glVertex3f(2.1f, 2.3f, 0.0);
	glVertex3f(2.6f, 2.3f, 0.0);
	glVertex3f(2.5f, 2.1f, 0.0);
	glVertex3f(2.2f, 2.1f, 0.0);
	glEnd();
	//tronco
	glColor3f(0.74, 0.56, 0.56);
	glBegin(GL_QUADS);
	glVertex3f(2.3f, 2.3f, 0.0);
	glVertex3f(2.3f, 2.5f, 0.0);
	glVertex3f(2.4f, 2.5f, 0.0);
	glVertex3f(2.4f, 2.3f, 0.0);
	glEnd();
	//velas
	glColor3f(0.75, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(2.4f, 2.3f, 0.0);
	glVertex3f(2.4f, 2.5f, 0.0);
	glVertex3f(2.6f, 2.3f, 0.0);
	glEnd();
	glPopMatrix();

	/*glPushMatrix();
	glTranslatef(x, y, z);
	glColor3f(0, 255, 169);
	glutSolidCube(20);
	glPopMatrix();
	*/
}

Inimigo::Inimigo()
{
}


Inimigo::~Inimigo()
{
}
