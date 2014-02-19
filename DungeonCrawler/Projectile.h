#ifndef Projectile_h__
#define Projectile_h__

#include "Entity.h"

#define PROJECTILE_MOVE_STEP 1.5f

class Projectile : public Entity 
{
public:
	Projectile(Vector3 position, float yaw, Item sourceItem, Entity* sourceEntity);

	virtual ~Projectile();

	void Update() override;

	void Move(Vector3 movement) override;

	bool IsRemoved() override
	{
		return destroyed;
	}

private:
	static const float projectBoundingWidth;
	Vector3 movementVector;
	bool destroyed;
	Entity* sourceEntity;
	Item sourceItem;
};

#endif // Projectile_h__
