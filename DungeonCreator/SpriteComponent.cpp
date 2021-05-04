#include "SpriteComponent.h"

SpriteComponent::SpriteComponent()
{
	m_x = 60;
	m_y = 60;
	m_width = 60;
	m_height = 60;
	xOffset = 0;
	yOffset = 0;
	timer = 0;
	m_animed = false;
	m_currentTex = 0;
	//m_currentState = NULL;
}

void SpriteComponent::resetSprite()
{
	m_x = 60;
	m_y = 60;
	m_width = 60;
	m_height = 60;
	m_animed = false;
}

void SpriteComponent::setPathAndScreen(std::string path, SDL_Renderer* t_screen, bool t_anime)
{
	bool newString = true;
	m_currentTex = -1;
	int counter = m_currentTex;
	for (auto currentPath : m_paths)
	{
		counter++;
		if (currentPath == path)
		{
			newString = false;
			m_currentTex = counter;
		}
		
	}
	if (newString)
	{
		m_paths.push_back(path);
		counter++;
		m_currentTex = counter;
	}
	m_screen = t_screen;
	m_animed = t_anime;
}

void SpriteComponent::setPosAndSize(int x, int y, int width, int height)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
}




bool SpriteComponent::finishedAnime()
{
	if (timer >= MAX_TIME-1 && xOffset >= 240)
	{
		return true;
	}
	return false;
}


void SpriteComponent::init()
{
}

void SpriteComponent::update()
{
	timer++;
	if (m_animed && timer >= MAX_TIME)
	{
		timer = 0;
		xOffset += 60;
		if (xOffset == 300)
		{
			xOffset = 0;
		}
		switch (m_currentState)
		{
		//Modify Yoffset here
		default:
			break;
		}
	}
}

void SpriteComponent::render()
{
	SDL_Rect dstrect = { m_x, m_y, m_width, m_height };

	SDL_Rect srcrect = { xOffset, yOffset, 60, 60 };

	while (loadedSurface.size() < m_paths.size())
	{
		loadedSurface.push_back(SDL_LoadBMP(m_paths.at(loadedSurface.size()).c_str()));
		m_texture.push_back(SDL_CreateTextureFromSurface(m_screen, loadedSurface.at(m_texture.size())));
	}
	if (loadedSurface.at(m_currentTex)->clip_rect.h - srcrect.h < srcrect.y)
	{
		srcrect.y = 0;
	}
	SDL_RenderCopy(m_screen, m_texture.at(m_currentTex), &srcrect, &dstrect);
}