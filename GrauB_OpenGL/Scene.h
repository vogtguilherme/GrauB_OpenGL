#pragma once
class Scene
{
public:

	void Render();
	void Start();
	void Update();
	void GetKeyboardInput();
	void GetMouseInput();

	Scene();
	~Scene();
};

