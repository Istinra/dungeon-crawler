#pragma once

#include "AbstractComponent.h"
#include "../Common/CommonTypes.h"

class RenderableComponent :	public AbstractComponent
{
public:
	RenderableComponent(Entity &parent, Sprite *sprite);
	virtual ~RenderableComponent();

	ComponentType Type()
	{
		return RENDERABLE;
	}

private:
	UniquePtr<Sprite> sprite;
};

