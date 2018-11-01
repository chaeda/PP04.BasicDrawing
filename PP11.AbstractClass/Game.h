#pragma once
#include "SDL.h"
#include "GameObject.h"
#include <vector>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "TextureManager.h"
class Game
{
private:
	Game() { }
	static Game* s_pInstance;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	std::vector<GameObject*> m_gameObjects;
	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	bool m_bRunning;
	int m_currentFrame;
public:
	~Game() { }
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
};
typedef Game TheGame;