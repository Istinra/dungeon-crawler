#pragma once

#include "AbstractComponent.h"
#include "../Common/CommonTypes.h"

class PhysicsComponent : public AbstractComponent
{
public:
	PhysicsComponent();
	virtual ~PhysicsComponent();

	ComponentType Type()
	{
		return PHYSICS;
	}

	void Move(Vector3 movement);

	virtual void Update(float total, float dt);

private:
	static const float boundingWidth;
	Vector3 position;
	float yaw;
};

