#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
	//void load(int x, int y, int width, int height, std::string textureID);
	//void draw(SDL_Renderer* pRenderer);
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	//{ delete this; };
};