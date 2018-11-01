#pragma once
#include "Vector2D.h"
#include "GameObject.h"

Vector2D m_position;
Vector2D m_velocity;
Vector2D m_acceleration;


class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
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
	std::string m_textureID;
};

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams)
{
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();

	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 1;
}

void SDLGameObject::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y,
		m_width, m_height, m_currentRow, m_currentFrame,
		TheGame::Instance()->getRenderer());
}