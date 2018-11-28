#pragma once
#include "GL\freeglut.h"

#include<iostream>
#include <string>

using namespace std;

enum States
{
	MAINMENU, PLAYING, HELP, PAUSE, GAMEOVER
};

class EstadosJogo
{
private:
	
	bool menuAtivo, over, jogo, saiu;
	int aux;

	States estadoAtual;

public:
	
	EstadosJogo();

	string setaSelecao, tituloJogo;
	string novoJogo, sairJogo, continuar, _gameOver;

	void Texto(const char *text, int length, int x, int y);
	void Titulo(const char *text, int length, int x, int y);
	void menu();
	void gameOver();

	States GetCurrentState();
	void SetCurrentState(States value);

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

