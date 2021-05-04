#include "AnimationStates.h"

void Idle::moving(Animation* a)
{
	a->setCurrent(new Moving());
	delete this;
}

void Moving::idle(Animation* a)
{
	a->setCurrent(new Idle());
	delete this;
}

