#pragma once

#include <vector>

#include "GameObject.h"

class GameObjectStore
{
private:
	std::vector<std::shared_ptr<GameObject>> gameObjects;
public:
	GameObjectStore() = default;
	
	std::vector<std::shared_ptr<GameObject>> getGameObjects();

	void addGameObject(std::shared_ptr<GameObject> gameObject) { gameObjects.push_back(std::move(gameObject)); }
};

