#pragma once

#include "AbstractComponent.h"

class PickupComponent :	public AbstractComponent
{
public:
	PickupComponent();
	virtual ~PickupComponent();

	ComponentType Type()
	{
		return PICK_UP;
	}

};

