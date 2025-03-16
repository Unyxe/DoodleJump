#pragma once

class GameObject;

class Component
{
public:
	GameObject& gameObject;

	explicit Component(GameObject& parentGameObject) :gameObject(parentGameObject) {}
	virtual ~Component() = default;
};

