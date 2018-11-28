#include "Scene.h"

void Scene::Update()
{
	//Condicional para quando o usuario deseja sair do jogo
	if (estadosJogo.getSairJogo())
	{
		exit(0);
	}
}

void Scene::GetKeyboardInputUP(unsigned char key, int x, int y)
{
	if (estadosJogo.getJogo())
	{
		switch (key)
		{
		case 'a':
			jogador.toRight = false;
			jogador.toLeft = false;
			break;
		case 'd':
			jogador.toLeft = false;
			jogador.toRight = false;
			break;
		}
	}
}

void Scene::GetKeyboardInput(unsigned char key, int x, int y)
{
	if (estadosJogo.getMenuAtivo())
	{
		switch (key)
		{
		case 264:
		case 's':
			if (estadosJogo.getAuxMenu() == 1)
			{
				estadosJogo.setAuxMenu(0);
			}
			else
			{
				estadosJogo.setAuxMenu(1);
			}
			break;

		case 265:
		case 'w':
			if (estadosJogo.getAuxMenu() == 1)
			{
				estadosJogo.setAuxMenu(0);
			}
			else
			{
				estadosJogo.setAuxMenu(1);
			}
			break;

		case 13:
			if (estadosJogo.getAuxMenu() == 1)
			{
				Start();

				estadosJogo.setJogo(true);

				SpecifyViewParameters();

				estadosJogo.setMenuAtivo(false);
			}
			else
			{
				estadosJogo.setSairJogo(true);
			}
			break;
		}
	}
	else if (estadosJogo.getJogo())
	{
		switch (key)
		{
		case 'a':
			jogador.toRight = false;
			jogador.toLeft = true;
			break;
		case 'd':
			jogador.toLeft = false;
			jogador.toRight = true;
			break;
		}

		switch (key)
		{
		case 27:
			estadosJogo.setJogo(false);
			estadosJogo.setPause(true);
			break;
		}
	}
	else if (estadosJogo.getOverAtivo())
	{
		switch (key)
		{
		case 's':
			if (estadosJogo.getAuxMenu() == 1)
			{
				estadosJogo.setAuxMenu(0);
			}
			else
			{
				estadosJogo.setAuxMenu(1);
			}
			break;

		case 'w':
			if (estadosJogo.getAuxMenu() == 1)
			{
				estadosJogo.setAuxMenu(0);
			}
			else
			{
				estadosJogo.setAuxMenu(1);
			}
			break;

		case 13:
			if (estadosJogo.getAuxMenu() == 1)
			{
				Start();

				estadosJogo.setJogo(true);

				SpecifyViewParameters();

				estadosJogo.setOverAtivo(false);
			}
			else
			{
				estadosJogo.setMenuAtivo(true);

				estadosJogo.setOverAtivo(false);
			}
			break;
		}
	}
	else if (estadosJogo.getPause())
	{
		switch (key)
		{
		case 's':
			if (estadosJogo.getAuxMenu() == 1)
			{
				estadosJogo.setAuxMenu(0);
			}
			else
			{
				estadosJogo.setAuxMenu(1);
			}
			break;

		case 'w':
			if (estadosJogo.getAuxMenu() == 1)
			{
				estadosJogo.setAuxMenu(0);
			}
			else
			{
				estadosJogo.setAuxMenu(1);
			}
			break;

		case 13:
			if (estadosJogo.getAuxMenu() == 1)
			{
				estadosJogo.setJogo(true);

				SpecifyViewParameters();

				estadosJogo.setPause(false);
			}
			else
			{
				estadosJogo.setMenuAtivo(true);

				estadosJogo.setPause(false);
			}
			break;
		}
	}

}

void Scene::GetSpecialKeyboardInput(unsigned char key, int x, int y)
{
	if (estadosJogo.getMenuAtivo())
	{
		switch (key)
		{
		case GLUT_KEY_DOWN:
			if (estadosJogo.getAuxMenu() == 1)
			{
				estadosJogo.setAuxMenu(0);
			}
			else
			{
				estadosJogo.setAuxMenu(1);
			}
			break;
		case GLUT_KEY_UP:
			if (estadosJogo.getAuxMenu() == 1)
			{
				estadosJogo.setAuxMenu(0);
			}
			else
			{
				estadosJogo.setAuxMenu(1);
			}			
			break;
		}
	}
}

