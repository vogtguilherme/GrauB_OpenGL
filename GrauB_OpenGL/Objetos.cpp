#include "Objetos.h"


void Objetos::criaMar()
{
	//mar
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 255);
	glVertex3f(-500, 0, 50.0f);
	glVertex3f(500, 0, 50.0f);
	glVertex3f(500, 0, -4000.0f);
	glVertex3f(-500, 0, -4000.0f);
	glEnd();
	glPopMatrix();

}

void Objetos::CriaMontanhas()
{
	//montanha1
	glPushMatrix();
	glTranslatef(30.0f, 0.0f, 0.0f);
	glRotatef(-90, 0.5, 0.0, 0.0);
	glScalef(30, 30, 30);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);				glVertex3f(0.3f, 0.3f, 1.0f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.2f, 0.4f, 0.5f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.4f, 0.4f, 0.5f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.4f, 0.2f, 0.5f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.2f, 0.2f, 0.5f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.2f, 0.4f, 0.5f); //cores e verteces
	glEnd();
	glPopMatrix();

	//montanha2
	glPushMatrix();
	glTranslatef(30.0f, -10.0f, 0.0f);
	glRotatef(-90, 0.5, 0.0, 0.0);
	glScalef(30, 30, 30);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.3f, 0.3f, 1.0f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.2f, 0.4f, 0.5f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.4f, 0.4f, 0.5f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.4f, 0.2f, 0.5f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.2f, 0.2f, 0.5f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.2f, 0.4f, 0.5f); //cores e verteces
	glEnd();
	glPopMatrix();


	//montanha3
	glPushMatrix();
	glTranslatef(20.0f, 20.0f, 0.0f);
	glRotatef(-90, 0.5, 0.0, 0.0);
	glScalef(30, 30, 30);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.3f, 0.3f, 1.0f); //cores e verteces
	glColor3f(1.1, 0.13, 0.7);				glVertex3f(0.2f, 0.4f, 0.5f); //cores e verteces
	glColor3f(1.1, 0.13, 0.7);				glVertex3f(0.4f, 0.4f, 0.5f); //cores e verteces
	glColor3f(1.1, 0.13, 0.7);				glVertex3f(0.4f, 0.2f, 0.5f); //cores e verteces
	glColor3f(1.1, 0.13, 0.7);				glVertex3f(0.2f, 0.2f, 0.5f); //cores e verteces
	glColor3f(1.1, 0.13, 0.7);				glVertex3f(0.2f, 0.4f, 0.5f); //cores e verteces
	glEnd();
	glPopMatrix();

	//montanha4
	glPushMatrix();
	glTranslatef(-40.0f, 0.0f, 0.0f);
	glRotatef(-90, 0.5, 0.0, 0.0);
	glScalef(30, 30, 30);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);				glVertex3f(0.3f, 0.3f, 1.0f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.2f, 0.4f, 0.5f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.4f, 0.4f, 0.5f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.4f, 0.2f, 0.5f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.2f, 0.2f, 0.5f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.2f, 0.4f, 0.5f); //cores e verteces
	glEnd();
	glPopMatrix();

	//montanha5
	glPushMatrix();
	glTranslatef(-50.0f, -10.0f, 0.0f);
	glRotatef(-90, 0.5, 0.0, 0.0);
	glScalef(30, 30, 30);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.3f, 0.3f, 1.0f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.2f, 0.4f, 0.5f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.4f, 0.4f, 0.5f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.4f, 0.2f, 0.5f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.2f, 0.2f, 0.5f); //cores e verteces
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.2f, 0.4f, 0.5f); //cores e verteces
	glEnd();
	glPopMatrix();


	//montanha6
	glPushMatrix();
	glTranslatef(-20.0f, 20.0f, 0.0f);
	glRotatef(-90, 0.5, 0.0, 0.0);
	glScalef(30, 30, 30);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.13, 0.7);				glVertex3f(0.3f, 0.3f, 1.0f); //cores e verteces
	glColor3f(1.1, 0.13, 0.7);				glVertex3f(0.2f, 0.4f, 0.5f); //cores e verteces
	glColor3f(1.1, 0.13, 0.7);				glVertex3f(0.4f, 0.4f, 0.5f); //cores e verteces
	glColor3f(1.1, 0.13, 0.7);				glVertex3f(0.4f, 0.2f, 0.5f); //cores e verteces
	glColor3f(1.1, 0.13, 0.7);				glVertex3f(0.2f, 0.2f, 0.5f); //cores e verteces
	glColor3f(1.1, 0.13, 0.7);				glVertex3f(0.2f, 0.4f, 0.5f); //cores e verteces
	glEnd();
	glPopMatrix();


}

void Objetos::CriaParedes()
{
	//parede lado direito
	glPushMatrix();
	glTranslatef(-540.0f, 0.5f, -2000.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glScalef(1000, 0.0, 4000.999f);
	glutSolidCube(1);
	glPopMatrix();

	//parede lado direito
	glPushMatrix();
	glTranslatef(540.0f, 0.5f, -2000.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glScalef(1000, 0.0, 4000.999f);
	glutSolidCube(1);
	glPopMatrix();
}

void Objetos::Mmovimenta(float _x)
{


	x = _x;

	//mar
	glPushMatrix();
	glBegin(GL_QUADS);
	glScalef(50.0f, 0.0, 0.0);
	glColor3f(0, 0, 255);
	glVertex3f(-1.5 + x, 0, 999999.999999999f);
	glVertex3f(1.5 + x, 0, 999999.999999999f);
	glVertex3f(1.5 + x, 0, -999999.99999999f);
	glVertex3f(-1.5 + x, 0, -999999.9999999f);
	glEnd();
	glPopMatrix();


}

Objetos::Objetos()
{
}


Objetos::~Objetos()
{
}
