#include "Monster.h"


void Monster::Update()
{
	/*if (m_x> 640 || m_x< 0)
	{
		dire *= -1;
	}
	m_x += dire;
*/

	//m_currentFrame = int((SDL_GetTicks() / 100) % 4);

	m_x -= 1;
}

void Monster::velocity(int velocity)
{
	this->dire = velocity;
}