#pragma once

class Animation
{
	class State* current;
public:
	Animation();
	void setCurrent(State* s)
	{
		current = s;
	}
	State* getCurrent()
	{
		return current;
	}
	void idle();
	void moving();
};
#include "AnimationStates.h"