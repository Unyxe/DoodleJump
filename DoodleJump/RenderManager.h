#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "GameObjectStore.h"

class RenderManager
{
private:
	const unsigned int SCREEN_WIDTH = 600;
	const unsigned int SCREEN_HEIGHT = 800;

	sf::RenderWindow window;

	GameObjectStore gameObjectStore;

	void pollEvent(std::optional<sf::Event> event);
	void renderFrame();

public:
	RenderManager();
	void StartRender();
};

