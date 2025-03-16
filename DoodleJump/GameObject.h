#pragma once
#include "Component.h"

#include <map>
#include <memory>
#include <typeindex>
#include <typeinfo>
#include <random>

class GameObject
{
private:
	std::map<std::type_index, std::shared_ptr<Component>> componentStore;
public:
	std::vector<std::shared_ptr<Component>> getComponents();

	template<typename T>
	std::shared_ptr<T> getComponent() {
		auto componentPair = componentStore.find(typeid(T));
		if (componentPair == componentStore.end()) {
			return nullptr;
		}
		return std::dynamic_pointer_cast<T>(componentPair->second);
	}

	template<typename T>
	void attachComponent() {
		std::shared_ptr<T> component = std::make_shared<T>(*this);
		componentStore[typeid(T)] = std::move(component);
	}

	template<typename T>
	void detachComponent() {
		componentStore.erase(typeid(T));
	}
};

