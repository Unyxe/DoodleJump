#pragma once

#include <SFML/Graphics.hpp>

class DrawableComponent : public Component
{
public:
	DrawableComponent(GameObject& parentGameObject) : Component(parentGameObject) {}
	virtual void draw(sf::RenderWindow& window) = 0;
};

