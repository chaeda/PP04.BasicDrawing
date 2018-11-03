#include "Enemy.h"
void Enemy::load(int x, int y, int width, int height,
	std::string textureID)
{
	//	GameObject::load(x, y, width, height, textureID);
	// �� �ڵ尡 �ǹ̰� ������? ���ڵ尡 �����ٸ�, �ڵ����� �θ� ȣ��?? 
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_textureID = textureID;
	m_currentRow = 1;
	m_currentFrame = 1;
}

void Enemy::draw(SDL_Renderer* pRenderer)
{
	//GameObject::draw(pRenderer);
	// �� �ڵ尡 �ǹ̰� ������? ���ڵ尡 �����ٸ�, �ڵ����� �θ� ȣ��?? 
	TheTextureManager::Instance()->drawFrame(m_textureID,
		m_x, m_y, m_width, m_height,
		m_currentRow, m_currentFrame, pRenderer);
}
void Enemy::update()
{
	m_y += 1;
	m_x += 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}