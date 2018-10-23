#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "TextureManager.h"

class GameObject
{
public:
	void load(int x, int y, int width, int height,
		std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean() { delete this; };
protected:
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};
