#pragma once
#include <SDL.h>
#include "TextureManager.h"
#include <SDL_image.h>
#include "Player.h"
#include <vector>
#include "Enemy.h"
#include <map>

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
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	std::vector<GameObject*> m_gameObjects;


	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;



	//int m_currentFrame;

	//TextureManager m_textureManager;

	//SDL_Texture* m_pTexture; // the new SDL_Texture variable
	//SDL_Rect m_sourceRectangle; // ���� �簢�� 
	//SDL_Rect m_destinationRectangle; // ��� �簢�� 

};