#include "EmptyGameObject.h"

EmptyGameObject::EmptyGameObject()
{
	attachComponent<TransformComponent>();
	getComponent<TransformComponent>()->position = { 0, 0 };
}
