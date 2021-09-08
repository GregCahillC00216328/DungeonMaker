#pragma once

#include "Component.h"
#include "Vector2.h"
class SelectedComponent : public Component
{
public:
	SelectedComponent();
	~SelectedComponent();
	SelectedComponent(bool t_isSelected);
	void init() override;
	void update() override;
	void render() override;

private:
	bool m_isSelected;
};