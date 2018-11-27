#pragma once
class Scene
{
public:

	void Render();
	void Start();
	void Update();
	void GetKeyboardInput();
	void GetMouseInput();

	void MainMenu();
	void Pause();
	void GameOver();
	void Help();

	Scene();
	~Scene();
};

