#pragma once
#include <iostream>
#include "Animation.h"
class State
{
public:
	virtual void idle(Animation* a)
	{
	}

	virtual void moving(Animation* a)
	{
	}
};

class Idle : public State
{
public:
	Idle() {}
	void moving(Animation* a);
};

class Moving : public State
{
public:
	Moving() {}
	void idle(Animation* a);
};
