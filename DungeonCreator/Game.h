#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "SpriteComponent.h"
#include "PositionComponent.h"
#include "BodyComponent.h"
#include "EntityManager.h"
#include "AudioComponent.h"
#include "Factory.h"

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void subSystemUpdate();
	void render();
	void clean();

	

	bool running() { return isRunning; }

	SDL_Renderer* m_renderer;
	SDL_Event m_event;
private:
	bool isRunning;
	SDL_Window* m_window;

	bool keyTest = false;
	bool temp = false;
	bool m_gotAchievment = false;

	float m_timer = 0.0f;
	float m_frames = 1.0f / 60.0f;

	Factory* m_factory = new ObjFactory();
	std::vector<MapObj*> m_mapObjVectorArray;

	/// <summary>
	/// Systems
	/// </summary
	std::vector<std::string> answer;

	void initEnts(Entity &t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim);

	void updateEnts(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim);
	
	
	
};
