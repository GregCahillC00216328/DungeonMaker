#include "PositionComponent.h"

PositionComponent::PositionComponent()
{
	
}

PositionComponent::~PositionComponent()
{
}

PositionComponent::PositionComponent(Vector2 position)
{
	m_position = position;
}

void PositionComponent::init()
{

}

void PositionComponent::update()
{

	
}

void PositionComponent::render()
{
}


void PositionComponent::setPosition(Vector2 position)
{
	std::cout << "Test" << std::endl;
	m_position = position;
}

void PositionComponent::setPreviousPosition(Vector2 position)
{
		m_prevPositions.push(position);

}

Vector2 PositionComponent::getPreviousPosition()
{
	if (!m_prevPositions.empty())
	{
		return m_prevPositions.top();
	}
	else
	{
		return m_position;
	}
	
}

void PositionComponent::setToPreviousPos()
{
	if (!m_prevPositions.empty())
	{
		m_position = m_prevPositions.top();
		m_prevPositions.pop();
	}
	
	
}

Vector2 PositionComponent::getPosition()
{
	if (m_position == NULL)
	{
		m_position = Vector2(0, 0);
	}
	return m_position;
}
