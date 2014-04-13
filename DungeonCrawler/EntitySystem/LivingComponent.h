#pragma once

#include "AbstractComponent.h"

class LivingComponent : public AbstractComponent
{
public:
	LivingComponent();
	virtual ~LivingComponent();

	ComponentType Type()
	{
		return LIVING;
	}
private:
	short health;
	short damage;
	float actionTimer;
	float hurtTimer;
};

