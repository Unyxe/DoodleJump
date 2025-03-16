#pragma once

#include "Component.h"
#include "DrawableComponent.h"

#include "Vector2.h"

class SpriteRendererComponent : public DrawableComponent
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	
	Vector2 relativePosition = { 0, 0 };

public:
	explicit SpriteRendererComponent(GameObject& parentGameObject) : DrawableComponent(parentGameObject), sprite(texture) {}
	void setTexture(sf::Texture& texture);
	void setTexture(std::string_view path);
	void draw(sf::RenderWindow& window) override;
};

