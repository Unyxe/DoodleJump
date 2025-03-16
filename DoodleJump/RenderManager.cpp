#include "RenderManager.h"

#include "DrawableComponent.h"
#include "EmptyGameObject.h"
#include "SpriteRendererComponent.h"

void RenderManager::pollEvent(std::optional<sf::Event> event)
{
	if (!event.has_value())return;
	
	if (event->is<sf::Event::Closed>()) {
		window.close();
	}
}

void RenderManager::renderFrame()
{
	window.clear();

	for (const auto& gameObject : gameObjectStore.getGameObjects()) {
		for (const auto& component : gameObject->getComponents()) {
			auto drawableComponent = std::dynamic_pointer_cast<DrawableComponent>(component);
			if (drawableComponent)
			{
				drawableComponent->draw(window);
			}
		}
	}

	window.display();
}

RenderManager::RenderManager() : window(sf::VideoMode({ SCREEN_WIDTH, SCREEN_HEIGHT }), "Doodle Jump")
{
	std::shared_ptr<EmptyGameObject> gameObject = std::make_shared<EmptyGameObject>();
	gameObject->attachComponent<SpriteRendererComponent>();
	gameObject->getComponent<SpriteRendererComponent>()->setTexture("C:\\Users\\Unyxe\\Pictures\\decoders.png");
	gameObject->getComponent<TransformComponent>()->position = { 100, 100 };
	
	gameObjectStore.addGameObject(gameObject);
}

void RenderManager::StartRender()
{
	while (window.isOpen()) {
		while (const std::optional<sf::Event> event = window.pollEvent()) pollEvent(event);
		renderFrame();
	}
}
