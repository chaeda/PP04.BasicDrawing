#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
public:
	void Update();
	void velocity(int vel);

private:
	const int turnCycle = 500;

	int dire;
};
