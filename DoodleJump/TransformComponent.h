#pragma once
#include "Component.h"

#include "Vector2.h"

class TransformComponent :
    public Component
{
public:
	explicit TransformComponent(GameObject& parentGameObject) : Component(parentGameObject) {};
	Vector2 position = { 0, 0 };
	float rotation = 0;
	float scale = 1;
};

