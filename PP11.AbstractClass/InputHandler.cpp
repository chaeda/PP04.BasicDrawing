#include "InputHandler.h"
#include "Game.h"

InputHandler::InputHandler()
{
	
}

void InputHandler::clean()
{
	
}

void InputHandler::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			TheGame::Instance()->quit();
		}
	}
}