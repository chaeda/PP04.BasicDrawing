#include "Game.h"
#include <SDL_image.h>
#include <iostream>
#include <SDL_keycode.h>
#include "Monster.h"




bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height,
			SDL_WINDOW_SHOWN);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;   
		if (!TheTextureManager::Instance()->load("assets/tree.png", "tree", m_pRenderer))
		{
			return false;
		}
		

		F_monster = new Monster();
		S_monster = new Monster();


		F_monster->load(100, 50, 64, 64, "tree");
		S_monster->load(100, 200, 64, 64, "tree");

		

		gameObjects.push_back(F_monster);
		gameObjects.push_back(S_monster);

		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

	}
	else {
		return false;
	}
	return true;

}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); 
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(m_pRenderer);
	}

	SDL_RenderPresent(m_pRenderer); 
}
void Game::update()
{
	//m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	//F_currentFrame = int(((SDL_GetTicks() / 100) % 10));

	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void Game::clean()
{
	//SDL_Delay(6000);
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}