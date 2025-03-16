#include "SpriteRendererComponent.h"

#include "GameObject.h"

#include "TransformComponent.h"

void SpriteRendererComponent::setTexture(sf::Texture& texture)
{
	this->texture = texture;
	sprite.setTexture(texture);
	sprite.setTextureRect({ { 0, 0 }, {static_cast<int>(texture.getSize().x), static_cast<int>(texture.getSize().y)} });
}

void SpriteRendererComponent::setTexture(std::string_view path)
{
	if (!texture.loadFromFile(path.data())) {
		throw std::runtime_error("Failed to load texture");
	}
	sprite.setTexture(texture);
	sprite.setTextureRect({ { 0, 0 }, {static_cast<int>(texture.getSize().x), static_cast<int>(texture.getSize().y)} });
}

void SpriteRendererComponent::draw(sf::RenderWindow& window)
{
	std::shared_ptr<TransformComponent> transformComponent = gameObject.getComponent<TransformComponent>();
	if (transformComponent) {
		sprite.setPosition({ static_cast<float>(transformComponent->position.x + relativePosition.x), static_cast<float>(transformComponent->position.y + relativePosition.y) });
	}
	else {
		throw std::runtime_error("Transform component not found");
	}

	window.draw(sprite);
}