void Scene::GetMouseInput(int button, int state, int x, int y)
{
	if (estadosJogo.getJogo())
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			if (state == GLUT_DOWN)
			{
				for (int i = 0; i < 10; i++)
				{
					if (bullets[i].usada == false)
					{
						bullets[i].CriaBullet(jogador.x, jogador.y, jogador.z - 10);
						bullets[i].usada = true;
						break;
					}
				}
			}
		}
	}
}

void Scene::EscreveVidas(void)
{
	char texto[8] = "LIFES: ";
	char teste[20];
	int i = 0;

	//Convers�o de inteiro para string, pois a OpenGL s� escreve string ou char
	sprintf_s(teste, "%d", jogador.vidas);

	//Cor da fonte
	glColor3ub(255, 255, 255);
	//glColor3f(1,1,1);
	//Posi��o da palavra
	glRasterPos3f(35.0f, 45.0f, -10.0f);

	//Uso do "for" para escrever mais de um caracter
	for (i = 0; i <= strlen(texto); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, texto[i]);

	for (i = 0; i <= strlen(teste); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, teste[i]);
}

void Scene::EscreveKills(void)
{
	char texto[8] = "KILLS:";
	char teste[20];
	int i = 0;

	//Convers�o de inteiro para string, pois a OpenGL s� escreve string ou char
	sprintf_s(teste, "%d", jogador.acertos);

	//Cor da fonte
	glColor3ub(255, 255, 255);
	//glColor3f(1,1,1);
	//Posi��o da palavra
	glRasterPos3f(35.0f, 43.0f, -10.0f);

	//Uso do "for" para escrever mais de um caracter
	for (i = 0; i <= strlen(texto); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, texto[i]);

	for (i = 0; i <= strlen(teste); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, teste[i]);
}

void Scene::EscreveFuel(void)
{
	char texto[8] = "FUEL:";
	char teste[20];
	int i = 0;

	//Convers�o de inteiro para string, pois a OpenGL s� escreve string ou char
	sprintf_s(teste, "%d", (int)jogador.combustivel);

	//Cor da fonte
	glColor3ub(255, 255, 255);
	//glColor3f(1,1,1);
	//Posi��o da palavra
	glRasterPos3f(35.0f, 41.0f, -10.0f);

	//Uso do "for" para escrever mais de um caracter
	for (i = 0; i <= strlen(texto); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, texto[i]);

	for (i = 0; i <= strlen(teste); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, teste[i]);
}

void Scene::SetWindowSize(GLsizei w, GLsizei h)
{
	// Para previnir uma divis�o por zero
	if (h == 0) h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);

	// Calcula a corre��o de aspecto
	fAspect = (GLfloat)w / (GLfloat)h;

	SpecifyViewParameters();
}

void Scene::SpecifyViewParameters()
{
	// Especifica sistema de coordenadas de proje��o
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de proje��o
	glLoadIdentity();

	// Especifica a proje��o perspectiva
	gluPerspective(angle, fAspect, 0.4, 3000);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo

	// Especifica posi��o do observador e do alvo
	gluLookAt(0, 40, 80, 0, 25, 0, 0, 10, 0);
}

void Scene::Render()
{
	// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (estadosJogo.getJogo())
	{
		Pecas.criaMar();
		Pecas.CriaParedes();
		Pecas.CriaMontanhas();

		for (int i = 0; i < 5; i++)
		{
			barcos[i].DesenhaInimigo();
		}

		for (int i = 0; i < 5; i++)
		{
			helicoptero[i].DesenhaHelecoptero();
		}

		for (int i = 0; i < 10; i++)
		{
			bullets[i].DesenhaBullet();
		}

		for (int i = 0; i < 3; i++)
		{
			fuel[i].DesenhaFuel();
		}

		jogador.Desenhajogador();

		EscreveVidas();
		EscreveKills();
		EscreveFuel();

		Playing();
	}
	else if (estadosJogo.getMenuAtivo())
	{
		MainMenu();
	}
	else if (estadosJogo.getOverAtivo())
	{
		GameOver();
	}
	else if (estadosJogo.getPause())
	{
		Pause();
	}
}

