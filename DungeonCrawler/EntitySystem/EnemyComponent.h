#pragma once

#include "AbstractComponent.h"

class EnemyComponent : public AbstractComponent
{
public:
	EnemyComponent();
	virtual ~EnemyComponent();

	ComponentType Type()
	{
		return ENEMY;
	}
private:
	bool isBoss;
	int textureId;
	unsigned int colour;
};
