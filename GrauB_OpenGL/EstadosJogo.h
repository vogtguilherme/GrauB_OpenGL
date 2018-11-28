#pragma once
#include "GL\freeglut.h"

#include<iostream>
#include <string>

using namespace std;

class EstadosJogo
{
private:
	
	bool menuAtivo, over, jogo, saiu;
	int aux;

public:
	
	EstadosJogo();

	string setaSelecao, tituloJogo;
	string novoJogo, sairJogo, continuar, _gameOver;

	void Texto(const char *text, int length, int x, int y);
	void Titulo(const char *text, int length, int x, int y);
	void menu();
	void gameOver();

	bool getMenuAtivo();
	void setMenuAtivo(bool menu);

	bool getOverAtivo();
	void setOverAtivo(bool pause);

	bool getSairJogo();
	void setSairJogo(bool _sair);

	bool getJogo();
	void setJogo(bool sair);

	int getAuxMenu();
	void setAuxMenu(int _aux);
};

