#include "Game.h"


EntityManager manager;
auto& objectSq(manager.addEntity("square"));

Game::Game()
{


}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{


	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_BORDERLESS;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		m_renderer = SDL_CreateRenderer(m_window, -1, 0);
		if (m_renderer)
		{
			SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
		}

		isRunning = true;
	}

	
	
}

void Game::handleEvents()
{
	
	SDL_PollEvent(&m_event);
	//auto t_objectSq = objectSq;
	switch (m_event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (m_event.key.keysym.sym)
		{
		case SDLK_UP:
			m_mapObjVectorArray.push_back(m_factory->initEntitySq(objectSq, Vector2(200, 200), Vector2(60, 60), "ART/Floor.bmp", false, *m_renderer));
			break;

		case SDLK_DOWN:
		
			break;

		case SDLK_LEFT:
			
			break;

		case SDLK_RIGHT:
		
			break;

		default:
			
			break;
		}
		break;
	case SDL_MOUSEBUTTONDOWN:
		manager.handleEvents();
	default:
		break;
	}

}

void Game::update()
{
	
	manager.update();

}

void Game::subSystemUpdate()
{
	
}

void Game::render()
{
	SDL_RenderClear(m_renderer);
	manager.draw(m_renderer);

	SDL_RenderPresent(m_renderer);
}


void Game::clean()
{
	
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
	isRunning = false;
}




void Game::initEnts(Entity &t_ent,Vector2 t_pos,Vector2 t_size, std::string t_str, bool t_isAnim)
{
	

}

void Game::updateEnts(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim)
{

}
