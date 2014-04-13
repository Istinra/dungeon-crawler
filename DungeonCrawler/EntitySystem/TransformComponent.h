#pragma once

#include "AbstractComponent.h"
#include "../Common/CommonTypes.h"

class TransformComponent : public AbstractComponent
{
public:
	TransformComponent(Vector3 pos, float yaw);
	virtual ~TransformComponent();

	ComponentType Type()
	{
		return TRANSFORM;
	}

private:
	Vector3 position;
	float yaw;
};
	