void Scene::Start()
{
	angle = 35;
	cubeAngle = 0;
	cubeX = 0;
	cubeY = 1.0;
	cubeZ = 0;
	moveX = 0;
	moveY = 0;
	moveZ = 0;

	jogador.CriaPlayer(0, 5, 0);
	jogador.vidas = 3;
	jogador.acertos = 0;
	jogador.combustivel = 100;

	for (int i = 0; i < 3; i++)
	{
		fuel[i].CriaFuel(rand() % 70 - 35, 5.0f, -1100 * (i + 1));
		fuel[i].speed = 2.0f;
		fuel[i].combustivel = 50.0f;
	}

	for (int i = 0; i < 5; i++)
	{
		barcos[i].CriaInimigo(rand() % 80 - 40, 5.0f, -1000 * (i + 1));
		barcos[i].speed = 1.0f;
	}

	for (int i = 0; i < 5; i++)
	{
		helicoptero[i].CriaHelecoptero(rand() % 70 - 35, 5.0f, -1100 * (i + 1));
		helicoptero[i].speed = 1.0f;
	}

	for (int i = 0; i < 10; i++)
	{
		bullets[i].CriaBullet(0, jogador.y, 1000);
		bullets[i].usada = false;
		bullets[i].speed = 5;
	}
}

void Scene::MainMenu()
{
	glColor3f(1.0, 1.0, 1.0);
	estadosJogo.Texto(estadosJogo.novoJogo.data(), estadosJogo.novoJogo.size(), 352, 270);
	estadosJogo.Texto(estadosJogo.sairJogo.data(), estadosJogo.sairJogo.size(), 350, 220);

	if (estadosJogo.getAuxMenu() == 0)
	{
		estadosJogo.Titulo(estadosJogo.setaSelecao.data(), estadosJogo.setaSelecao.size(), 300, 220);
	}

	else
	{
		estadosJogo.Titulo(estadosJogo.setaSelecao.data(), estadosJogo.setaSelecao.size(), 300, 270);
	}

	estadosJogo.Titulo(estadosJogo.tituloJogo.data(), estadosJogo.tituloJogo.size(), 320, 420);
}

