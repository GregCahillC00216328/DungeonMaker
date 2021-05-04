#include "EntityManager.h"


void EntityManager::handleEvents()
{
	for (auto& e : entities)
	{
		Entity& tempE = *e.get();
		SDL_MouseButtonEvent t_mouse{};

		if (t_mouse.button == SDL_BUTTON_LEFT)
		{

			int x, y;
			SDL_GetMouseState(&x, &y);
			if ((x > tempE.getComponent<PositionComponent>().getPosition().x && x < tempE.getComponent<PositionComponent>().getPosition().x + 60 &&
				y < tempE.getComponent<PositionComponent>().getPosition().x && y < tempE.getComponent<PositionComponent>().getPosition().y + 60))
			{
				tempE.getComponent<PositionComponent>().setPosition(Vector2(x, y));
			}

		}
	}
}

void EntityManager::update()
{
	for (auto& e : entities)
	{
		e->update();
	}
	
	
}

void EntityManager::draw(SDL_Renderer* t_screen)
{
	for (auto& e : entities)
	{
		e->render(t_screen);

	}
}

void EntityManager::refresh()
{
	entities.erase(std::remove_if(std::begin(entities), std::end(entities),
		[](const std::unique_ptr<Entity>& mEntity)
	{
		return !mEntity->getAlive();
	}), std::end(entities));
}

Entity& EntityManager::addEntity(std::string t_identifier)
{

	Entity* e = new Entity();
	std::unique_ptr<Entity> uPtr{ e };
	entities.emplace_back(std::move(uPtr));
	e->setComponentString(t_identifier);
	return *e;
}

