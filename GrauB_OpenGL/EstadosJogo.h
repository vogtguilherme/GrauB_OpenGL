#pragma once
#include "GL\freeglut.h"

#include<iostream>
#include <string>

using namespace std;

class EstadosJogo
{
private:
	
	bool menuAtivo, over, jogo, saiu, paused;
	int aux;

public:
	
	EstadosJogo();

	string setaSelecao, tituloJogo;
	string novoJogo, sairJogo, continuar, _gameOver, restart, pauseText;

	void Texto(const char *text, int length, int x, int y);
	void Titulo(const char *text, int length, int x, int y);
	void menu();
	void gameOver();
	void pause();

	bool getMenuAtivo();
	void setMenuAtivo(bool menu);

	bool getOverAtivo();
	void setOverAtivo(bool pause);

	bool getSairJogo();
	void setSairJogo(bool _sair);

	bool getJogo();
	void setJogo(bool sair);

	bool getPause();
	void setPause(bool pause);

	int getAuxMenu();
	void setAuxMenu(int _aux);
};