void Scene::Playing()
{
	if (jogador.vidas <= 0 || jogador.combustivel <= 0)
	{
		estadosJogo.setJogo(false);
		estadosJogo.setOverAtivo(true);
	}

	jogador.combustivel -= (100.0f / 30.0f) / 60.0f;

	//coptero
	for (int i = 0; i < 5; i++)
	{
		if (helicoptero[i].z < 100)
			helicoptero[i].Movimento(0, helicoptero[i].speed*speed);
		else
		{
			helicoptero[i].CriaHelecoptero(rand() % 70 - 30, helicoptero[i].y, -3000);
			
			if (helicoptero[i].speed < 20) 
				helicoptero[i].speed += helicoptero[i].speed*0.2f;
		}

		//sistema de colisao do player com o objeto
		if (jogador.x - 1.5f < helicoptero[i].x + 10 && jogador.x + 1.5f > helicoptero[i].x - 10)
		{
			if (jogador.y - 1.5f < helicoptero[i].y + 10 && jogador.y + 1.5f > helicoptero[i].y - 10)
			{
				if (jogador.z - 1.5f < helicoptero[i].z + 10 && jogador.z + 1.5f > helicoptero[i].z - 10)
				{
					helicoptero[i].CriaHelecoptero(40000, helicoptero[i].y, helicoptero[i].z);

					jogador.vidas--;
				}
			}
		}
	}

	//barquinho
	for (int i = 0; i < 5; i++)
	{
		if (barcos[i].z < 100) 
			barcos[i].Movimento(0, barcos[i].speed * speed);
		else
		{
			barcos[i].CriaInimigo(rand() % 80 - 40, barcos[i].y, -4000);
			if (barcos[i].speed < 20)
				barcos[i].speed += barcos[i].speed * 0.1f;
		}
		//colisao do player com o objeto barquinho
		if (jogador.x - 1.5f < barcos[i].x + 10 && jogador.x + 1.5f > barcos[i].x - 10)
		{
			if (jogador.y - 1.5f < barcos[i].y + 10 && jogador.y + 1.5f > barcos[i].y - 10)
			{
				if (jogador.z - 1.5f < barcos[i].z + 10 && jogador.z + 1.5f > barcos[i].z - 10)
				{
					barcos[i].CriaInimigo(50000, barcos[i].y, barcos[i].z);

					jogador.vidas--;
				}
			}
		}
	}
	//gasolina
	for (int i = 0; i < 3; i++)
	{
		fuel[i].Movimenta(0, fuel[i].speed);

		if (fuel[i].z > 100) fuel[i].CriaFuel(rand() % 75 - 20, fuel[i].y, -4000);

		//colisao do player com o combustivel
		if (jogador.x - 1.5f < fuel[i].x + 10 && jogador.x + 1.5f > fuel[i].x - 10)
		{
			if (jogador.y - 1.5f < fuel[i].y + 10 && jogador.y + 1.5f > fuel[i].y - 10)
			{
				if (jogador.z - 1.5f < fuel[i].z + 10 && jogador.z + 1.5f > fuel[i].z - 10)
				{
					if (jogador.combustivel + fuel[i].combustivel < 100) jogador.combustivel += fuel[i].combustivel;
					else jogador.combustivel = 100;

					fuel[i].CriaFuel(50000, fuel[i].y, fuel[i].x);
				}
			}
		}
	}
	//bala
	for (int j = 0; j < 10; j++)
	{
		if (bullets[j].usada == true)
		{
			bullets[j].Movimento(0, -bullets[j].speed);

			if (bullets[j].z < -2000)
			{
				bullets[j].CriaBullet(0, jogador.y, 1000);
				bullets[j].usada = false;
			}

			//colisor da bala com o barco
			for (int i = 0; i < 5; i++)
			{
				if (bullets[j].x - 0.5f < barcos[i].x + 10 && bullets[j].x + 0.5f > barcos[i].x - 10)
				{
					if (bullets[j].y - 0.5f < barcos[i].y + 10 && bullets[j].y + 0.5f > barcos[i].y - 10)
					{
						if (bullets[j].z - 0.5f < barcos[i].z + 10 && bullets[j].z + 0.5f > barcos[i].z - 10)
						{
							barcos[i].CriaInimigo(50000, barcos[i].y, barcos[i].z);

							bullets[j].CriaBullet(0, jogador.y, 1000);
							bullets[j].usada = false;

							jogador.acertos++;
						}
					}
				}
			}

			//colisor da bala no coptero
			for (int i = 0; i < 5; i++)
			{
				if (bullets[j].x - 0.5f < helicoptero[i].x + 10 && bullets[j].x + 0.5f > helicoptero[i].x - 10)
				{
					if (bullets[j].y - 0.5f < helicoptero[i].y + 10 && bullets[j].y + 0.5f > helicoptero[i].y - 10)
					{
						if (bullets[j].z - 0.5f < helicoptero[i].z + 10 && bullets[j].z + 0.5f > helicoptero[i].z - 10)
						{
							helicoptero[i].CriaHelecoptero(50000, helicoptero[i].y, helicoptero[i].z);

							bullets[j].CriaBullet(0, jogador.y, 1000);
							bullets[j].usada = false;

							jogador.acertos++;
						}
					}
				}
			}

		}
	}
}

void Scene::Pause()
{
	estadosJogo.pause();
}

void Scene::GameOver()
{
	glColor3f(1.0, 1.0, 1.0);
	estadosJogo.Texto(estadosJogo.novoJogo.data(), estadosJogo.novoJogo.size(), 352, 270);
	estadosJogo.Texto(estadosJogo.sairJogo.data(), estadosJogo.sairJogo.size(), 350, 220);

	if (estadosJogo.getAuxMenu() == 0)
	{
		estadosJogo.Titulo(estadosJogo.setaSelecao.data(), estadosJogo.setaSelecao.size(), 300, 220);
	}
	else
	{
		estadosJogo.Titulo(estadosJogo.setaSelecao.data(), estadosJogo.setaSelecao.size(), 300, 270);
	}

	glColor3f(1.0, 0.0, 0.0);
	estadosJogo.Titulo(estadosJogo._gameOver.data(), estadosJogo._gameOver.size(), 330, 420);
}

void Scene::Help()
{
}

Scene::Scene()
{
}

Scene::~Scene()
{
}
