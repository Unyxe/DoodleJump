#include "GameObject.h"

std::vector<std::shared_ptr<Component>> GameObject::getComponents()
{
	std::vector<std::shared_ptr<Component>> components;
	for (auto& [type, component] : componentStore)
	{
		components.push_back(component);
	}
	return components;
}
