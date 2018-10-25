#pragma once
#include "GameObject.h"
using namespace std;

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams*pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

protected:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	string m_textureID;
};


void SDLGameObject::update()
{
	m_x += 1;
}

void SDLGameObject::clean()
{
}

