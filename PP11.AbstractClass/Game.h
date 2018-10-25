#pragma once
#include <vector>
#include <map>
#include "Player.h"
#include "Enemy.h"


Game* Game::s_pInstance = 0;

class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }





private:
	Game();
	static Game* s_pInstance;
	typedef Game TheGame;



	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	 vector<GameObject*> m_gameObjects;


	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;





	// Game::render 수정 필요 

};