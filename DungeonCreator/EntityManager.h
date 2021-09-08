#pragma once
#include "Entity.h"
#include "Vector2.h"
#include "BodyComponent.h"
#include "SpriteComponent.h"
#include "PositionComponent.h"
#include <SDL.h>


class EntityManager
{
private:
	std::vector<std::unique_ptr<Entity>> entities;

	std::string m_direction = "";

	static int  currBiggestStack;
public:
	
	
	void handleEvents(SDL_MouseButtonEvent& t_event);
	void update();
	void draw(SDL_Renderer* t_screen);
	void refresh();
	Entity& addEntity(std::string t_identifier);
	
	
	
	
	
};
