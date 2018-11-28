#pragma once

#include<gl\freeglut.h>
#include<iostream>

#include "Bullet.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Objetos.h"
#include "Fuel.h"

class Scene
{
public:

	GLfloat fAspect, angle;

	GLfloat cubeAngle, cubeX, cubeY, cubeZ, moveX, moveY, moveZ;

	const int FPS = 60;

	void Render();
	void Start();
	void Update();
	void GetKeyboardInput(unsigned char key, int x, int y);
	void GetMouseInput(int button, int state, int x, int y);
	void SetWindowSize(GLsizei w, GLsizei h);
	void SpecifyViewParameters();

	void MainMenu();
	void Playing(void);
	void Pause();
	void GameOver();
	void Help();

	Scene();
	~Scene();

	Bullet bullets[1];
	Jogador jogador;
	Inimigo IA[5];
	Fuel fuel[3];
	Objetos Pecas;	

	bool lado = true;

	float speed = 5.0f;
};

