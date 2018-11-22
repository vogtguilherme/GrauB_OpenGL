#include "Player.h"



void Player::DesenhaPlayer()
{

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	////nave
	glColor3f(0.7, 0.13, 0.13);
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.26, 0.13);				glVertex3f(0.3f, 0.3f, 1.0f); //cores e verteces
	glColor3f(0.7, 0.13, 0.26);				glVertex3f(0.2f, 0.4f, 0.5f); //cores e verteces
	glColor3f(0.7, 0.13, 0.13);				glVertex3f(0.4f, 0.4f, 0.5f); //cores e verteces
	glColor3f(0.15, 0.13, 0.13);			glVertex3f(0.4f, 0.2f, 0.5f); //cores e verteces
	glColor3f(0.7, 0.25, 0.13);				glVertex3f(0.2f, 0.2f, 0.5f); //cores e verteces
	glColor3f(1.0, 0.13, 0.13);				glVertex3f(0.2f, 0.4f, 0.5f); //cores e verteces
	glEnd();
	glPopMatrix();

}

Player::Player()
{
}


Player::~Player()
{
}
