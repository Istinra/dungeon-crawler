#pragma once

#include "ComponentType.h"

class Entity;

class AbstractComponent
{
public:
	AbstractComponent(Entity &parent);
	virtual ~AbstractComponent();

	virtual ComponentType Type() = 0;
	virtual void Update(float total, float dt) = 0;
protected:
	Entity &parent;
};

