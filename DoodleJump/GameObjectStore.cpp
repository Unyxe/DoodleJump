#include "GameObjectStore.h"

std::vector<std::shared_ptr<GameObject>> GameObjectStore::getGameObjects()
{
	return gameObjects;
}
