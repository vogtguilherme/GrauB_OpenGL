#include "Scene.h"

void Scene::Update()
{
	//Controle das variáveis de estado e fluxo do jogo
	if (estadosJogo.getJogo())
	{

	}

	//Condicional para quando o usuario deseja sair do jogo
	if (estadosJogo.getSairJogo())
	{
		exit(0);
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
			if (jogador.x > -39) jogador.Movimenta(-1);
			break;
		case 'd':
			if (jogador.x < 39) jogador.Movimenta(1);
			break;
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

	//Conversão de inteiro para string, pois a OpenGL só escreve string ou char
	sprintf_s(teste, "%d", jogador.vidas);

	//Cor da fonte
	glColor3ub(255, 255, 255);
	//glColor3f(1,1,1);
	//Posição da palavra
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

	//Conversão de inteiro para string, pois a OpenGL só escreve string ou char
	sprintf_s(teste, "%d", jogador.acertos);

	//Cor da fonte
	glColor3ub(255, 255, 255);
	//glColor3f(1,1,1);
	//Posição da palavra
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

	//Conversão de inteiro para string, pois a OpenGL só escreve string ou char
	sprintf_s(teste, "%d", (int)jogador.combustivel);

	//Cor da fonte
	glColor3ub(255, 255, 255);
	//glColor3f(1,1,1);
	//Posição da palavra
	glRasterPos3f(35.0f, 41.0f, -10.0f);

	//Uso do "for" para escrever mais de um caracter
	for (i = 0; i <= strlen(texto); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, texto[i]);

	for (i = 0; i <= strlen(teste); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, teste[i]);
}

void Scene::SetWindowSize(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if (h == 0) h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	fAspect = (GLfloat)w / (GLfloat)h;

	SpecifyViewParameters();
}

void Scene::SpecifyViewParameters()
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
	gluPerspective(angle, fAspect, 0.4, 3000);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo

	// Especifica posição do observador e do alvo
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

		for (int i = 0; i < 5; i++)
		{
			IA[i].DesenhaInimigo();
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
		IA[i].CriaInimigo(rand() % 80 - 40, 5.0f, -1000 * (i + 1));
		IA[i].speed = 1.0f;
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

	for (int i = 0; i < 5; i++)
	{
		if (IA[i].z < 100) IA[i].Movimento(0, IA[i].speed * speed);
		else
		{
			IA[i].CriaInimigo(rand() % 80 - 40, IA[i].y, -4000);
			if (IA[i].speed < 20) IA[i].speed += IA[i].speed * 0.1f;
		}

		if (jogador.x - 1.5f < IA[i].x + 10 && jogador.x + 1.5f > IA[i].x - 10)
		{
			if (jogador.y - 1.5f < IA[i].y + 10 && jogador.y + 1.5f > IA[i].y - 10)
			{
				if (jogador.z - 1.5f < IA[i].z + 10 && jogador.z + 1.5f > IA[i].z - 10)
				{
					IA[i].CriaInimigo(50000, IA[i].y, IA[i].z);

					jogador.vidas--;
				}
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		fuel[i].Movimenta(0, fuel[i].speed);

		if (fuel[i].z > 100) fuel[i].CriaFuel(rand() % 70 - 35, fuel[i].y, -4000);

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

			for (int i = 0; i < 5; i++)
			{
				if (bullets[j].x - 0.5f < IA[i].x + 10 && bullets[j].x + 0.5f > IA[i].x - 10)
				{
					if (bullets[j].y - 0.5f < IA[i].y + 10 && bullets[j].y + 0.5f > IA[i].y - 10)
					{
						if (bullets[j].z - 0.5f < IA[i].z + 10 && bullets[j].z + 0.5f > IA[i].z - 10)
						{
							IA[i].CriaInimigo(50000, IA[i].y, IA[i].z);

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
